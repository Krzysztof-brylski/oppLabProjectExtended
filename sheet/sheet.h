//
// Created by Krzysztof on 09.03.2023.
//
#pragma once
#include <cstring>
#include <iostream>
#include <fstream>
#include <string>
#include "../cells/cellInterface.h"
#include "../cells/int/intCell.h"
using namespace std;
/**
 * sheet class provides methods for sheet management
 */
class Sheet {
private:
    CellInterface*** arrayPtr= nullptr;
    int numRows=0;
    int numColumns=0;
public:

    /**
     * Constructor for sheet
     * @param[in] rowsNumber - number of rows for new sheet
     * @param[in] columnsNumber - number of columns for new sheet
     */
    Sheet(int rowsNumber=0, int columnsNumber=0);
    /**
     *
     * destructor
     */
     ~Sheet();
    /**
     * resizing sheet array
     * @param[in] newRowsNumber - new number of rows for new sheet
     * @param[in] newColumnsNumber - new number of columns for new sheet
     */
    void resize( int newRowsNumber, int newColumnsNumber);

public:
    /**
     * getter for rows number
     * @return rows number
     */
    int getRowsNumber();
    /**
    * getter for columns number
    * @return columns number
    */
    int getColumnsNumber();
    /**
     * operatpr []
     * @param i
     * @return
     */
    CellInterface* &operator[](int i);
public:

    /**
     * setting value and type for specified cell
     * @param cell
     * @param rowNumber
     * @param columnNumber
     */
    void setCell(CellInterface* cell, int rowNumber, int columnNumber);

    /**
     * getting specified cell
     * @param rowNumber
     * @param columnNumber
     * @return
     */
    CellInterface* getCell(int rowNumber, int columnNumber);

    /**
     * return all cells from specified row
     * @param rowNumber
     * @return array with cells from specified row
     */
    CellInterface** getRowCells(int rowNumber);

    /**
     * return all cells from specified column
     * @param columnNumber
     * @return array with cells from specified column
     */
    CellInterface** getColumnCells(int columnNumber);

};


