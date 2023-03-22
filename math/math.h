#pragma once
#include <iostream>
#include "../cells/cellInterface.h"
#include "../cells/int/intCell.h"
#include "../cells/float/floatCell.h"
#include "../cells/string/stringCell.h"
#include "../exceptions/MathException.h"
class math {

public:
    static CellInterface* sum(CellInterface** arr,int size);
    static CellInterface* min(CellInterface** arr,int size);
    static CellInterface* max(CellInterface** arr,int size);
    static CellInterface* avg(CellInterface** arr,int size);
};


