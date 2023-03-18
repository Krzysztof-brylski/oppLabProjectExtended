//
// Created by Krzysztof on 18.03.2023.
//

#include "viewStack.h"
ViewStack::ViewStack(){
    this->size=0;
    this->stack=new ViewInterface*[0];
}

ViewStack::~ViewStack(){
    delete[] this->stack;
}

void ViewStack::push(ViewInterface *view) {

    ViewInterface **tempArray = new ViewInterface*[this->size];
    memcpy(tempArray, this->stack,(sizeof(ViewInterface)*this->size) );
    delete[] this->stack;

    this->stack=new ViewInterface*[(this->size+1)];

    memcpy(this->stack,tempArray ,(sizeof(ViewInterface)*this->size) );
    delete[] tempArray;
    this->stack[this->size]=view;
    this->size+=1;
}
ViewInterface* ViewStack::get() {
    return  this->stack[(this->size-1)];
}

void ViewStack::pop() {

    ViewInterface **tempArray = new ViewInterface*[(this->size-1)];
    memcpy(tempArray, this->stack,((sizeof(ViewInterface)*this->size) - sizeof(ViewInterface)) );
    delete[] this->stack;

    this->stack = new ViewInterface*[(this->size-1)];

    memcpy(this->stack,tempArray ,((sizeof(ViewInterface)*this->size) - sizeof(ViewInterface)) );
    delete[] tempArray;

    this->size-=1;

}

bool ViewStack::empty(){
    return this->size==0;
}

int ViewStack::getSize(){
    return this->size;
}
