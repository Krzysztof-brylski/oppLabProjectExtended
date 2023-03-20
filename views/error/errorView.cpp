
#include "errorView.h"


ErrorView::ErrorView(std::string error, class ViewStack *viewStack) {
    this->name="!! Error Screen !!";
    this->data=error;
    this->ViewStack=viewStack;
}

ErrorView::~ErrorView(){
    delete this->ViewStack;
}

void ErrorView::drawMenu() {
    this->clearScreen();
    cout<< this->name<<endl;
    cout<<"____________________________"<<endl;
    cout<<"Error message: "<< this->data<<endl<<endl;
    cout<<"1. Go back"<<endl;
}

void ErrorView::draw() {
    int select;
    this->drawMenu();
    cin>>select;
    switch (select) {
        case 1:
            this->goPreviousView();
            break;
        default:
            cout<<"Comment undefined"<<endl;
    }
    
}

void ErrorView::clearScreen() {
    system("cls");
}

void ErrorView::goPreviousView() {
    this->ViewStack->pop();
}

void ErrorView::callErrorScreen(string errorMessage) {
    return;
}
