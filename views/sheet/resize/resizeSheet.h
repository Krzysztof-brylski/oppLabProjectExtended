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
    /**
     * validate if dimensions passed by user is legal
     * @param newRows
     * @param newColumns
     */
    void validateSize(int newRows, int newColumns );
public:
    /**
     * view constructor
     * @param sheet current sheet
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



