#pragma once
#include <iostream>
#include <exception>
using namespace std;

struct FileExceptionInterface : public std::exception
{
public:
    virtual const char * what () const throw ()=0;
};

struct FileDimensionsEncodingException: FileExceptionInterface{
    const char * what () const throw (){
        return "[Error!] Incorrect dimensions encoding ";
    }
};

struct FileCellDataEncodingException: FileExceptionInterface{
    const char * what () const throw (){
        return "[Error!] Incorrect cell data encoding";
    }
};