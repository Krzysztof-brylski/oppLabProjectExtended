#pragma once
#include <iostream>
#include <exception>
using namespace std;
/**
 * math exceptions
 */
struct MathExceptionInterface : public std::exception
{
public:
    virtual const char * what () const throw ()=0;
};
/**
 * MathTypesConflictException is thrown when someone wants to perform illegal math operation
 */
struct MathTypesConflictException: MathExceptionInterface{
    const char * what () const throw (){
        return "[MATH Error!] types conflict error";
    }
};