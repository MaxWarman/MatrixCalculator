#include "cmainwindow.h"
#include "ui_cmainwindow.h"
#include "ccontroller.h"

#include <iostream>
#include <QMessageBox>

cMainWindow::cMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::cMainWindow)
{
    ui->setupUi(this);

    mController = nullptr;

    setTextBoxAVector();
    setTextBoxBVector();
}

cMainWindow::~cMainWindow()
{
    delete ui;
}

Ui::cMainWindow* cMainWindow::getUI(){
    return(ui);
}

QVector<QVector<QPlainTextEdit *>> cMainWindow::getTextBoxAVector()
{
    return mTextBoxAVector;
}

QVector<QVector<QPlainTextEdit *>> cMainWindow::getTextBoxBVector()
{
    return mTextBoxBVector;
}

void cMainWindow::setController(cController* aController)
{
    mController = aController;
}

void cMainWindow::setTextBoxAVector()
{
    QVector<QPlainTextEdit *> tmp;

        tmp.push_back(ui->plainTextEdit_A_1_1);
        tmp.push_back(ui->plainTextEdit_A_1_2);
        tmp.push_back(ui->plainTextEdit_A_1_3);
        tmp.push_back(ui->plainTextEdit_A_1_4);
        tmp.push_back(ui->plainTextEdit_A_1_5);

        mTextBoxAVector.push_back(tmp);
        tmp.erase(tmp.begin(), tmp.end());

        tmp.push_back(ui->plainTextEdit_A_2_1);
        tmp.push_back(ui->plainTextEdit_A_2_2);
        tmp.push_back(ui->plainTextEdit_A_2_3);
        tmp.push_back(ui->plainTextEdit_A_2_4);
        tmp.push_back(ui->plainTextEdit_A_2_5);

        mTextBoxAVector.push_back(tmp);
        tmp.erase(tmp.begin(), tmp.end());

        tmp.push_back(ui->plainTextEdit_A_3_1);
        tmp.push_back(ui->plainTextEdit_A_3_2);
        tmp.push_back(ui->plainTextEdit_A_3_3);
        tmp.push_back(ui->plainTextEdit_A_3_4);
        tmp.push_back(ui->plainTextEdit_A_3_5);

        mTextBoxAVector.push_back(tmp);
        tmp.erase(tmp.begin(), tmp.end());

        tmp.push_back(ui->plainTextEdit_A_4_1);
        tmp.push_back(ui->plainTextEdit_A_4_2);
        tmp.push_back(ui->plainTextEdit_A_4_3);
        tmp.push_back(ui->plainTextEdit_A_4_4);
        tmp.push_back(ui->plainTextEdit_A_4_5);

        mTextBoxAVector.push_back(tmp);
        tmp.erase(tmp.begin(), tmp.end());

        tmp.push_back(ui->plainTextEdit_A_5_1);
        tmp.push_back(ui->plainTextEdit_A_5_2);
        tmp.push_back(ui->plainTextEdit_A_5_3);
        tmp.push_back(ui->plainTextEdit_A_5_4);
        tmp.push_back(ui->plainTextEdit_A_5_5);

        mTextBoxAVector.push_back(tmp);
        tmp.erase(tmp.begin(), tmp.end());
}

void cMainWindow::setTextBoxBVector()
{
    QVector<QPlainTextEdit *> tmp;

        tmp.push_back(ui->plainTextEdit_B_1_1);
        tmp.push_back(ui->plainTextEdit_B_1_2);
        tmp.push_back(ui->plainTextEdit_B_1_3);
        tmp.push_back(ui->plainTextEdit_B_1_4);
        tmp.push_back(ui->plainTextEdit_B_1_5);

        mTextBoxBVector.push_back(tmp);
        tmp.erase(tmp.begin(), tmp.end());

        tmp.push_back(ui->plainTextEdit_B_2_1);
        tmp.push_back(ui->plainTextEdit_B_2_2);
        tmp.push_back(ui->plainTextEdit_B_2_3);
        tmp.push_back(ui->plainTextEdit_B_2_4);
        tmp.push_back(ui->plainTextEdit_B_2_5);

        mTextBoxBVector.push_back(tmp);
        tmp.erase(tmp.begin(), tmp.end());

        tmp.push_back(ui->plainTextEdit_B_3_1);
        tmp.push_back(ui->plainTextEdit_B_3_2);
        tmp.push_back(ui->plainTextEdit_B_3_3);
        tmp.push_back(ui->plainTextEdit_B_3_4);
        tmp.push_back(ui->plainTextEdit_B_3_5);

        mTextBoxBVector.push_back(tmp);
        tmp.erase(tmp.begin(), tmp.end());

        tmp.push_back(ui->plainTextEdit_B_4_1);
        tmp.push_back(ui->plainTextEdit_B_4_2);
        tmp.push_back(ui->plainTextEdit_B_4_3);
        tmp.push_back(ui->plainTextEdit_B_4_4);
        tmp.push_back(ui->plainTextEdit_B_4_5);

        mTextBoxBVector.push_back(tmp);
        tmp.erase(tmp.begin(), tmp.end());

        tmp.push_back(ui->plainTextEdit_B_5_1);
        tmp.push_back(ui->plainTextEdit_B_5_2);
        tmp.push_back(ui->plainTextEdit_B_5_3);
        tmp.push_back(ui->plainTextEdit_B_5_4);
        tmp.push_back(ui->plainTextEdit_B_5_5);

        mTextBoxBVector.push_back(tmp);
        tmp.erase(tmp.begin(), tmp.end());
}

