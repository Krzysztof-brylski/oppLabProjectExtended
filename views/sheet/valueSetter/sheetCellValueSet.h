#pragma once
#include "../../default/defaultView.h"
#include "../../../sheet/sheet.h"
#include "../display/displaySheetView.h"
class SheetCellValueSet final: public DefaultView {
private:
    Sheet* sheet;
    /**
     * draw menu
     */
    void drawMenu();

    /**
     * draw menu witch all available cells type
     */
    void drawChangeTypeMenu();

    /**
     * draw menu witch value changing
     */
    void drawValueChangeMenu();

    /**
     * validate if dimensions passed by user is legal
     * @param newRows
     * @param newColumns
     */
    void validateSize(int newRows, int newColumns);
public:
    /**
     * view constructor
     * @param sheet current sheet
     * @param ViewStack pointer to view stack
     */
    SheetCellValueSet(Sheet *sheet, class ViewStack *ViewStack);

    /**
     * destructor
     */
    ~SheetCellValueSet();

    /**
     * draw screen
     */
    void draw();



};



