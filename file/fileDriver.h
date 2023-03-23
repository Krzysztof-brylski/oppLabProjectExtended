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
/**
 * file driver provides methods for file validation, and for building/ saving sheet from/to file
 */
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
     * validate if serialized cell is properly encoded
     * @param str
     * @return
     */
    static bool  validateSerializedCell(string serializedCell);
    /**
     * detect with type of cell is serializedCell
     * @param serializedCell
     * @return cell object
     */
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
     * check is file properly endoced
     * @return
     */
    bool validateFile();
    /**
     * perform regex match
     * @param str
     * @param regex
     * @return
     */
    static bool regexMatch(string str, string regex);



    /**
     * build sheet from file
     * @return serializedCellString
     */
    Sheet* buildSheetFromFile();

    /**
     * save sheet in file
     * @param sheet
     */
    void saveSheetInFile( Sheet* sheet);
};