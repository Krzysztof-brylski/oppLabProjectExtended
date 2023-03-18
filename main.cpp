#include <iostream>
#include <fstream>
#include "file/fileDriver.h"
#include "views/stack/viewStack.h"
#include "views/main/mainView.h"
using namespace std;
int main() {

    FileDriver fileDriver("test.txt",ios::in);
    try{
        fileDriver.validateFile();
    }catch(FileExceptionInterface &e){
        cout<<e.what()<<endl;
    }

    ViewStack *viewStack= new ViewStack();
    viewStack->push(new MainView(
                    "test view uaaaa 1",
                "view 1",
                viewStack
            ));
    cout<<viewStack->getSize()<<endl;
    while(!viewStack->empty()){

        viewStack->get();
        viewStack->get()->draw();
    }



//    cout<<fileDriver.fileExists()<<endl;
//    cout<<fileDriver.fileEmpty()<<endl;
}
