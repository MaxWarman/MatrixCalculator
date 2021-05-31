#include "ccontroller.h"
#include "cmodel.h"
#include "cmainwindow.h"

#include <QString>

cController::cController(cModel* aModel, cMainWindow* aView)
{
    mView = aView;
    mModel = aModel;
}

cController::~cController()
{
    delete mView;
    delete mModel;
}

void cController::AddMatrices()
{
    mModel->AddMatrices();
}

void cController::SubtractAB()
{
    mModel->SubtractAB();
}

void cController::SubtractBA()
{
    mModel->SubtractAB();
}

void cController::MultiplyAB()
{
    mModel->MultiplyAB();
}

void cController::MultiplyBA()
{
    mModel->MultiplyBA();
}

void cController::CalculateDeterminantA()
{
    mModel->CalculateDeterminantA();
}

void cController::CalculateDeterminantB()
{
    mModel->CalculateDeterminantB();
}

void cController::PowerA()
{
    mModel->PowerA();
}

void cController::PowerB()
{
    mModel->PowerB();
}

void cController::MultiplyAbyScalar()
{
    mModel->MultiplyAbyScalar();
}

void cController::MultiplyBbyScalar()
{
    mModel->MultiplyBbyScalar();
}

void cController::CheckOperations()
{
    mModel->UpdateMatrices();
    mModel->CheckPossibleOperations();
}

void cController::UpdateA()
{
    mModel->UpdateMatrixA();
    mModel->CheckPossibleOperations();
}

void cController::UpdateB()
{
    mModel->UpdateMatrixB();
    mModel->CheckPossibleOperations();
}

void cController::SwapMatrices()
{
    mModel->SwapMatrices();
    mModel->UpdateMatrixA();
    mModel->UpdateMatrixB();
    mModel->CheckPossibleOperations();
}

