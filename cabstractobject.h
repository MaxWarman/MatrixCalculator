#ifndef CABSTRACTOBJECT_H
#define CABSTRACTOBJECT_H

#include <iostream>
#include <string>
#include <vector>

class cAbstractObject
{
    private:

    protected:
        int mColumns;
        int mRows;
        std::vector<std::vector<double>> mValues;

    public:
        cAbstractObject();
        virtual ~cAbstractObject();

        virtual void Info() const = 0;
        virtual std::string ToString() const = 0;
        virtual void Print() const = 0;
};

#endif // CABSTRACTOBJECT_H
