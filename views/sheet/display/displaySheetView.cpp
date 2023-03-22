//
// Created by Krzysztof on 20.03.2023.
//

#include "displaySheetView.h"

DisplaySheetView::DisplaySheetView(Sheet *sheet, class ViewStack *ViewStack) {
    this->sheet=sheet;
    this->name="Displaying Sheet: ";
    this->ViewStack=ViewStack;
}
DisplaySheetView::~DisplaySheetView() {
    delete this->sheet;
    delete this->ViewStack;
}

void DisplaySheetView::drawMenu(){
    this->clearScreen();
    cout<<"___________________________"<<endl;
    cout<< this->name<<endl<<endl;
    for(int i=0;i<this->sheet->getRowsNumber();i++){
        for(int z=0;z<this->sheet->getColumnsNumber();z++){
            if(dynamic_cast<CellInterface*>(this->sheet->getCell(i,z)) == nullptr){
                cout<<"### ";
                continue;
            }
            cout<<this->sheet->getCell(i,z)->serialize()<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"___________________________"<<endl;
    cout<<"1. Display sheet"<<endl;
    cout<<"2. Perform math actions"<<endl;
    cout<<"3. Set cell value"<<endl;
    cout<<"4. Resize sheet"<<endl;
    cout<<"5. Save sheet"<<endl;
    cout<<"6. exit"<<endl;

}

void DisplaySheetView::draw() {
    this->drawMenu();
    int select=0;
    cin>>select;
    switch (select) {
        case 1:
            return;
        case 2:
            //this->ViewStack->push(new SheetMathActionView(this->sheet,this->ViewStack))
            break;
        case 3:
            //this->ViewStack->push(new SheetSetCellValueView(this->sheet,this->ViewStack))
            break;
        case 4:
            //this->ViewStack->push(new SheetResizeView(this->sheet,this->ViewStack))
            break;
        case 5:
            //this->ViewStack->push(new SheetSaveInFIleView(this->sheet,this->ViewStack))
            break;
        case 6:
            this->goPreviousView();
            break;
        default:
            cout<<"Command undefined!"<<endl;
            break;
    }

}