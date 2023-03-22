//
// Created by Krzysztof on 22.03.2023.
//

#include "mathActionResult.h"


MathActionResult::MathActionResult(CellInterface *result, std::string mathActionName, class ViewStack *ViewStack) {
    this->result=result;
    this->name=mathActionName;
    this->ViewStack=ViewStack;
}
MathActionResult::~MathActionResult() {
    delete this->result;
    delete this->ViewStack;
}

void MathActionResult::drawMenu() {
    this->clearScreen();
    cout <<"Math action result screen"<<endl;
    cout << "___________________________" << endl;
    cout<<"Drawing Result of: "<< this->name<<endl;
    cout<<result->serialize()<<endl<<endl;
    cout<<"1. go back"<<endl;
}
void MathActionResult::draw() {
    int a=0;
    this->drawMenu();

    cin>>a;
    if(a==1){
        this->goPreviousView();
    }

}