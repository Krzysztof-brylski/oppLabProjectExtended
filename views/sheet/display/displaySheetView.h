#include "../../default/defaultView.h"
#include "../../../sheet/sheet.h"
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
     * @param name screen name
     * @param data screen data
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



