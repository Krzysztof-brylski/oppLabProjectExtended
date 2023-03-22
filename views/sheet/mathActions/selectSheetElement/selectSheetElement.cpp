//
// Created by Krzysztof on 22.03.2023.
//

#include "selectSheetElement.h"

SelectSheetElement::SelectSheetElement(Sheet *sheet, class ViewStack *ViewStack) {
    this->sheet=sheet;
    this->name="Select sheet element...";
    this->ViewStack=ViewStack;
}

SelectSheetElement::~SelectSheetElement() {
    delete this->sheet;
    delete this->ViewStack;
}

void SelectSheetElement::drawMenu() {
    this->clearScreen();
    cout << this->name << endl << endl;
    cout << "___________________________" << endl;
    cout<<"Set on with element wud you like to perform math action"<<endl;
    cout<<"1. row: "<<endl;
    cout<<"2. column: "<<endl;
    cout<<"3. Go back: "<<endl;
}

void SelectSheetElement::draw() {
    int elementNumber,select;
    this->drawMenu();
    cin>>select;
    if(select != 3){
        cout<<"select element number:"<<endl;
        cin>>elementNumber;
    }

    switch (select) {
        case 1:
            this->ViewStack->push(
                new MathActions(this->sheet->getRowCells(elementNumber),
                    this->sheet->getColumnsNumber(),
                    this->ViewStack
                )
            );

            break;
        case 2:
            this->ViewStack->push(
                new MathActions(this->sheet->getColumnCells(elementNumber),
                    this->sheet->getRowsNumber(),
                    this->ViewStack
                )
            );
            break;
        case 3:
            this->goPreviousView();
            break;
        default:
            cout<<"Command undefined!"<<endl;
            break;
    }


}