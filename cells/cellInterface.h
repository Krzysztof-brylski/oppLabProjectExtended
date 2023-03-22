#pragma once
#include <iostream>
#include <string>
#include "../exceptions/MathException.h"

using namespace std;

class CellInterface{
protected:
    enum type { INT=0, FLOAT=1, STRING=2 } valid_type;
    union cellDataUnion
    {
        char* textData;
        int intData;
        double floatData;
    } cellDataUnion;

public:

    virtual string serialize()=0;

    virtual CellInterface* deserialize(string serializedCell)=0;

    virtual  union cellDataUnion getValue()=0;

    virtual  enum type getType()=0;

    //operators
    virtual bool operator< (CellInterface& other)=0;

    virtual bool operator> (CellInterface& other)=0;

    virtual CellInterface& operator +=( CellInterface& other)=0;



    virtual CellInterface& operator /=(CellInterface& other)=0;

};