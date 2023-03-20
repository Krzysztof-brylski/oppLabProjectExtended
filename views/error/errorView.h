#pragma once
#pragma hdrstop
#include "../viewInterface.h"
#include "../default/defaultView.h"
using namespace std;

class ErrorView: public ViewInterface{

public:
    ErrorView(string error,class ViewStack* viewStack);
    ~ErrorView();

    void clearScreen() final;

    void goPreviousView() final;

    void callErrorScreen(string errorMessage);

    void drawMenu();

    void draw();



};


