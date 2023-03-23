#pragma hdrstop
#pragma once
#include "../exceptions/SheetExceprion.h"
#include <iostream>
#include "stack/viewStack.h"


using namespace std;

class ViewStack;

/**
 * ViewInterface class
 */
class ViewInterface {
public:
    string data="", name="";
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



