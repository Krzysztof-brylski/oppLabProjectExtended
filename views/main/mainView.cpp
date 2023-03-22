//
// Created by Krzysztof on 17.03.2023.
//

#include "mainView.h"

MainView::MainView(string name, string data, struct ViewStack *ViewStack) {
    this->name=name;
    this->data=data;
    this->ViewStack=ViewStack;
}
MainView::~MainView(){
    delete this->ViewStack;
}

void MainView::drawMenu(){
    this->clearScreen();
    cout<<"_______________"<<endl;
    cout<<"View: "<< this->name<<endl<<endl;
    cout<<"1. Create new Sheet"<<endl;
    cout<<"2. Load sheet from file"<<endl;
    cout<<"3. Exit"<<endl;
}

void MainView::draw(){

    this->drawMenu();

    int select=0;
    cin>>select;
    switch(select){
        case 1:
            this->ViewStack->push(new CreateSheetView("Creating new sheet","", this->ViewStack));
            break;
        case 2:
            this->ViewStack->push(new LoadSheetView("Loading sheet from file","", this->ViewStack));
            break;
        case 3:
            this->goPreviousView();
            break;
        default:
            cout<<"Command undefined!"<<endl;
    }

}





