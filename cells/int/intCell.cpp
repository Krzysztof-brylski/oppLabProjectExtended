//
// Created by Krzysztof on 21.03.2023.
//

#include "intCell.h"

IntCell::IntCell(int intCell){
    this->valid_type=CellInterface::INT;
    this->cellDataUnion.intData=intCell;
}
IntCell::IntCell(IntCell &other)  {
    this->valid_type=other.getType();
    this->cellDataUnion=other.getValue();
}

string IntCell::serialize(){
    return "int,"+ to_string(this->cellDataUnion.intData)+" ";
}

CellInterface* IntCell::deserialize(string serializedCell) {
    //todo decode serializedCell
    return new IntCell(stof(serializedCell));
}


union CellInterface::cellDataUnion IntCell::getValue() {
    return this->cellDataUnion;
}
enum CellInterface::type IntCell::getType(){
    return this->valid_type;
}

bool IntCell::operator>(CellInterface &other) {
    if(this == &other){
        return false;
    }
    switch(other.getType()){
        case CellInterface::STRING:
            throw  MathTypesConflictException();
            break;
        case CellInterface::INT:
            return (this->cellDataUnion.intData > other.getValue().intData);
            break;
        case CellInterface::FLOAT:
            return (this->cellDataUnion.intData > (int)other.getValue().floatData);
    }

}

bool IntCell::operator< (CellInterface &other) {

    if(this == &other){
        return false;
    }
    switch(other.getType()){
        case CellInterface::STRING:
            throw  MathTypesConflictException();
            break;
        case CellInterface::INT:
            return (this->cellDataUnion.intData < other.getValue().intData);
            break;
        case CellInterface::FLOAT:
            return (this->cellDataUnion.intData < (int)other.getValue().floatData);
    }


}

CellInterface &IntCell::operator /=(CellInterface &other) {
    if(this == &other){
        return *this;
    }
    switch(other.getType()){
        case CellInterface::STRING:
            throw  MathTypesConflictException();
            break;
        case CellInterface::INT:
            this->cellDataUnion.intData /= other.getValue().intData;
            break;
        case CellInterface::FLOAT:
            this->cellDataUnion.intData /= (int)other.getValue().floatData;
    }
    return *this;
}

CellInterface *IntCell::operator=(CellInterface* other) {
    if(other == this){
        return this;
    }
    this->valid_type = other->getType();
    this->cellDataUnion = other->getValue();
    return this;
}
CellInterface& IntCell::operator+=(CellInterface &other) {
    if(this == &other){
        return *this;
    }
    switch(other.getType()){
        case CellInterface::STRING:
            throw  MathTypesConflictException();
            return *this;
            break;
        case CellInterface::INT:
            this->cellDataUnion.intData += other.getValue().intData;
            break;
        case CellInterface::FLOAT:
            this->cellDataUnion.intData += (int)other.getValue().floatData;
    }
    return *this;
}


