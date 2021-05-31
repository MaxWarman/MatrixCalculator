#ifndef CCONTROLLER_H
#define CCONTROLLER_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
class cModel;
class cMainWindow;

class cController
{
private:
    cModel* mModel;
    cMainWindow* mView;

public:
    // Constructor
    cController(cModel* aModel, cMainWindow* aView);
    ~cController();

    // Operations
    void AddMatrices();
    void SubtractAB();
    void SubtractBA();
    void MultiplyAB();
    void MultiplyBA();

    void CalculateDeterminantA();
    void CalculateDeterminantB();
    void PowerA();
    void PowerB();

    void MultiplyAbyScalar();
    void MultiplyBbyScalar();


    // Update data in Model
    void CheckOperations();
    void UpdateA();
    void UpdateB();
    void SwapMatrices();
};

#endif // CCONTROLLER_H
