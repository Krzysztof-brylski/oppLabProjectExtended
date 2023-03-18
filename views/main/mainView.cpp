//
// Created by Krzysztof on 17.03.2023.
//

#include "mainView.h"

MainView::MainView(string data,string name,class ViewStack* ViewStack ){
    this->data=data;
    this->name=name;
    this->ViewStack=ViewStack;
}
ViewInterface::~ViewInterface(){

}

void MainView::callErrorScreen() {}

void MainView::goPreviousView() {
    //cout<<this->ViewStack<<endl;
   //cout<<this->ViewStack->getSize()<<endl;
    this->ViewStack->pop();
}

void MainView::clearScreen() {}



void MainView::draw(){
    int select=0;
    cout<<"_______________"<<endl;
    cout<<"View: "<< this->name<<endl<<endl;
    cout<<"data: "<<this->data<<endl<<endl;
    cout<<"1. next"<<endl;
    cout<<"2. prev"<<endl;
    cin>>select;
    switch(select){
        case 1:
            this->ViewStack->push(new MainView("test data auuuu view2","view 2", this->ViewStack));
            break;
        case 2:
            this->goPreviousView();
            break;
    }

}

