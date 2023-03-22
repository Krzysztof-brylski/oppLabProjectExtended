#pragma once
#include "../../../default/defaultView.h"
#include "../../../../sheet/sheet.h"

class MathActionResult final: public DefaultView{
private:
    CellInterface* result;
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
    MathActionResult(CellInterface* result,string mathActionName,class ViewStack* ViewStack);

    /**
     * destructor
     */
    ~MathActionResult();

    /**
     * draw screen
     */
    void draw();



};



