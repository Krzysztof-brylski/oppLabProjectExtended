//
// Created by Krzysztof on 18.03.2023.
//

#include "defaultView.h"


void DefaultView::goPreviousView() {
    this->ViewStack->pop();
}

void DefaultView::clearScreen(){
    system("cls");
}

void  DefaultView::callErrorScreen(string errorMessage){
    this->ViewStack->push(new ErrorView(errorMessage,ViewStack));
}

void DefaultView::drawMenu() {

}


ViewInterface::~ViewInterface() {

}
