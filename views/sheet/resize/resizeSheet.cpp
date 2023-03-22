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

void ResizeSheet::draw() {
    int newRows=0,newColumns=0;
    this->drawMenu();
    cin>>newRows;
    cin>>newColumns;
    this->sheet->resize(newRows,newColumns);
    this->goPreviousView();
}