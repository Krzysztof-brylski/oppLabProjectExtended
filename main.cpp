#include <iostream>
#include <fstream>
//#include "file/fileDriver.h"
#include "cells/float/floatCell.h"
#include "cells/int/intCell.h"
#include "cells/string/stringCell.h"
#include "views/stack/viewStack.h"
#include "views/main/mainView.h"
using namespace std;




int main() {

//        ViewStack* stack1=new ViewStack();
//        stack1->push(
//                new MainView("Main view","", stack1)
//                );
//        //view stack execution
//        while(!stack1->empty()){
//            stack1->get()->draw();
//        }

    FloatCell* cell1 = new FloatCell(10.1);
    FloatCell* cell2 = new FloatCell(10.2);
    IntCell* cell3 = new IntCell(1);
    IntCell* cell4 = new IntCell(5);
    StringCell* cell5 = new StringCell("test eloo");
    StringCell* cell6 = new StringCell("test eloo 2");

    cout<<cell1->serialize();
    cout<<cell2->serialize()<<endl;
    cout<<cell3->serialize();
    cout<<cell4->serialize()<<endl;
    cout<<cell5->serialize();
    cout<<cell6->serialize()<<endl;

}
