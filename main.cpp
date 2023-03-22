#include <iostream>
#include <fstream>
#include "file/fileDriver.h"
#include "cells/float/floatCell.h"
#include "cells/int/intCell.h"
#include "cells/string/stringCell.h"
#include "sheet/sheet.h"
#include "views/stack/viewStack.h"
#include "views/main/mainView.h"
#include "math/math.h"
using namespace std;




int main() {

//        ViewStack* stack1=new ViewStack();
//        stack1->push(
//                new MainView("Welcome view","",stack1)
//                );
//        //view stack execution
//
//        while(!stack1->empty()){
//            stack1->get()->draw();
//        }
//        FileDriver* driver = new FileDriver("test.txt",ios::in);
//        Sheet* sheet = driver->buildSheetFromFile();
        CellInterface** arr= new CellInterface * [3];

        arr[0] = new FloatCell(5);
        arr[1] = new IntCell(6);
        arr[2] = new FloatCell(11.2);
        try{
            cout<<(math::sum(arr,3))->serialize()<<endl;
            cout<<(math::min(arr,3))->serialize()<<endl;
            cout<<(math::max(arr,3))->serialize()<<endl;
            cout<<(math::avg(arr,3))->serialize()<<endl;
        }catch(MathExceptionInterface &e){
            cout<<e.what()<<endl;
        }

}