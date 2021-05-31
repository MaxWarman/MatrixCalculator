#include "cmatrix.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

cMatrix::cMatrix(int aRows, int aColumns)//: mRows(aRows), mColumns(aColumns)
{
    mRows = aRows;
    mColumns = aColumns;

    std::vector<double> temp(mColumns, 0);
    for(int i = 0; i < aRows; i++)
    {
        mValues.push_back(temp);
    }
}

cMatrix::cMatrix(int aRows, int aColumns, double aValues[])
{
    mRows = aRows;
    mColumns = aColumns;

    int counter = 0;
    for(int i = 0; i < mRows; i++)
    {
        std::vector<double> temp;
        for(int j = 0; j < mColumns; j++)
        {
            temp.push_back(aValues[counter]);
            counter++;
        }
        mValues.push_back(temp);
    }
}

cMatrix::cMatrix(int aRows, int aColumns, std::vector<std::vector<double>> aValues)
{
    mRows = aRows;
    mColumns = aColumns;
    mValues = aValues;
}

cMatrix::cMatrix(const cMatrix & aMatrix)
{
    mRows = aMatrix.mRows;
    mColumns = aMatrix.mColumns;
    mValues = aMatrix.mValues;
}

cMatrix::~cMatrix()
{
    //std::cout << "\nVector mValues destroyed...\n" << std::endl;
}

int cMatrix::getColumns()
{
    return this->mColumns;
}

int cMatrix::getRows()
{
    return this->mRows;
}

std::vector<std::vector<double>> cMatrix::getValuesVector()
{
    return this->mValues;
}

void cMatrix::setValue(int aRow, int aColumn, double aValue)
{
    mValues.at(aRow).at(aColumn) = aValue;
}

void cMatrix::Info() const
{
    std::cout << "Rows: " << mRows << "\tColumns: " << mColumns << "\tIndices: " << mRows*mColumns << std::endl;
    std::cout << "Values: [";
    for(int i = 0; i < mRows; i++)
    {
        std::cout << "[";
        for(int j = 0; j < mColumns; j++)
        {
            std::cout << mValues.at(i).at(j);
            if(j != mColumns-1)    {std::cout << ", ";}
        }
        std::cout << "]";
        if(i != mRows-1)        {std::cout << ", ";}
    }
    std::cout << "]" << std::endl;
}

void cMatrix::Print() const
{
    std::cout << "cMatrix:" << std::endl;

    for(int i = 0; i < mRows; i++)
    {
        for(int j = 0; j < mColumns; j++)
        {
            std::cout << mValues.at(i).at(j) << "\t";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

std::string cMatrix::ToString() const
{
    std::stringstream ss;
    for(int i = 0; i < mRows; i++)
    {
        for(int j = 0; j < mColumns; j++)
        {
            ss << (double)mValues.at(i).at(j) << "\t";
        }
        ss << "\n";
    }
    ss << "\n";
    return ss.str();
}

cMatrix cMatrix::Clone()
{
    return cMatrix(*this);
}

cMatrix cMatrix::Add(const cMatrix & aM2) const
{
    // pierwsza implementacja obslugi wyjatkow
    if(mRows != aM2.mRows || mColumns != aM2.mColumns)
    {
        throw std::invalid_argument("Matrices have to be the same size!");
    }

    double result_values[mRows * mColumns];
    int counter = 0;
    for(int i = 0; i < mRows; i++)
    {
        for(int j = 0; j < mColumns; j++)
        {
            result_values[counter] = mValues.at(i).at(j) + aM2.mValues.at(i).at(j);
            counter++;
        }
    }

    cMatrix result(mRows, mColumns, result_values);
    return result;
}

cMatrix operator+(const cMatrix & aM1, const cMatrix & aM2)
{
    return aM1.Add(aM2);
}

cMatrix cMatrix::Subtract(const cMatrix & aM2) const
{
    // pierwsza implementacja obslugi wyjatków
    if(mRows != aM2.mRows || mColumns != aM2.mColumns)
    {
        throw std::invalid_argument("Matrices have to be the same size!");
    }

    double result_values[mRows * mColumns];
    int counter = 0;
    for(int i = 0; i < mRows; i++)
    {
        for(int j = 0; j < mColumns; j++)
        {
            result_values[counter] = mValues.at(i).at(j) - aM2.mValues.at(i).at(j);
            counter++;
        }
    }

    cMatrix result(mRows, mColumns, result_values);
    return result;
}

cMatrix operator-(const cMatrix & aM1, const cMatrix & aM2)
{
    return aM1.Subtract(aM2);
}

cMatrix cMatrix::MulByMatrix(const cMatrix & aM2) const
{
    // pierwsza implementacja obslugi wyjatków
    if(mColumns != aM2.mRows)
    {
        throw std::invalid_argument("Invalid matrices. Columns of left != Rows of right.");
    }

    double result_values[mRows * aM2.mColumns];
    for(int i = 0; i < mRows * aM2.mColumns; i++)
    {
        result_values[i] = 0;
    }

    int counter = 0;

    for(int i = 0; i < mRows; i++)
    {
        for(int j = 0; j < aM2.mColumns; j++)
        {
            for(int k = 0; k < mColumns; k++)
            {
                result_values[counter] += mValues.at(i).at(k) * aM2.mValues.at(k).at(j);
            }
            counter++;
        }
    }

    cMatrix result(mRows, aM2.mColumns, result_values);
    return result;
}

cMatrix operator*(const cMatrix & aM1, const cMatrix & aM2)
{
    return aM1.MulByMatrix(aM2);
}

cMatrix cMatrix::MulByScalar(const double & aScalar) const
{
    cMatrix result(mRows, mColumns);

    for(int i = 0; i < mRows; i++)
    {
        for(int j = 0; j < mColumns; j++)
        {
            result.mValues.at(i).at(j) = mValues.at(i).at(j) * aScalar;
        }
    }

    return result;
}

cMatrix operator*(const cMatrix & aM1, const double & aScalar)
{
    return aM1.MulByScalar(aScalar);
}

cMatrix operator*(const double & aScalar, const cMatrix & aM1)
{
    return aM1.MulByScalar(aScalar);
}

std::ostream & operator<<(std::ostream & aStr, const cMatrix & aMatrix)
{
    aStr << aMatrix.ToString();
    return aStr;
}

cMatrix & cMatrix::operator=(const cMatrix & aM1)
{
    mRows = aM1.mRows;
    mColumns = aM1.mColumns;
    mValues = aM1.mValues;

    return *this;
}

cMatrix cMatrix::Transpose()
{
    cMatrix result(mColumns, mRows);

    for(int i = 0; i < mRows; i++)
    {
        for(int j = 0; j < mColumns; j++)
        {
            result.mValues.at(j).at(i) = mValues.at(i).at(j);
        }
    }

    return result;
}
