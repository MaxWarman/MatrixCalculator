#include "cmodel.h"
#include "cmainwindow.h"

#include <string>

#include "cmatrix.h"
#include "csquarematrix.h"

cModel::cModel(cMainWindow* aView)
{
    mView = aView;

    // do zaimplementowania
    mIsAddPossible = false;
    mIsMulABPossible = false;
    mIsMulBAPossible = false;
    mIsASquare = false;
    mIsBSquare = false;

    mMatrixA = new cMatrix(mView->getUI()->spinBox_A_Rows->value(), mView->getUI()->spinBox_A_Columns->value());
    mMatrixB = new cMatrix(mView->getUI()->spinBox_B_Rows->value(), mView->getUI()->spinBox_B_Columns->value());

    mAmodified = true;
    mBmodified = true;
}

cModel::~cModel()
{
    delete mMatrixA;
    delete mMatrixB;
}

void cModel::AddMatrices()
{
    UpdateMatrices();

    cMatrix resultMatrix = *mMatrixA + *mMatrixB;

    GUI_DisplayResultMatrix("A + B", resultMatrix);
}

void cModel::SubtractAB()
{
    UpdateMatrices();

    cMatrix resultMatrix = *mMatrixA - *mMatrixB;

    GUI_DisplayResultMatrix("A - B", resultMatrix);
}

void cModel::SubtractBA()
{
    UpdateMatrices();

    cMatrix resultMatrix = *mMatrixB - *mMatrixA;

    GUI_DisplayResultMatrix("B - A", resultMatrix);
}

void cModel::MultiplyAB()
{
    UpdateMatrices();

    cMatrix resultMatrix = *mMatrixA * *mMatrixB;

    GUI_DisplayResultMatrix("A * B", resultMatrix);
}

void cModel::MultiplyBA()
{
    UpdateMatrices();

    cMatrix resultMatrix = *mMatrixB * *mMatrixA;

    GUI_DisplayResultMatrix("B * A", resultMatrix);
}

void cModel::CalculateDeterminantA()
{
    UpdateMatrixA();

    cSquareMatrix tmp = *mMatrixA;
    double det = tmp.Determinant();

    std::string resultText = std::to_string(det);

    mView->DisplayResultNumber("Det(A)", resultText);
}

void cModel::CalculateDeterminantB()
{
    UpdateMatrixB();

    cSquareMatrix tmp = *mMatrixB;
    double det = tmp.Determinant();

    std::string resultText = std::to_string(det);

    mView->DisplayResultNumber("Det(B)", resultText);
}

void cModel::PowerA()
{
    UpdateMatrices();
    int exponent = mView->getUI()->spinBox_Power_A->value();

    cSquareMatrix copy = *mMatrixA;

    cSquareMatrix resultMatrix = copy.Power(exponent);

    GUI_DisplayResultMatrix("A ^ n", resultMatrix);
}

void cModel::PowerB()
{
    UpdateMatrices();
    int exponent = mView->getUI()->spinBox_Power_B->value();

    cSquareMatrix copy = *mMatrixB;

    cSquareMatrix resultMatrix = copy.Power(exponent);

    GUI_DisplayResultMatrix("B ^ n", resultMatrix);
}

void cModel::MultiplyAbyScalar()
{
    UpdateMatrices();
    double scalar = mView->getUI()->spinBox_Mul_By_Scalar_A->value();

    cMatrix resultMatrix = *mMatrixA * scalar;

    GUI_DisplayResultMatrix("A * m", resultMatrix);
}

void cModel::MultiplyBbyScalar()
{
    UpdateMatrices();
    double scalar = mView->getUI()->spinBox_Mul_By_Scalar_B->value();

    cMatrix resultMatrix = *mMatrixB * scalar;

    GUI_DisplayResultMatrix("B * m", resultMatrix);
}

void cModel::UpdateMatrixA()
{
    mAmodified = true;

    int newRows = mView->getUI()->spinBox_A_Rows->value();
    int newColumns = mView->getUI()->spinBox_A_Columns->value();

    if(newRows == newColumns)
    {
        delete mMatrixA;
        mMatrixA = new cSquareMatrix(newRows, newColumns);
    }
    else
    {
        delete mMatrixA;
        mMatrixA = new cMatrix(newRows, newColumns);
    }

    for(int i = 0; i < mMatrixA->getRows(); ++i)
    {
        for(int j = 0; j < mMatrixA->getColumns(); ++j)
        {
            double value = mView->getTextBoxAVector().at(i).at(j)->toPlainText().toDouble();
            mMatrixA->setValue(i, j, value);
        }
    }

    //
    mView->getUI()->label_test1->setText(QString::fromStdString(mMatrixA->ToString()));
    //

}

