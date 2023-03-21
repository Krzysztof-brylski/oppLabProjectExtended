//
// Created by Krzysztof on 21.03.2023.
//

#include "floatCell.h"

FloatCell::FloatCell(double floatCell) {
    this->valid_type=CellInterface::FLOAT;
    this->cellDataUnion.floatData=floatCell;
}

string FloatCell::serialize(){
    return "float,"+ to_string(this->cellDataUnion.floatData)+" ";
}

CellInterface* FloatCell::deserialize(string serializedCell) {
    //todo decode serializedCell
    return new FloatCell(stof(serializedCell));
}

union CellInterface::cellDataUnion FloatCell::getValue() {
    return this->cellDataUnion;
}
enum CellInterface::type FloatCell::getType(){
    return this->valid_type;
}

CellInterface *FloatCell::operator+(CellInterface *other) {
    if(this->valid_type != other->getType()){
        return this;
    }
    this->cellDataUnion.intData += other->getValue().intData;
    return this;
}

CellInterface *FloatCell::operator-(CellInterface *other) {
    if(this->valid_type != other->getType()){
        return this;
    }
    this->cellDataUnion.intData -= other->getValue().intData;
    return this;
}

CellInterface *FloatCell::operator *(CellInterface *other) {
    if(this->valid_type != other->getType()){
        return this;
    }
    this->cellDataUnion.intData *= other->getValue().intData;
    return this;
}

