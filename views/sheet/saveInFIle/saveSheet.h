#pragma once
#include "../../default/defaultView.h"
#include "../../../sheet/sheet.h"
#include "../../../file/fileDriver.h"
class SaveSheet final: public DefaultView{
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
    SaveSheet(Sheet* sheet,class ViewStack* ViewStack);

    /**
     * destructor
     */
    ~SaveSheet();

    /**
     * draw screen
     */
    void draw();



};