void cModel::UpdateMatrixB()
{
    mBmodified = true;

    int newRows = mView->getUI()->spinBox_B_Rows->value();
    int newColumns = mView->getUI()->spinBox_B_Columns->value();

    if(newRows == newColumns)
    {
        delete mMatrixB;
        mMatrixB = new cSquareMatrix(newRows, newColumns);
    }
    else
    {
        delete mMatrixB;
        mMatrixB = new cMatrix(newRows, newColumns);
    }

    for(int i = 0; i < mMatrixB->getRows(); ++i)
    {
        for(int j = 0; j < mMatrixB->getColumns(); ++j)
        {
            double value = mView->getTextBoxBVector().at(i).at(j)->toPlainText().toDouble();
            mMatrixB->setValue(i, j, value);
        }
    }

    //
    mView->getUI()->label_test2->setText(QString::fromStdString(mMatrixB->ToString()));
    //

}

void cModel::UpdateMatrices()
{
    UpdateMatrixA();
    UpdateMatrixB();
}

void cModel::CheckPossibleOperations()
{
    // Is A + B, A - B, B - A possible?
    if(mMatrixA->getRows() == mMatrixB->getRows() && mMatrixA->getColumns() == mMatrixB->getColumns())  { mIsAddPossible = true; }
    else                                                                                                { mIsAddPossible = false; }

    // Is A * B possible?
    if(mMatrixA->getColumns() == mMatrixB->getRows())                                                   { mIsMulABPossible = true; }
    else                                                                                                { mIsMulABPossible = false; }

    // Is B * A possible?
    if(mMatrixB->getColumns() == mMatrixA->getRows())                                                   { mIsMulBAPossible = true; }
    else                                                                                                { mIsMulBAPossible = false; }

    // Is Det(A) or A^n possible?
    if(mMatrixA->getRows() == mMatrixA->getColumns())                                                   { mIsASquare = true; }
    else                                                                                                { mIsASquare = false; }

    // Is Det(B) or B^n possible?
    if(mMatrixB->getRows() == mMatrixB->getColumns())                                                   { mIsBSquare = true; }
    else                                                                                                { mIsBSquare = false; }

    UpdateGUI();
}

void cModel::SwapMatrices()
{
    for(int i = 0; i < mView->getTextBoxAVector().size(); ++i)
    {
        for(int j = 0; j < mView->getTextBoxAVector().at(0).size(); ++j)
        {
            QString tmp = mView->getTextBoxAVector().at(i).at(j)->toPlainText();
            mView->getTextBoxAVector().at(i).at(j)->setPlainText(   mView->getTextBoxBVector().at(i).at(j)->toPlainText()   );
            mView->getTextBoxBVector().at(i).at(j)->setPlainText(tmp);
        }
    }

    int tmpRows = mView->getUI()->spinBox_A_Rows->value();
    mView->getUI()->spinBox_A_Rows->setValue(mView->getUI()->spinBox_B_Rows->value());
    mView->getUI()->spinBox_B_Rows->setValue(tmpRows);

    int tmpColumns = mView->getUI()->spinBox_A_Columns->value();
    mView->getUI()->spinBox_A_Columns->setValue(mView->getUI()->spinBox_B_Columns->value());
    mView->getUI()->spinBox_B_Columns->setValue(tmpColumns);
}

void cModel::GUI_DisplayResultMatrix(std::string aOperation, const cMatrix & aResult)
{
    std::string resultMessage = aResult.ToString();
    int tmp = mView->DisplayResultMatrix(aOperation, resultMessage);

    if (tmp == 1)
    {
        delete mMatrixA;
        mMatrixA = new cMatrix(aResult);
    }
    else if (tmp == 2)
    {
        delete mMatrixB;
        mMatrixB = new cMatrix(aResult);
    }

    UpdateGUI();

    UpdateMatrices();
}

