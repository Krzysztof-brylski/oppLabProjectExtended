#pragma once
#include "../../default/defaultView.h"
#include "../../../math/math.h"
#include "../../../sheet/sheet.h"
#include "./result/mathActionResult.h"
class MathActions final: public DefaultView{
private:
    CellInterface** arr;
    int size;
    /**
     * draw menu
     */
    void drawMenu();

public:
    /**
     * view constructor
     * @param arr array with cells
     * @param size array size
     * @param ViewStack pointer to view stack
     */
    MathActions(CellInterface** arr,int size,class ViewStack* ViewStack);

    /**
     * destructor
     */
    ~MathActions();

    /**
     * draw screen
     */
    void draw();



};



