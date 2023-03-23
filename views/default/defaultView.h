#pragma once
#pragma hdrstop
#include "../viewInterface.h"
#include "../error/errorView.h"
/**
 * default view provides all default methods for view management
 */
class DefaultView: public ViewInterface{

protected:
    /**
     * clearing screen function
     */
    virtual void clearScreen();
    /**
     * function for going back to previous screen
     */
    virtual void goPreviousView();
    /**
     * function for calling error screen
     * @param errorMessage string with error message
     */
    virtual void callErrorScreen(string errorMessage);

    /**
     * drawing default menu
     */
    virtual void drawMenu();

};


