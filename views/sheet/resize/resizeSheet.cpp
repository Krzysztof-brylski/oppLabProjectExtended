//
// Created by Krzysztof on 20.03.2023.
//


#include "resizeSheet.h"

ResizeSheet::ResizeSheet(Sheet *sheet, class ViewStack *ViewStack) {
    this->sheet=sheet;
    this->name="Resizing sheet...";
    this->ViewStack=ViewStack;
}

ResizeSheet::~ResizeSheet() {
    delete this->sheet;
    delete this->ViewStack;
}

void ResizeSheet::drawMenu() {
    this->clearScreen();
    cout << this->name << endl << endl;
    cout << "___________________________" << endl;
    cout<<"Set new row number and new columns number: "<<endl;

}

void ResizeSheet::validateSize(int newRows, int newColumns ){
    if(newRows<0 or newColumns<0 ){
        throw new SheetNegativeDimensions();
    }
    if(newRows >this->sheet->getRowsNumber()){
        throw new SheetRowNumberOutOfRangeException();
    }

    if(newColumns >this->sheet->getColumnsNumber()){
        throw new SheetColumNumberOutOfRangeException();
    }
}


void ResizeSheet::draw() {
    int newRows=0,newColumns=0;
    this->drawMenu();
    cin>>newRows;
    cin>>newColumns;
    try{
        this->validateSize(newRows,newColumns);
    }catch(SheetExceptionInterface &e){
        this->callErrorScreen(e.what());
    }
    this->sheet->resize(newRows,newColumns);
    this->goPreviousView();
}