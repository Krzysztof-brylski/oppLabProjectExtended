#pragma once
#pragma hdrstop
#include "../viewInterface.h"
#include "../error/errorView.h"

class DefaultView: public ViewInterface{

protected:

    virtual void clearScreen();

    virtual void goPreviousView();

    virtual void callErrorScreen(string errorMessage);

    virtual void drawMenu();

};


