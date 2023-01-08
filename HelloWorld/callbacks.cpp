//
//  callbacks.cpp
//  HelloWorld
//
//  Created by yann on 19/12/2022.
//  Copyright (c) 2022 yann. All rights reserved.
//

#include "callbacks.h"

/**
 * Init Drawing Area with the cells grid
 */
gboolean initGrid(GtkWidget *widget, GdkEventExpose *event, gpointer data)
{
    g_print("draw cells grid");
    
    Grid *grid = (Grid *) data;
    
    for (int i = 0; i < 10000; i++) {
        Cell cell = grid->getCell(i);
        if (cell.getState()) {
            gdk_draw_rectangle(widget->window,
                           widget->style->fg_gc[gtk_widget_get_state (widget)],
                           cell.getState(),
                           cell.getColumn()*2,
                           cell.getRow()*2,
                           2,
                           2
            );
        }
    }
    
    return TRUE;
}

gboolean startGame(GtkWidget *widget, GdkEventExpose *event, gpointer data)
{
    std::cout << "Start game" << std::endl;
    return TRUE;
}

void stopGame()
{
    
}
