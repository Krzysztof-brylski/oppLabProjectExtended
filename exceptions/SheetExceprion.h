#pragma once
#include <iostream>
#include <exception>
using namespace std;
/**
 * sheet exceptions
 */
struct SheetExceptionInterface : public std::exception
{
public:
    virtual const char * what () const throw ()=0;
};
/**
 *  SheetRowNumberOutOfRangeException is thrown someone wants to access sheet row out of sheet range
 */
struct SheetRowNumberOutOfRangeException: SheetExceptionInterface{
    const char * what () const throw (){
        return "[Error!] row number out of range";
    }
};

/**
 *  SheetColumNumberOutOfRangeException is thrown someone wants to access sheet column out of sheet range
 */
struct SheetColumNumberOutOfRangeException: SheetExceptionInterface {
    const char * what () const throw (){
        return "[Error!] column number out of range";
    }
};
/**
 *  SheetNegativeDimensions is thrown someone wants wants set sheet dimensions to 0
 */
struct SheetNegativeDimensions: SheetExceptionInterface{
    const char * what () const throw (){
        return "[Error!] Dimensions cant be smaller than 0";
    }
};
