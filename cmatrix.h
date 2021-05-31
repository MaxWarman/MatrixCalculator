#ifndef CMATRIX_H
#define CMATRIX_H

#include "cabstractobject.h"
#include <vector>
#include <string>

class cMatrix: public cAbstractObject
{
    private:

    protected:

    public:
        cMatrix(int aRows, int aColumns);
        cMatrix(int aRows, int aColumns, double aValues[]);
        cMatrix(int aRows, int aColumns, std::vector<std::vector<double>> aValues);
        cMatrix(const cMatrix & aMatrix);

        virtual ~cMatrix();

        int getColumns();
        int getRows();
        std::vector<std::vector<double>> getValuesVector();

        void setValue(int aRow, int aColumn, double aValue);

        void Info() const;
        void Print() const;
        std::string ToString() const;

        cMatrix Clone();

        virtual cMatrix Add(const cMatrix & aM2) const;
        friend  cMatrix operator+(const cMatrix & aM1, const cMatrix & aM2);

        virtual cMatrix Subtract(const cMatrix & aM2) const;
        friend cMatrix operator-(const cMatrix & aM1, const cMatrix & aM2);

        virtual cMatrix MulByMatrix(const cMatrix & aM2) const;
        friend cMatrix operator*(const cMatrix & aM1, const cMatrix & aM2);

        virtual cMatrix MulByScalar(const double & aScalar) const;
        friend cMatrix operator*(const cMatrix & aM1, const double & aScalar);
        friend cMatrix operator*(const double & aScalar, const cMatrix & aM1);

        friend std::ostream & operator<<(std::ostream & aStr, const cMatrix & aMatrix);
        cMatrix & operator=(const cMatrix & aM1);

        virtual cMatrix Transpose();

};

#endif // CMATRIX_H

