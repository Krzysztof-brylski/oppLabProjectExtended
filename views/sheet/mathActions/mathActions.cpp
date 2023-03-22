//
// Created by Krzysztof on 20.03.2023.
//

#include "mathActions.h"
MathActions::MathActions(CellInterface** arr,int size,class ViewStack* ViewStack) {
    this->arr=arr;
    this->size=size;
    this->ViewStack=ViewStack;
}

MathActions::~MathActions() {
    delete this->arr;
    delete this->ViewStack;
}

void MathActions::drawMenu() {
    this->clearScreen();
    cout << "___________________________" << endl;
    cout<<"select math action: "<<endl;
    cout<<"1. sum: "<<endl;
    cout<<"2. min: "<<endl;
    cout<<"3. max: "<<endl;
    cout<<"4. avg: "<<endl;
    cout<<"5. go back: "<<endl;
}

void MathActions::draw() {
    int select=0;
    this->drawMenu();
    cin>>select;
    try {
        switch (select) {
            case 1:
                this->ViewStack->push(
                        new MathActionResult(
                                math::sum(this->arr, this->size),
                                "Sum",
                                this->ViewStack
                        )
                );
                break;
            case 2:
                this->ViewStack->push(
                        new MathActionResult(
                                math::min(this->arr, this->size),
                                "Min",
                                this->ViewStack
                        )
                );
                break;
            case 3:
                this->ViewStack->push(
                        new MathActionResult(
                                math::max(this->arr, this->size),
                                "Max",
                                this->ViewStack
                        )
                );
                break;
            case 4:
                this->ViewStack->push(
                        new MathActionResult(
                                math::avg(this->arr, this->size),
                                "Avg",
                                this->ViewStack
                        )
                );
                break;
            case 5:
                this->goPreviousView();
                break;
            default:
                cout << "Command undefined!" << endl;
                break;
        }
    }
    catch(MathExceptionInterface &e){
        this->callErrorScreen(e.what());
    }

}