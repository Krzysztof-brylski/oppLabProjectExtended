#pragma once
#include "../cellInterface.h"
#include <cstring>
#include <cstdio>
using namespace std;
class StringCell final: public CellInterface{
public:
    StringCell(const char* textData,int size);

    string serialize();

    CellInterface* deserialize(string serializedCell);

    union CellInterface::cellDataUnion getValue();
    enum CellInterface::type getType();


    CellInterface* operator +(CellInterface* other);

    CellInterface* operator -(CellInterface* other);

    CellInterface* operator *(CellInterface* other);
};

