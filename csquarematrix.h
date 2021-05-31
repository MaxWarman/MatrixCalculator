#ifndef CSQUAREMATRIX_H
#define CSQUAREMATRIX_H

#include "cmatrix.h"

#include <vector>
#include <string>


class cSquareMatrix: public cMatrix
{
    private:

    protected:

    public:
        cSquareMatrix(int aRows, int aColumns);
        cSquareMatrix(int aRows, int aColumns, double aValues[]);
        cSquareMatrix(int aRows, int aColumns, std::vector<std::vector<double>> aValues);
        cSquareMatrix(const cMatrix & aMatrix);
        cSquareMatrix(const cSquareMatrix & aSqMatrix);

        virtual ~cSquareMatrix();

        cSquareMatrix Minor(int aRow, int aColumn) const;
        double Determinant();

        static cSquareMatrix Identity(int aRows);
        cSquareMatrix Power(int aExponent);

        cSquareMatrix Add(const cSquareMatrix & aM2);

        cSquareMatrix Subtract(const cSquareMatrix & aM2);
        cSquareMatrix MulByScalar(const double & aM2);
        cSquareMatrix MulByMatrix(const cSquareMatrix & aM2);
};

#endif // CSQUAREMATRIX_H
