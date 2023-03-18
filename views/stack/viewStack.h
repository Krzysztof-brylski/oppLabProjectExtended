#pragma hdrstop
#pragma once
#include "../viewInterface.h"
using namespace std;
#include <iostream>
#include <string>

class ViewInterface;

class ViewStack {
private:
    ViewInterface** stack = new ViewInterface*[0];
    int size;

public:
    /**
     * basic view stack constructor
     */
    ViewStack();

     /**
      * basic view stack destructor
      */
     ~ViewStack();

     /**
      * push view on stack
      */
     void push(ViewInterface* view);

     /**
      * delete last element from stack
      * @return ViewInterface* last view on stack
      */
     void pop();

    /**
     * get last element from stack
     * @return ViewInterface* last view on stack
     */
    ViewInterface* get();



     /**
      * check is stack empty
      * @return bool is stack empty
      */
     bool empty();

     int getSize();

};



