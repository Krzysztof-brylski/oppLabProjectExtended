#pragma once
#include "../cellInterface.h"
#include <iostream>
#include <string>



using namespace std;

class FloatCell final: public CellInterface{

public:
    FloatCell(double floatCell);

    string serialize();


    CellInterface* deserialize(string serializedCell);

    union CellInterface::cellDataUnion getValue();
    enum CellInterface::type getType();


    CellInterface* operator +(CellInterface* other);

    CellInterface* operator -(CellInterface* other);

    CellInterface* operator *(CellInterface* other);
};


