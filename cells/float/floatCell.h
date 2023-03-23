#pragma once
#include "../cellInterface.h"
#include <iostream>
#include <string>



using namespace std;
/**
 *  float type cell
 * !cant interact with string cell!
 * !!all operators all legal!!
 */
class FloatCell final: public CellInterface{

public:
    FloatCell(double floatCell);

    string serialize();


    CellInterface* deserialize(string serializedCell);

    union CellInterface::cellDataUnion getValue();
    enum CellInterface::type getType();

    bool operator <(CellInterface& other);

    bool operator >(CellInterface& other);

    CellInterface& operator +=(CellInterface& other);



    CellInterface& operator /=(CellInterface& other);


};


