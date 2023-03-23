#include "../../default/defaultView.h"
#include "../../../sheet/sheet.h"
#include "../display/displaySheetView.h"
class CreateSheetView final: public DefaultView {
private:
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
     * @param name screen name
     * @param data screen data
     * @param ViewStack pointer to view stack
     */
    CreateSheetView(string name,string data,class ViewStack* ViewStack);

    /**
     * destructor
     */
    ~CreateSheetView();

    /**
     * draw screen
     */
    void draw();



};



