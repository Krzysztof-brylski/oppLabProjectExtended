#pragma once
#include "../../default/defaultView.h"
#include "../../../sheet/sheet.h"
#include "../../../file/fileDriver.h"
class ResizeSheet final: public DefaultView{
private:
    Sheet* sheet;
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
    ResizeSheet(Sheet* sheet,class ViewStack* ViewStack);

    /**
     * destructor
     */
    ~ResizeSheet();

    /**
     * draw screen
     */
    void draw();



};



