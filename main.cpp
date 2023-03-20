#include <iostream>
#include <fstream>
#include "file/fileDriver.h"
#include "views/stack/viewStack.h"
#include "views/main/mainView.h"
using namespace std;
int main() {

//        ViewInterface** test = new ViewInterface*[3];
//        ViewInterface** test2 = new ViewInterface*[2];
//        MainView* view=new MainView("test","test", nullptr);
//        MainView* view2=new MainView("test2","test2", nullptr);
//        MainView* view3=new MainView("test3","test3", nullptr);
//        test[0]=view;
//        test[1]=view2;
//        test[2]=view3;
//
//        test2[0]=test[0];
//    delete[] test;
//
//        test2[1]->draw();
//        test2[0]->draw();
        ViewStack* stack1=new ViewStack();
        stack1->push(
                new MainView("test","test", stack1)
                );
        while(!stack1->empty()){
            stack1->get()->draw();
        }
}
