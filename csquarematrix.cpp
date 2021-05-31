#include <iostream>
#include <vector>

//#include <string>
//#include <sstream>
//#include <stdexcept>

#include "cmatrix.h"
#include "csquarematrix.h"

cSquareMatrix::cSquareMatrix(int aRows, int aColumns, double aValues[]): cMatrix(aRows, aColumns, aValues)
{

}

cSquareMatrix::cSquareMatrix(int aRows, int aColumns, std::vector<std::vector<double>> aValues): cMatrix(aRows, aColumns, aValues)
{

}

cSquareMatrix::cSquareMatrix(int aRows, int aColumns): cMatrix(aRows, aColumns)
{

}

cSquareMatrix::cSquareMatrix(const cMatrix & aMatrix): cMatrix(aMatrix)
{

}

cSquareMatrix::cSquareMatrix(const cSquareMatrix & aSqMatrix): cMatrix(aSqMatrix)
{

}

cSquareMatrix::~cSquareMatrix()
{

}

cSquareMatrix cSquareMatrix::Minor(int aRow, int aColumn) const
{
    double minor[(mRows - 1) * (mColumns - 1)];
    int counter = 0;

    for(int i = 0; i < mRows; i++)
    {
        for(int j = 0; j < mColumns; j++)
        {
            if(i != aRow && j != aColumn)
            {
                minor[counter] = mValues.at(i).at(j);
                counter++;
            }
        }
    }

    return cSquareMatrix(mRows-1, mColumns-1, minor);
}

double cSquareMatrix::Determinant()
{
    double det = 0;

    cSquareMatrix matrix = *this;

    if(mRows == 1)
    {
        return matrix.mValues.at(0).at(0);
    }


    double sign = 1;

    for(int i = 0; i < matrix.mRows; i++)
    {
        cSquareMatrix tmp = matrix.Minor(0,i);
        det += sign * matrix.mValues.at(0).at(i) * tmp.Determinant();
        sign *= -1;
    }

    return det;
}

cSquareMatrix cSquareMatrix::Identity(int aRows)
{
    cSquareMatrix I(aRows, aRows);

    for(int i = 0; i < I.mRows; i++)
    {
        for(int j = 0; j < I.mColumns; j++)
        {
            if(i == j)
            {
                I.mValues.at(i).at(j) = 1;
            }
        }
    }

    return I;
}

cSquareMatrix cSquareMatrix::Power(int aExponent)
{
    if (aExponent == 0) {return cSquareMatrix::Identity(mRows);}


    cSquareMatrix tmp = *this;
    for(int i = 0; i < aExponent-1; i++)
    {
        tmp = tmp.MulByMatrix(*this);
    }

    return tmp;
}

cSquareMatrix cSquareMatrix::Add(const cSquareMatrix & aM2)
{
    return cSquareMatrix(*this + aM2);
}

cSquareMatrix cSquareMatrix::Subtract(const cSquareMatrix & aM2)
{
    return cSquareMatrix(*this - aM2);
}

cSquareMatrix cSquareMatrix::MulByMatrix(const cSquareMatrix & aM2)
{
    return cSquareMatrix(*this * aM2);
}

cSquareMatrix cSquareMatrix::MulByScalar(const double & aScalar)
{
    return cSquareMatrix(*this * aScalar);
}
