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
     * @param result cell with math action result
     * @param mathActionName action name
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



