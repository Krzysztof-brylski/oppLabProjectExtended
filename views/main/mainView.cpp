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
    cout<<"data: "<<this->data<<endl<<endl;
    cout<<"1. next"<<endl;
    cout<<"2. prev"<<endl;
    cout<<"3. error"<<endl;
}

void MainView::draw(){

    this->drawMenu();

    int select=0;
    cin>>select;
    switch(select){
        case 1:
            this->ViewStack->push(new MainView("test data auuuu view2","view 2", this->ViewStack));
            break;
        case 2:
            this->goPreviousView();
            break;
        case 3:
            this->callErrorScreen("Test Error");
            break;
    }

}





