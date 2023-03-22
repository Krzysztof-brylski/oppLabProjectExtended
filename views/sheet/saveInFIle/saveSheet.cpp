//
// Created by Krzysztof on 20.03.2023.
//


#include "saveSheet.h"

SaveSheet::SaveSheet(Sheet *sheet, class ViewStack *ViewStack) {
    this->sheet=sheet;
    this->name="Saving Sheet in file ...";
    this->ViewStack=ViewStack;
}

SaveSheet::~SaveSheet() {
    delete this->sheet;
    delete this->ViewStack;
}

void SaveSheet::drawMenu() {
    this->clearScreen();
    cout << this->name << endl << endl;
    cout << "___________________________" << endl;
    cout << "set file name:" << endl;

}

void SaveSheet::draw() {
    string fileName;
    this->drawMenu();
    cin>>fileName;
    FileDriver* file = new FileDriver(fileName,ios::out);
    file->saveSheetInFile(this->sheet);
    cout<<"success.."<<endl;
    this->goPreviousView();
}