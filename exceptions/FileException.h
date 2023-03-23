#pragma once
#include <iostream>
#include <exception>
using namespace std;
/**
 * files exceptions
 */
struct FileExceptionInterface : public std::exception
{
public:
    virtual const char * what () const throw ()=0;
};

/**
 * FileDimensionsEncodingException is thrown when file has improperly encoded sheet dimensions
 *
 */
struct FileDimensionsEncodingException: FileExceptionInterface{
    const char * what () const throw (){
        return "[Error!] Incorrect dimensions encoding ";
    }
};

/**
 * FileCellDataEncodingException is thrown when data in file are improperly encoded
 */
struct FileCellDataEncodingException: FileExceptionInterface{
    const char * what () const throw (){
        return "[Error!] Incorrect cell data encoding";
    }
};