//
// Created by Krzysztof on 21.03.2023.
//

#include "stringCell.h"

StringCell::StringCell(const char* textData,int size){
    this->valid_type=CellInterface::FLOAT;
    this->cellDataUnion.textData = new char[size];
    strcpy( this->cellDataUnion.textData,textData);
}

string StringCell::serialize(){
    string temp = this->cellDataUnion.textData;
    return "string,"+temp+" ";
}

CellInterface* StringCell::deserialize(string serializedCell) {
    //todo decode serializedCell
    return new StringCell((char*)serializedCell.c_str(),serializedCell.length());
}

union CellInterface::cellDataUnion StringCell::getValue() {
    return this->cellDataUnion;
}
enum CellInterface::type StringCell::getType(){
    return this->valid_type;
}

CellInterface *StringCell::operator+(CellInterface *other) {
    if(this->valid_type != other->getType()){
        return this;
    }
    this->cellDataUnion.intData += other->getValue().intData;
    return this;
}

CellInterface *StringCell::operator-(CellInterface *other) {
    if(this->valid_type != other->getType()){
        return this;
    }
    this->cellDataUnion.intData -= other->getValue().intData;
    return this;
}

CellInterface *StringCell::operator *(CellInterface *other) {
    if(this->valid_type != other->getType()){
        return this;
    }
    this->cellDataUnion.intData *= other->getValue().intData;
    return this;
}