int cMainWindow::DisplayResultMatrix(std::string aOperation, std::string aResultMessage)
{
      QMessageBox msgBox;
      msgBox.setWindowTitle(QString::fromStdString(aOperation));
      msgBox.setText(QString::fromStdString(aResultMessage));

      msgBox.addButton(tr("Cancel"), QMessageBox::NoRole);
      QAbstractButton* btnInsertToA = msgBox.addButton(tr("Insert to A"), QMessageBox::ActionRole);
      QAbstractButton* btnInsertToB = msgBox.addButton(tr("Insert to B"), QMessageBox::ActionRole);

      msgBox.exec();

      if (msgBox.clickedButton()==btnInsertToA) {

         return 1;
      }
      else if (msgBox.clickedButton()==btnInsertToB) {

         return 2;
      }

      return 0;
}

void cMainWindow::DisplayResultNumber(std::string aOperation, std::string aResultMessage)
{
    QMessageBox msgBox;
    msgBox.setWindowTitle(QString::fromStdString(aOperation));
    msgBox.setText(QString::fromStdString(aResultMessage));

    msgBox.exec();
}

void cMainWindow::DisplayError(std::string aErrorMessage)
{
    QMessageBox mb;
    mb.setWindowTitle("Error!");

    QString resultTextQString = QString::fromStdString(aErrorMessage);
    mb.setText(resultTextQString);
    mb.exec();
}


// private SLOTS (on button click...)


void cMainWindow::on_btn_fill_A_with_zeros_clicked()
{
    for(int i = 0; i < ui->spinBox_A_Rows->value(); ++i)
    {
        for(int j = 0; j < ui->spinBox_A_Columns->value(); ++j)
        {
            if(mTextBoxAVector.at(i).at(j)->toPlainText() == "")
            {
                mTextBoxAVector.at(i).at(j)->setPlainText("0");
            }
        }
    }
}

void cMainWindow::on_btn_fill_B_with_zeros_clicked()
{
    for(int i = 0; i < ui->spinBox_B_Rows->value(); ++i)
    {
        for(int j = 0; j < ui->spinBox_B_Columns->value(); ++j)
        {
            if(mTextBoxBVector.at(i).at(j)->toPlainText() == "")
            {
                mTextBoxBVector.at(i).at(j)->setPlainText("0");
            }
        }
    }
}

void cMainWindow::on_spinBox_A_Rows_valueChanged(int arg1)
{
    mController->UpdateA();
}

void cMainWindow::on_spinBox_A_Columns_valueChanged(int arg1)
{
    mController->UpdateA();
}

void cMainWindow::on_spinBox_B_Rows_valueChanged(int arg1)
{
    mController->UpdateB();
}

void cMainWindow::on_spinBox_B_Columns_valueChanged(int arg1)
{
    mController->UpdateB();
}

void cMainWindow::on_btn_Clear_A_clicked()
{
    for(int i = 0; i < ui->spinBox_A_Rows->value(); ++i)
    {
        for(int j = 0; j < ui->spinBox_A_Columns->value(); j++)
        {
            mTextBoxAVector.at(i).at(j)->setPlainText("");
        }
    }
}

void cMainWindow::on_btn_Clear_B_clicked()
{
    for(int i = 0; i < ui->spinBox_B_Rows->value(); ++i)
    {
        for(int j = 0; j < ui->spinBox_B_Columns->value(); ++j)
        {
            mTextBoxBVector.at(i).at(j)->setPlainText("");
        }
    }
}

void cMainWindow::on_btn_Switch_Sides_clicked()
{
    mController->SwapMatrices();
}

void cMainWindow::on_btn_Add_clicked()
{
    mController->AddMatrices();
}

void cMainWindow::on_btn_Subtract_AB_clicked()
{
    mController->SubtractAB();
}

void cMainWindow::on_btn_Subtract_BA_clicked()
{
    mController->SubtractBA();
}

void cMainWindow::on_btn_Mul_AB_clicked()
{
    mController->MultiplyAB();
}

void cMainWindow::on_btn_Mul_BA_clicked()
{
    mController->MultiplyBA();
}

void cMainWindow::on_btn_Det_A_clicked()
{
    mController->CalculateDeterminantA();
}

void cMainWindow::on_btn_Det_B_clicked()
{
    mController->CalculateDeterminantB();
}

void cMainWindow::on_btn_Power_A_clicked()
{
    mController->PowerA();
}

void cMainWindow::on_btn_Power_B_clicked()
{
    mController->PowerB();
}

void cMainWindow::on_btn_Mul_By_Scalar_A_clicked()
{
    mController->MultiplyAbyScalar();
}

void cMainWindow::on_btn_Mul_By_Scalar_B_clicked()
{
    mController->MultiplyBbyScalar();
}
