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

bool FloatCell::operator > (CellInterface &other) {
    if(this == &other){
        return false;
    }
    switch(other.getType()){
        case CellInterface::STRING:
            throw  MathTypesConflictException();
            break;
        case CellInterface::INT:
            return (this->cellDataUnion.floatData > (double)other.getValue().intData);
            break;
        case CellInterface::FLOAT:
            return (this->cellDataUnion.floatData > other.getValue().floatData);
    }

}

bool FloatCell::operator< (CellInterface &other) {
    if(this == &other){
        return false;
    }
    switch(other.getType()){
        case CellInterface::STRING:
            throw  MathTypesConflictException();
            break;
        case CellInterface::INT:
            return (this->cellDataUnion.floatData < (double )other.getValue().intData);
            break;
        case CellInterface::FLOAT:
            return (this->cellDataUnion.floatData < other.getValue().floatData);
    }
}

CellInterface &FloatCell::operator /=(CellInterface &other) {
    if(this == &other){
        return *this;
    }
    switch(other.getType()){
        case CellInterface::STRING:
            throw  MathTypesConflictException();
            break;
        case CellInterface::INT:
            this->cellDataUnion.floatData /= (double )other.getValue().intData;
            break;
        case CellInterface::FLOAT:
            this->cellDataUnion.floatData /= other.getValue().floatData;
    }
    return *this;
}
CellInterface& FloatCell::operator+=(CellInterface &other) {
    if(this == &other){
        return *this;
    }
    switch(other.getType()){
        case CellInterface::STRING:
            throw  MathTypesConflictException();
            return *this;
            break;
        case CellInterface::INT:
            this->cellDataUnion.floatData += (double)other.getValue().intData;
            break;
        case CellInterface::FLOAT:
            this->cellDataUnion.floatData += other.getValue().floatData;
    }
    return *this;

}

