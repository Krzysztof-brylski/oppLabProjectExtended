
#include "SheetCellValueSet.h"




SheetCellValueSet::SheetCellValueSet(Sheet *sheet, class ViewStack *ViewStack) {
    this->sheet=sheet;
    this->name="";
    this->ViewStack=ViewStack;
}

SheetCellValueSet::~SheetCellValueSet(){
    delete this->ViewStack;
}


void SheetCellValueSet::drawMenu() {
    this->clearScreen();
    cout<<"___________________________"<<endl<<endl;
    cout<<"Set cell row number and columns number, to edit: "<<endl;
}

void SheetCellValueSet::drawChangeTypeMenu() {
    this->clearScreen();
    cout<<"Select type for modified cell"<<endl;
    cout<<"i, int cell"<<endl;
    cout<<"f, float cell"<<endl;
    cout<<"s, string cell"<<endl;
}

void SheetCellValueSet::drawValueChangeMenu() {
    cout<<"Select new value cell: "<<endl;
}
void SheetCellValueSet::validateSize(int newRows, int newColumns ){
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

void SheetCellValueSet::draw() {
    CellInterface* newCell= nullptr;
    int newRows=0,newColumns=0;
    char result;
    this->drawMenu();
    string valueS;
    cin>>newRows;
    cin>>newColumns;

    try{
        this->validateSize(newRows,newColumns);
    }catch(SheetExceptionInterface &e){
        this->callErrorScreen(e.what());
        return;
    }

    this->drawChangeTypeMenu();
    cin>>result;
    cout<<result;
    switch(result){
        case 'i':
            int valueI;
            this->drawValueChangeMenu();
            cin>>valueI;
            newCell = new IntCell(valueI);

            break;
        case 'f':
            double valueF;
            this->drawValueChangeMenu();
            cin>>valueF;
            newCell = new FloatCell(valueF);
            break;
        case 's':

            this->drawValueChangeMenu();
            cin>>valueS;
            newCell = new StringCell(valueS.c_str(),valueS.length());
            break;
        default:
            cout<<"command undefined!"<<endl;
            break;

    }
    if(newCell != nullptr){
        this->sheet->setCell(newCell,newRows,newColumns);
    }
    this->goPreviousView();
}
