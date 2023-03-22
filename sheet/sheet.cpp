//
// Created by Krzysztof on 09.03.2023.
//

#include "sheet.h"


Sheet::Sheet(int rowsNumber, int columnsNumber) {
    this->numRows=rowsNumber;
    this->numColumns=columnsNumber;
    this->arrayPtr = new CellInterface **[this->numRows];
    for (int i = 0; i < this->numRows;i++) {
        this->arrayPtr[i] = new CellInterface*[this->numColumns];
        for(int z =0;z< this->numColumns;z++){
            this->arrayPtr[i][z]= new IntCell(0);
        }
    }
}

int Sheet::getRowsNumber() {
    return this->numRows;
}

int Sheet::getColumnsNumber() {
    return this->numColumns;
}

void Sheet::setCell(CellInterface *cell, int rowNumber, int columnNumber) {
    this->arrayPtr[rowNumber][columnNumber]=cell;
}

CellInterface *&Sheet::operator[](int i) {
    return *this->arrayPtr[i];
}

CellInterface *Sheet::getCell(int rowNumber, int columnNumber) {
    return this->arrayPtr[rowNumber][columnNumber];
}

Sheet::~Sheet() {
    delete[] this->arrayPtr;
}

void Sheet::resize(int newRowsNumber, int newColumnsNumber) {
    CellInterface*** temp = new CellInterface **[this->numRows];
    for (int i = 0; i < this->numRows;i++) {
        temp[i] = new CellInterface*[this->numColumns];
        for(int z=0;z< this->numColumns;z++){
            temp[i][z]= this->arrayPtr[i][z];
        }
    }
    delete[] this->arrayPtr;

    this->arrayPtr = new CellInterface **[newRowsNumber];
    for(int i=0;i<newRowsNumber;i++){
        this->arrayPtr[i] = new CellInterface*[newColumnsNumber];
        for(int z=0;z<newColumnsNumber;z++){
            this->arrayPtr[i][z]= new IntCell(0);
        }
    }


    for (int i = 0; i < this->numRows;i++) {
        for(int z=0; z< this->numColumns;z++){
            cout<<this->arrayPtr[i][z]->serialize()<<endl;
            this->arrayPtr[i][z] = temp[i][z];
        }
    }
    cout<<endl<<endl;
    delete[] temp;
    this->numRows=newRowsNumber;
    this->numColumns=newColumnsNumber;
}
