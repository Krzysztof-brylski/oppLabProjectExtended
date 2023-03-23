#pragma once
#include "../cellInterface.h"
#include <iostream>
#include <string>

using namespace std;

/**
 *  int type cell
 * !cant interact with string cell!
 * !!all operators all legal!!
 */

class IntCell final: public CellInterface{

public:
    IntCell(int intCell);

    IntCell(IntCell &other);

    string serialize();

    CellInterface* deserialize(string serializedCell);

    union CellInterface::cellDataUnion getValue() ;
    enum CellInterface::type getType() ;

    CellInterface* operator =(CellInterface* other);

    bool operator <(CellInterface& other);

    bool operator >(CellInterface& other);

    CellInterface& operator +=( CellInterface& other);


    CellInterface& operator /=(CellInterface& other);


};


