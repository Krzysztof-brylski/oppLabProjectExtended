#pragma hdrstop
#pragma once
#include <iostream>
#include "stack/viewStack.h"


using namespace std;

class ViewStack;


class ViewInterface {
public:
//     int* sheetContainer= nullptr;
    string data, name;

    //Sheet* sheetData=nullptr
    ViewStack* ViewStack= nullptr;
    /**
     *
     */
    virtual void draw()=0;

    /**
     *
     */

    virtual void goPreviousView()=0;

    /**
     *
     */
    virtual void clearScreen()=0;

    /**
     * error
     */
     virtual void callErrorScreen()=0;

     /**
      * destructor
      */
     virtual ~ViewInterface()=0;
};



