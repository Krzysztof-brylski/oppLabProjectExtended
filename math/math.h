#pragma once
#include <iostream>
#include "../cells/cellInterface.h"
#include "../cells/int/intCell.h"
#include "../cells/float/floatCell.h"
#include "../cells/string/stringCell.h"
#include "../exceptions/MathException.h"
/**
 * math facade class provides static methods for math actions on cells array
 */

class math {

public:
    /**
     * sum function
     * @param arr array with cells
     * @param size array size
     * @return cell with result
     */
    static CellInterface* sum(CellInterface** arr,int size);

    /**
     * min function
     * @param arr array with cells
     * @param size array size
     * @return cell with result
     */
    static CellInterface* min(CellInterface** arr,int size);

    /**
     * max function
     * @param arr array with cells
     * @param size array size
     * @return cell with result
     */
    static CellInterface* max(CellInterface** arr,int size);

    /**
     * avg function
     * @param arr array with cells
     * @param size array size
     * @return cell with result
     */
    static CellInterface* avg(CellInterface** arr,int size);
};


