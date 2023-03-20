

#include "viewStack.h"
ViewStack::ViewStack(){
    this->size=0;
    this->stack = nullptr;
}

ViewStack::~ViewStack(){
    delete[] this->stack;
}

void ViewStack::push(ViewInterface *view) {
    if(this->stack == nullptr){
        this->stack = new ViewInterface*;
        this->stack[0] = view;
        this->size+=1;
        return;
    }
    ViewInterface** tempArray = new ViewInterface*[this->size];
    for(int i=0;i< this->size;i++){
        tempArray[i]= this->stack[i];
    }
    delete[] this->stack;
    this->stack = new ViewInterface*[(this->size+1)];
    for(int i=0;i< this->size;i++){
         this->stack[i] = tempArray[i];
    }
    this->stack[this->size] = view;
    this->size+=1;
    delete[] tempArray;
}
ViewInterface* ViewStack::get() {
    return  this->stack[(this->size-1)];
}

void ViewStack::pop() {

    this->size-=1;
    ViewInterface **tempArray = new ViewInterface*[this->size];
    for(int i=0;i< this->size;i++){
        tempArray[i]= this->stack[i];
    }
    delete[] this->stack;

    this->stack = new ViewInterface*[this->size];
    for(int i=0;i< this->size;i++){
        this->stack[i]=tempArray[i];
    }

    delete[] tempArray;
}

bool ViewStack::empty(){
    return this->size==0;
}

int ViewStack::getSize(){
    return this->size;
}
