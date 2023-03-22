//
// Created by Krzysztof on 21.03.2023.
//

#include "intCell.h"

IntCell::IntCell(int intCell){
    this->valid_type=CellInterface::FLOAT;
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

CellInterface *IntCell::operator+(CellInterface *other) {
    if(this->valid_type != other->getType()){
        return this;
    }
    this->cellDataUnion.intData += other->getValue().intData;
    return this;
}

CellInterface *IntCell::operator-(CellInterface *other) {
    if(this->valid_type != other->getType()){
        return this;
    }
    this->cellDataUnion.intData -= other->getValue().intData;
    return this;
}

CellInterface *IntCell::operator *(CellInterface *other) {
    if(this->valid_type != other->getType()){
        return this;
    }
    this->cellDataUnion.intData *= other->getValue().intData;
    return this;
}

CellInterface *IntCell::operator=(CellInterface* other) {
    if(other == this){
        return this;
    }
    this->valid_type = other->getType();
    this->cellDataUnion = other->getValue();
    return this;
}


