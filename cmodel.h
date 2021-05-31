#ifndef CMODEL_H
#define CMODEL_H

#include "cmatrix.h"
#include "csquarematrix.h"

#include <QString>
#include <string>

class cMainWindow;

class cModel
{
    private:
        // View pointer (MVC structure)
        cMainWindow* mView;

        // Operation possiblity flags
        bool mIsAddPossible;
        bool mIsMulABPossible;
        bool mIsMulBAPossible;
        bool mIsASquare;
        bool mIsBSquare;

        // Matrices modification flags
        bool mAmodified;
        bool mBmodified;

        // Pointers to dynamically allocated matrices
        cMatrix * mMatrixA;
        cMatrix * mMatrixB;

    public:
        // Constructor & Destructor
        cModel(cMainWindow*);
        ~cModel();

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

        // Update Model data methods
        void UpdateMatrixA();
        void UpdateMatrixB();
        void UpdateMatrices();
        void CheckPossibleOperations();

        void SwapMatrices();

        // GUI oriented methods
        void GUI_DisplayResultMatrix(std::string aOperation, const cMatrix & aResult);

        void UpdateGUI();

        void UpdateGUI_MatrixAEnableFields();
        void UpdateGUI_MatrixBEnableFields();
        void UpdateGUI_MatrixADisplay();
        void UpdateGUI_MatrixBDisplay();

        void UpdateGUI_InsertToA();

};

#endif // CMODEL_H
