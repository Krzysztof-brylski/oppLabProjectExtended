
#include "loadSheet.h"



LoadSheetView::LoadSheetView(string name, string data, class ViewStack *ViewStack) {
    this->name=name;
    this->data=data;
    this->ViewStack=ViewStack;
}

LoadSheetView::~LoadSheetView(){
    delete this->ViewStack;
}


void LoadSheetView::drawMenu() {
    this->clearScreen();

    cout<<"___________________________"<<endl<<endl;
    cout<<"Enter file name: "<<endl;
}


void LoadSheetView::draw() {

    string fileName;
    this->drawMenu();
    cin>>fileName;

    FileDriver* file = new FileDriver(fileName,ios::in);
    if(!file->fileExists()){
        this->callErrorScreen("Selected file dont exists");
        return;
    }
    if(file->fileEmpty()){
        this->callErrorScreen("Selected file is empty");
        return;
    }
//    try{
//        file->validateFile();
//    }catch(FileExceptionInterface &e){
//        this->callErrorScreen(e.what());
//        return;
//    }

    Sheet* newSheet =file->buildSheetFromFile();

    this->ViewStack->pop();
    this->ViewStack->push( new DisplaySheetView(newSheet,this->ViewStack));
}
