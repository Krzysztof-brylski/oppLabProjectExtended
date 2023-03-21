#include <iostream>
#include <fstream>
#include "file/fileDriver.h"
#include "cells/float/floatCell.h"
#include "cells/int/intCell.h"
#include "cells/string/stringCell.h"
#include "sheet/sheet.h"
#include "views/stack/viewStack.h"
#include "views/main/mainView.h"
using namespace std;




int main() {


        FileDriver* driver = new FileDriver("test.txt",ios::in);
        Sheet* sheet=driver->buildSheetFromFile();
        sheet->resize(3,3);
        ViewStack* stack1=new ViewStack();
        stack1->push(
                new DisplaySheetView(sheet,stack1)
                );
        //view stack execution
        while(!stack1->empty()){
            stack1->get()->draw();
        }
//    try{
//        (new FileDriver("test.txt",ios::in))->validateFile();
//    }catch(FileExceptionInterface &e){
//        cout<<e.what()<<endl;
//    }
//
//
//
//
//    cout<<sheet->getCell(0,0)->serialize()<<endl;
}