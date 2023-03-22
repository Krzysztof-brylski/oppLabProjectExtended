#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include "../exceptions/FileException.h"
#include "../cells/cellInterface.h"
#include "../sheet/sheet.h"
#include "../cells/int/intCell.h"
#include "../cells/float/floatCell.h"
#include "../cells/string/stringCell.h"
using namespace std;

class FileDriver{
private:
    string fileName;
    fstream* file;
    int fileSize;

private:
    /**
     * calculate selected file size;
     * @return
     */
    int calculateFileSize();
    /**
     *
     * @param str
     * @return
     */
    static bool  validateSerializedCell(string serializedCell);

    CellInterface* detectCellType(string serializedCell);

public:
    /**
     * constructor
     * @param filename
     */
    FileDriver(string filename, ios_base::openmode mode);

    /**
     * destructor
     */
    ~FileDriver();

    /**
     * check if file exists
     * @return bool
     */
    bool fileExists();

    /**
     * check is file empty
     * @return bool
     */
    bool fileEmpty();
    /**
     *
     * @return
     */
    bool validateFile();
    /**
     *
     * @param str
     * @param regex
     * @return
     */
    static bool regexMatch(string str, string regex);



    /**
     *
     * @return serializedCellString
     */
    Sheet* buildSheetFromFile();

    /**
     *
     * @param sheet
     */
    void saveSheetInFile( Sheet* sheet);
};