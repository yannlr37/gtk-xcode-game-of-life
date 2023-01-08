//
//  Grid.h
//  HelloWorld
//
//  Created by yann on 13/12/2022.
//  Copyright (c) 2022 yann. All rights reserved.
//

#ifndef __HelloWorld__Grid__
#define __HelloWorld__Grid__

#include <stdio.h>
#include <iostream>
#include <vector>
#include "Cell.h"
#include "Positions.h"

class Grid {
private:
    int m_rows;
    int m_columns;
    std::vector<Cell> m_cells;
    void initCells();
    std::vector<Cell> getNeighbors(int index);
    int getNeighborsAlive(std::vector<Cell> neighbors);
public:
    Grid(int rows, int columns);
    void evaluate();
    void displayCells();
    Cell getCell(int index);
};

#endif /* defined(__HelloWorld__Grid__) */
