//
//  Cell.cpp
//  HelloWorld
//
//  Created by yann on 13/12/2022.
//  Copyright (c) 2022 yann. All rights reserved.
//

#include "Cell.h"
#include "Positions.h"
#include <iostream>

Cell::Cell(int row, int column)
{
    m_row = row;
    m_col = column;
    std::string r = std::to_string(row);
    std::string c = std::to_string(column);
    m_index = std::stoi(c + r);
    m_state = ((rand()%10) > 7 ? true: false);
}

void Cell::setPosition(int position)
{
    m_position = position;
}

int Cell::getPosition()
{
    return m_position;
}

int Cell::getIndex()
{
    return m_index;
}

int Cell::getRow()
{
    return m_row;
}

int Cell::getColumn()
{
    return m_col;
}

gboolean Cell::getState()
{
    return m_state;
}

void Cell::kill()
{
    m_state = false;
}

void Cell::resurrect()
{
    m_state = true;
}