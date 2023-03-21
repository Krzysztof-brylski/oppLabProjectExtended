#pragma once
#include "../cellInterface.h"

class StringCell final: public CellInterface{
public:
    StringCell(char* textData);

    string serialize();

    CellInterface* deserialize(string serializedCell);

    union CellInterface::cellDataUnion getValue();
    enum CellInterface::type getType();


    CellInterface* operator +(CellInterface* other);

    CellInterface* operator -(CellInterface* other);

    CellInterface* operator *(CellInterface* other);
};

