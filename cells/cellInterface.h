#pragma once
#include <iostream>
#include <string>
#include "../exceptions/MathException.h"

using namespace std;
/**
 * cell interface
 */
class CellInterface{
protected:
    /**
     * enum with cell data type
     */
    enum type { INT=0, FLOAT=1, STRING=2 } valid_type;
    /**
     *  union with cell data
     */
    union cellDataUnion
    {
        char* textData;
        int intData;
        double floatData;
    } cellDataUnion;

public:
    /**
     * converts object into string
     * @return serialized object
     */
    virtual string serialize()=0;
    /**
     * converts serialized cell into object
     * @param serializedCell[in] string with serialized cell
     * @return cell object
     */
    virtual CellInterface* deserialize(string serializedCell)=0;
    /**
     * get cell data
     * @return union with cell data
     */
    virtual union cellDataUnion getValue()=0;
    /**
     * get cell type
     * @return cell type
     */
    virtual  enum type getType()=0;

    //operators
    /**
     * overloaded < operator
     * @param other
     * @return
     */
    virtual bool operator< (CellInterface& other)=0;

    /**
     * overloaded > operator
     * @param other
     * @return
     */
    virtual bool operator> (CellInterface& other)=0;

    /**
     * overloaded += operator
     * @param other
     * @return
     */
    virtual CellInterface& operator +=( CellInterface& other)=0;


    /**
     * overloaded /= operator
     * @param other
     * @return
     */
    virtual CellInterface& operator /=(CellInterface& other)=0;

};