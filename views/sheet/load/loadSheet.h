#include "../../default/defaultView.h"
#include "../../../sheet/sheet.h"
#include "../display/displaySheetView.h"
#include "../../../file/fileDriver.h"
class LoadSheetView final: public DefaultView {
private:
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
    LoadSheetView(string name,string data,class ViewStack* ViewStack);

    /**
     * destructor
     */
    ~LoadSheetView();

    /**
     * draw screen
     */
    void draw();



};



