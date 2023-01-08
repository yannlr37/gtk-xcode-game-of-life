//
//  View.h
//  HelloWorld
//
//  Created by yann on 08/01/2023.
//  Copyright (c) 2023 yann. All rights reserved.
//

#ifndef __HelloWorld__View__
#define __HelloWorld__View__

#include <stdio.h>
#include <gtk/gtk.h>
#include "Grid.h"
#include "callbacks.h"

class View {

private:
    GtkWidget *m_main_window;
    GtkWidget *m_vbox;
    GtkWidget *m_hbox;
    GtkWidget *m_separator;
    GtkWidget *m_drawing_area;
    GtkWidget *m_start_button;
    GtkWidget *m_stop_button;

public:
    void init(Grid *grid);
    GtkWidget* getMainWindow();
};

#endif /* defined(__HelloWorld__View__) */
