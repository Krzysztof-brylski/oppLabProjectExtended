#include <iostream>
using namespace std;

class viewInterface {
protected:
     int* sheetContainer= nullptr;

public:

    /**
     *
     */
    virtual void draw()=0;

    /**
     *
     */

    virtual void goPreviousView()=0;
    /**
     *
     */
    virtual void goNextView()=0;

    /**
     *
     */
    virtual void clearScreen()=0;

    /**
     * error
     */
     virtual void callErrorScreen()=0;
};



