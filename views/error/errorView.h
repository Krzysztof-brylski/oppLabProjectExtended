#pragma once
#pragma hdrstop
#include "../viewInterface.h"
#include "../default/defaultView.h"
using namespace std;

class ErrorView: public ViewInterface{

public:
    /**
     * constructor
     * @param error error message
     * @param viewStack viewStack
     */
    ErrorView(string error,class ViewStack* viewStack);

    /**
     *  destructor
     */
    ~ErrorView();

    /**
     * clearing screen function
     */
    void clearScreen() final;

    /**
     * function for going back to previous screen
     */
    void goPreviousView() final;

    /**
     * function for calling error screen (included only to satisfy view interface)
     * @param errorMessage string with error message
     */
    void callErrorScreen(string errorMessage);

    /**
     * drawing view menu
     */
    void drawMenu();
    /**
     * drawing view
     */
    void draw();



};


