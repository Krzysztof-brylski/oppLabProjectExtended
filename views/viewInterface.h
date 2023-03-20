#pragma hdrstop
#pragma once
#include <iostream>
#include "stack/viewStack.h"


using namespace std;

class ViewStack;


class ViewInterface {
public:
    string data="", name="";
    //Sheet* sheetData=nullptr
    ViewStack* ViewStack;

private:
    /**
     *  delete currently displayed screen from stack
     */

    virtual void goPreviousView()=0;

    /**
     *  clearing screen
     */
    virtual void clearScreen()=0;

    /**
     * pushing error screen on stack
     */
    virtual void callErrorScreen(string errorMessage)=0;


    /**
     * drawing screen menu
     */
     virtual void drawMenu()=0;

public:
    /**
     * drawing screen
     */
    virtual void draw()=0;

     /**
      * destructor
      */
     virtual ~ViewInterface()=0;
};



