#pragma once
#include "../../../default/defaultView.h"
#include "../../../../sheet/sheet.h"
#include "../mathActions.h"
class SelectSheetElement final: public DefaultView{
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
    SelectSheetElement(Sheet* sheet,class ViewStack* ViewStack);

    /**
     * destructor
     */
    ~SelectSheetElement();

    /**
     * draw screen
     */
    void draw();



};



