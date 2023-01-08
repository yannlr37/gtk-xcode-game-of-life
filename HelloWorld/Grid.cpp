//
//  Grid.cpp
//  HelloWorld
//
//  Created by yann on 13/12/2022.
//  Copyright (c) 2022 yann. All rights reserved.
//

#include "Grid.h"

Grid::Grid(int rows, int columns)
{
    m_rows = rows;
    m_columns = columns;
    initCells();
}

void Grid::initCells()
{
    std::vector<Cell> cells = {};
    
    for (int c = 0; c < m_columns; c++) {
        for (int r = 0; r < m_rows; r++) {
            Cell *cell = new Cell(r, c);
            if (r == 0) {
                if (c == 0) {
                    cell->setPosition(POS_CORNER_TOP_LEFT);
                } else if (c == m_columns-1) {
                    cell->setPosition(POS_CORNER_TOP_RIGHT);
                } else {
                    cell->setPosition(POS_BORDER_TOP);
                }
            } else if (r == m_rows-1) {
                if (c == 0) {
                    cell->setPosition(POS_CORNER_BOTTOM_LEFT);
                } else if (c == m_columns-1) {
                    cell->setPosition(POS_CORNER_BOTTOM_RIGHT);
                } else {
                    cell->setPosition(POS_BORDER_BOTTOM);
                }
            } else {
                if (c == 0) {
                    cell->setPosition(POS_BORDER_LEFT);
                } else if (c == m_columns-1) {
                    cell->setPosition(POS_BORDER_RIGHT);
                } else {
                    cell->setPosition(POS_CENTER);
                }
            }
            cells.push_back(*cell);
        }
    }
    
    m_cells = cells;
}

void Grid::evaluate()
{
    int max = (int) m_cells.size();
    for (int i = 0; i < max; i++) {
        std::vector<Cell> neighbors;
        int neighborsAlive;
        
        neighbors = getNeighbors(i);
        neighborsAlive = getNeighborsAlive(neighbors);
        if (neighborsAlive == 3) {
            m_cells.at(i).resurrect();
        }
        if (neighborsAlive > 3 || neighborsAlive < 2) {
            m_cells.at(i).kill();
        }
    }
}

int Grid::getNeighborsAlive(std::vector<Cell> neighbors)
{
    int len = (int) neighbors.size();
    int res = 0;
    for (int i = 0; i < len; i++) {
        if (neighbors.at(i).getState()) {
            res++;
        }
    }
    return res;
}

std::vector<Cell> Grid::getNeighbors(int index)
{
    std::vector<Cell> neighbors;
    
    if (m_cells.at(index).getPosition() == POS_CENTER) {
        neighbors.push_back(m_cells.at(index - 1));
        neighbors.push_back(m_cells.at(index - m_rows + 1));
        neighbors.push_back(m_cells.at(index - m_rows));
        neighbors.push_back(m_cells.at(index - m_rows - 1));
        neighbors.push_back(m_cells.at(index + 1));
        neighbors.push_back(m_cells.at(index + m_rows - 1));
        neighbors.push_back(m_cells.at(index + m_rows));
        neighbors.push_back(m_cells.at(index + m_rows + 1));
    } else if (m_cells.at(index).getPosition() == POS_CORNER_TOP_LEFT) {
        neighbors.push_back(m_cells.at(index + 1));
        neighbors.push_back(m_cells.at(index + m_rows));
        neighbors.push_back(m_cells.at(index + m_rows + 1));
    } else if (m_cells.at(index).getPosition() == POS_CORNER_TOP_RIGHT) {
        neighbors.push_back(m_cells.at(index + 1));
        neighbors.push_back(m_cells.at(index - m_rows + 1));
        neighbors.push_back(m_cells.at(index - m_rows));
    } else if (m_cells.at(index).getPosition() == POS_CORNER_BOTTOM_LEFT) {
        neighbors.push_back(m_cells.at(index - 1));
        neighbors.push_back(m_cells.at(index - m_rows + 1));
        neighbors.push_back(m_cells.at(index + m_rows + 1));
    } else if (m_cells.at(index).getPosition() == POS_CORNER_BOTTOM_RIGHT) {
        neighbors.push_back(m_cells.at(index - 1));
        neighbors.push_back(m_cells.at(index - m_rows));
        neighbors.push_back(m_cells.at(index - m_rows - 1));
    } else if (m_cells.at(index).getPosition() == POS_BORDER_TOP) {
        neighbors.push_back(m_cells.at(index - m_rows + 1));
        neighbors.push_back(m_cells.at(index - m_rows));
        neighbors.push_back(m_cells.at(index + 1));
        neighbors.push_back(m_cells.at(index + m_rows));
        neighbors.push_back(m_cells.at(index + m_rows + 1));
    } else if (m_cells.at(index).getPosition() == POS_BORDER_BOTTOM) {
        neighbors.push_back(m_cells.at(index - 1));
        neighbors.push_back(m_cells.at(index - m_rows));
        neighbors.push_back(m_cells.at(index - m_rows - 1));
        neighbors.push_back(m_cells.at(index + m_rows - 1));
        neighbors.push_back(m_cells.at(index + m_rows));
    } else if (m_cells.at(index).getPosition() == POS_BORDER_LEFT) {
        neighbors.push_back(m_cells.at(index - 1));
        neighbors.push_back(m_cells.at(index + 1));
        neighbors.push_back(m_cells.at(index + m_rows - 1));
        neighbors.push_back(m_cells.at(index + m_rows));
        neighbors.push_back(m_cells.at(index + m_rows + 1));
    } else if (m_cells.at(index).getPosition() == POS_BORDER_RIGHT) {
        neighbors.push_back(m_cells.at(index - 1));
        neighbors.push_back(m_cells.at(index - m_rows + 1));
        neighbors.push_back(m_cells.at(index - m_rows));
        neighbors.push_back(m_cells.at(index - m_rows - 1));
        neighbors.push_back(m_cells.at(index + 1));
    }
    return neighbors;
}

void Grid::displayCells()
{
    int max = (int) m_cells.size();
    for (int i = 0; i < max; i++) {
        Cell c = m_cells.at(i);
        std::cout << c.getIndex() << " : " << "(";
        std::cout << c.getColumn() << "," << c.getRow() << ")";
        std::cout << " - " << (c.getState() ? "alive" : "dead");
        std::cout << " - " << c.getPosition() << std::endl;
    }
    std::cout << "--------------------------" << std::endl;
}

Cell Grid::getCell(int index)
{
    return m_cells.at(index);
}
