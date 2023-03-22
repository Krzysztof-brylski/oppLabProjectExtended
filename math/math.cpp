//
// Created by Krzysztof on 22.03.2023.
//

#include "math.h"

CellInterface* math::sum(CellInterface** arr,int size){
    CellInterface* result= nullptr;
    if(dynamic_cast<IntCell*>(arr[0]) != nullptr){
        result = new IntCell(0);
    }
    else if(dynamic_cast<FloatCell*>(arr[0]) != nullptr){
        result = new FloatCell(0.0);
    }
    else{
        throw MathTypesConflictException();
    }
    for (int i = 0; i < size; ++i) {
        try{
             *result += *arr[i];
        }catch(MathExceptionInterface &e){
            throw MathTypesConflictException();
            return nullptr;
        }
    }
    return  result;
}

CellInterface* math::min(CellInterface** arr,int size){

    if(dynamic_cast<StringCell*>(arr[0]) != nullptr){
        throw MathTypesConflictException();
    }
    CellInterface* result= arr[0];

    for (int i = 0; i < size; ++i) {
        try{
            if(*result > *arr[i]){
                result=arr[i];
            }
        }catch(MathExceptionInterface &e){
            throw MathTypesConflictException();
            return nullptr;
        }
    }
    return  result;
}

CellInterface* math::max(CellInterface** arr,int size){
    if(dynamic_cast<StringCell*>(arr[0]) != nullptr){
        throw MathTypesConflictException();
    }
    CellInterface* result= arr[0];

    for (int i = 0; i < size; ++i) {
        try{
            if(*result < *arr[i]){
                result=arr[i];
            }
        }catch(MathExceptionInterface &e){
            throw MathTypesConflictException();
            return nullptr;
        }
    }
    return  result;
}
CellInterface* math::avg(CellInterface **arr, int size) {
    if(dynamic_cast<StringCell*>(arr[0]) != nullptr){
        throw MathTypesConflictException();
    }
    CellInterface* result=math::sum(arr,size);
    IntCell* temp = new IntCell(size);
    (*result) /= (*temp);

    return result;

}