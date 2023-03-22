#pragma once
#include <iostream>
#include <exception>
using namespace std;

struct MathExceptionInterface : public std::exception
{
public:
    virtual const char * what () const throw ()=0;
};

struct MathTypesConflictException: MathExceptionInterface{
    const char * what () const throw (){
        return "[MATH Error!] types conflict error";
    }
};