#include "createSheet.h"


CreateSheetView::CreateSheetView(string name, string data, class ViewStack *ViewStack) {
    this->name=name;
    this->data=data;
    this->ViewStack=ViewStack;
}

CreateSheetView::~CreateSheetView(){
    delete this->ViewStack;
}

void CreateSheetView::validateSize(int newRows, int newColumns ){
    if(newRows<0 or newColumns<0 ){
        throw new SheetNegativeDimensions();
    }

}


void CreateSheetView::drawMenu() {
    this->clearScreen();

    cout<<"___________________________"<<endl<<endl;
    cout<<"Set row number and columns number: "<<endl;
}


void CreateSheetView::draw() {

    int newRows=0,newColumns=0;
    this->drawMenu();
    cin>>newRows;
    cin>>newColumns;
    try {
        this->validateSize(newColumns, newRows);
    }catch(SheetExceptionInterface &e){
        this->callErrorScreen(e.what());
    }

    Sheet* sheet= new Sheet(newRows,newColumns);

    this->ViewStack->pop();
    this->ViewStack->push( new DisplaySheetView(sheet,this->ViewStack));
}
