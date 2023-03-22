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
     *
     */
    void drawChangeTypeMenu();

    /**
     *
     */
    void drawValueChangeMenu();

    /**
     *
     */
    void validateSize(int newRows, int newColumns);
public:
    /**
     * view constructor
     * @param name screen name
     * @param data screen data
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



