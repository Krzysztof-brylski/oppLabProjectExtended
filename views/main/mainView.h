#include "../viewInterface.h"
#include "../default/defaultView.h"
#include "../sheet/create/createSheet.h"
#include "../sheet/load/loadSheet.h"
#pragma once
class ViewStack;

class MainView: public DefaultView {


private:
    /**
     * draw menu
     */
    void drawMenu();

public:
    /**
     * view constructor
     * @param name screen name
     * @param data screen data
     * @param ViewStack pointer to view stack
     */
    MainView(string name,string data,class ViewStack* ViewStack);

    /**
     * destructor
     */
    ~MainView();

    /**
     * draw screen
     */
    void draw();



};


