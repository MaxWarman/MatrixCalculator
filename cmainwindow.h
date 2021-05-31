#ifndef CMAINWINDOW_H
#define CMAINWINDOW_H


#include "ui_cmainwindow.h"

#include <QMainWindow>
#include <iostream>

QT_BEGIN_NAMESPACE
namespace Ui { class cMainWindow; }
QT_END_NAMESPACE
class cController;

class cMainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::cMainWindow * ui;
    QVector<QVector<QPlainTextEdit *>> mTextBoxAVector;
    QVector<QVector<QPlainTextEdit *>> mTextBoxBVector;

    // Controller pointer (MVC structure)
    cController * mController;

private slots:
    void on_btn_fill_A_with_zeros_clicked();

    void on_btn_fill_B_with_zeros_clicked();

    void on_btn_Add_clicked();

    void on_spinBox_A_Rows_valueChanged(int arg1);

    void on_spinBox_A_Columns_valueChanged(int arg1);

    void on_spinBox_B_Rows_valueChanged(int arg1);

    void on_spinBox_B_Columns_valueChanged(int arg1);

    void on_btn_Clear_A_clicked();

    void on_btn_Clear_B_clicked();

    void on_btn_Switch_Sides_clicked();

    void on_btn_Det_A_clicked();

    void on_btn_Subtract_AB_clicked();

    void on_btn_Subtract_BA_clicked();

    void on_btn_Mul_AB_clicked();

    void on_btn_Mul_BA_clicked();

    void on_btn_Det_B_clicked();

    void on_btn_Power_A_clicked();

    void on_btn_Power_B_clicked();

    void on_btn_Mul_By_Scalar_A_clicked();

    void on_btn_Mul_By_Scalar_B_clicked();

public:
    // Constructor / Destructor
    cMainWindow(QWidget *parent = nullptr);
    ~cMainWindow();

    // Private field getters
    Ui::cMainWindow*  getUI();
    QVector<QVector<QPlainTextEdit *>> getTextBoxAVector();
    QVector<QVector<QPlainTextEdit *>> getTextBoxBVector();

    // Controller setter
    void setController(cController* aController);

    // Set two 2d-vectors that contain text boxes (QPlainTextEdit) of input values
    void setTextBoxAVector();
    void setTextBoxBVector();

    // Display Message Boxes
    int DisplayResultMatrix(std::string aOperation, std::string aResultMessage);
    void DisplayResultNumber(std::string aOperation, std::string aResultMessage);
    void DisplayError(std::string aErrorMessage);
};

#endif // CMAINWINDOW_H
