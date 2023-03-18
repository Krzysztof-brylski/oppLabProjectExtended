#include "../viewInterface.h"
#pragma once
class ViewStack;

class MainView: public ViewInterface {


public:

    MainView(string data,string name,class ViewStack* viewStack);


    /**
     * destructor
     */



    void draw();

    /**
     *
     */

    void goPreviousView();

    /**
     *
     */
    void clearScreen();

    /**
     * error
     */
    void callErrorScreen();


};


