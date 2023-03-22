#pragma once
#include <iostream>
#include <exception>
using namespace std;

struct SheetExceptionInterface : public std::exception
{
public:
    virtual const char * what () const throw ()=0;
};

struct SheetRowNumberOutOfRangeException: SheetExceptionInterface{
    const char * what () const throw (){
        return "[Error!] row number out of range";
    }
};

struct SheetColumNumberOutOfRangeException: SheetExceptionInterface {
    const char * what () const throw (){
        return "[Error!] column number out of range";
    }
};

struct SheetNegativeDimensions: SheetExceptionInterface{
    const char * what () const throw (){
        return "[Error!] Dimensions cant be smaller than 0";
    }
};
