#include <iostream>
#include <fstream>
#include "file/fileDriver.h"

using namespace std;
int main() {

    FileDriver fileDriver("test.txt",ios::in);
    try{
        fileDriver.validateFile();
    }catch(FileExceptionInterface &e){
        cout<<e.what()<<endl;
    }

//    cout<<fileDriver.fileExists()<<endl;
//    cout<<fileDriver.fileEmpty()<<endl;
}
