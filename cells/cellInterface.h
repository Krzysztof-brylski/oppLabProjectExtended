#pragma once
#include <iostream>
#include <string>


using namespace std;

class CellInterface{
protected:
    enum type { INT, FLOAT, STRING } valid_type;
    union cellDataUnion
    {
        char* textData;
        int intData;
        double floatData;
    } cellDataUnion;

public:

    virtual string serialize()=0;

    virtual CellInterface* deserialize(string serializedCell)=0;

    virtual union cellDataUnion getValue()=0;

    virtual enum type getType()=0;

    //operators
    virtual CellInterface* operator +(CellInterface* other)=0;

    virtual CellInterface* operator -(CellInterface* other)=0;

    virtual CellInterface* operator *(CellInterface* other)=0;

};