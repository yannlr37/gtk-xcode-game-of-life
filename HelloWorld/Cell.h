//
//  Cell.h
//  HelloWorld
//
//  Created by yann on 13/12/2022.
//  Copyright (c) 2022 yann. All rights reserved.
//

#ifndef __HelloWorld__Cell__
#define __HelloWorld__Cell__

#include <stdio.h>
#include <gtk/gtk.h>

class Cell {
private:
    int m_position;
    int m_index;
    int m_row;
    int m_col;
    gboolean m_state;
public:
    Cell(int row, int col);
    void setPosition(int position);
    int getPosition();
    int getIndex();
    int getRow();
    int getColumn();
    gboolean getState();
    void kill();
    void resurrect();
};

#endif /* defined(__HelloWorld__Cell__) */