void cModel::UpdateGUI()
{
    // Enable/disable buttons A + B, A - B, B - A
    mView->getUI()->btn_Add->setEnabled(mIsAddPossible);
    mView->getUI()->btn_Subtract_AB->setEnabled(mIsAddPossible);
    mView->getUI()->btn_Subtract_BA->setEnabled(mIsAddPossible);

    // Enable/disable button A * B
    mView->getUI()->btn_Mul_AB->setEnabled(mIsMulABPossible);

    // Enable/disable button B * A
    mView->getUI()->btn_Mul_BA->setEnabled(mIsMulBAPossible);

    // Enable/disable buttons A^n, Det(A)
    mView->getUI()->btn_Power_A->setEnabled(mIsASquare);
    mView->getUI()->btn_Det_A->setEnabled(mIsASquare);

    // Enable/disable buttons B^n, Det(B)
    mView->getUI()->btn_Power_B->setEnabled(mIsBSquare);
    mView->getUI()->btn_Det_B->setEnabled(mIsBSquare);


    // Matrix A

    if(mAmodified)
    {
        UpdateGUI_MatrixAEnableFields();
        UpdateGUI_MatrixADisplay();
        mAmodified = false;
    }

    // Matrix B

    if(mBmodified)
    {
        UpdateGUI_MatrixBEnableFields();
        UpdateGUI_MatrixBDisplay();
        mBmodified = false;
    }

    //
    mView->getUI()->label_test1->setText(QString::fromStdString(mMatrixA->ToString()));
    mView->getUI()->label_test2->setText(QString::fromStdString(mMatrixB->ToString()));
    //
}

void cModel::UpdateGUI_MatrixAEnableFields()
{
    for(int i = 0; i < mView->getTextBoxAVector().size(); ++i)
    {
        for(int j = 0; j <  mView->getTextBoxAVector().at(i).size(); ++j)
        {
            if( i < mMatrixA->getRows() && j < mMatrixA->getColumns() )
            {
                mView->getTextBoxAVector().at(i).at(j)->setEnabled(true);
            }
            else
            {
                mView->getTextBoxAVector().at(i).at(j)->setEnabled(false);
                if(mView->getTextBoxAVector().at(i).at(j)->toPlainText().toDouble() == 0)
                {
                    mView->getTextBoxAVector().at(i).at(j)->setPlainText("");
                }
            }
        }
    }
}

void cModel::UpdateGUI_MatrixBEnableFields()
{
    for(int i = 0; i < mView->getTextBoxBVector().size(); ++i)
    {
        for(int j = 0; j < mView->getTextBoxBVector().at(i).size(); ++j)
        {
            if( i < mMatrixB->getRows() && j < mMatrixB->getColumns() )
            {
                mView->getTextBoxBVector().at(i).at(j)->setEnabled(true);
            }
            else
            {
                mView->getTextBoxBVector().at(i).at(j)->setEnabled(false);
                if(mView->getTextBoxBVector().at(i).at(j)->toPlainText().toDouble() == 0)
                {
                    mView->getTextBoxBVector().at(i).at(j)->setPlainText("");
                }
            }
        }
    }
}

void cModel::UpdateGUI_MatrixADisplay()
{
    for(int i = 0; i < mMatrixA->getRows(); ++i)
    {
        for(int j = 0; j < mMatrixA->getColumns(); ++j)
        {
            mView->getTextBoxAVector().at(i).at(j)->setPlainText(QString::number(mMatrixA->getValuesVector().at(i).at(j)));
            if(mView->getTextBoxAVector().at(i).at(j)->toPlainText().toDouble() == 0)
            {
                mView->getTextBoxAVector().at(i).at(j)->setPlainText("");
            }
        }
    }
}

void cModel::UpdateGUI_MatrixBDisplay()
{
    for(int i = 0; i < mMatrixB->getRows(); ++i)
    {
        for(int j = 0; j < mMatrixB->getColumns(); ++j)
        {
            mView->getTextBoxBVector().at(i).at(j)->setPlainText(QString::number(mMatrixB->getValuesVector().at(i).at(j)));
            if(mView->getTextBoxBVector().at(i).at(j)->toPlainText().toDouble() == 0)
            {
                mView->getTextBoxBVector().at(i).at(j)->setPlainText("");
            }
        }
    }
}

void cModel::UpdateGUI_InsertToA()
{
    mView->getUI()->spinBox_A_Rows->setValue(mMatrixA->getRows());
    mView->getUI()->spinBox_A_Columns->setValue(mMatrixA->getColumns());

    for(int i = 0; i < mMatrixA->getRows(); ++i)
    {
        for(int j = 0; j < mMatrixB->getColumns(); ++j)
        {
            mView->getTextBoxAVector().at(i).at(j)->setPlainText(QString::number(mMatrixA->getValuesVector().at(i).at(j)));
        }
    }
}
