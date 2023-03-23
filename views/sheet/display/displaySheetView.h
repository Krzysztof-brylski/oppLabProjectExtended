#pragma once
#include "../../default/defaultView.h"
#include "../../../sheet/sheet.h"
#include "../saveInFIle/saveSheet.h"
#include "../resize/resizeSheet.h"
#include "../valueSetter/sheetCellValueSet.h"
#include "../mathActions/selectSheetElement/selectSheetElement.h"
class DisplaySheetView final: public DefaultView{
private:
    Sheet* sheet;
    /**
     * draw menu
     */
    void drawMenu();

public:
    /**
     * view constructor
     * @param sheet current sheet
     * @param ViewStack pointer to view stack
     */
    DisplaySheetView(Sheet* sheet,class ViewStack* ViewStack);

    /**
     * destructor
     */
    ~DisplaySheetView();

    /**
     * draw screen
     */
    void draw();



};



