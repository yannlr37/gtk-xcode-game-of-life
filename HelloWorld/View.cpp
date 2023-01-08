//
//  View.cpp
//  HelloWorld
//
//  Created by yann on 08/01/2023.
//  Copyright (c) 2023 yann. All rights reserved.
//

#include "View.h"

GtkWidget* View::getMainWindow()
{
    return m_main_window;
}

void View::init(Grid* grid)
{
    m_main_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(m_main_window), "Game of Life");
    
    m_vbox = gtk_vbox_new(FALSE, 4);
    m_drawing_area = gtk_drawing_area_new();
    
    gtk_widget_set_size_request(m_drawing_area, 200, 200);
    g_signal_connect (G_OBJECT(m_drawing_area), "expose_event", G_CALLBACK(initGrid), grid);
    
    gtk_container_add(GTK_CONTAINER(m_vbox), m_drawing_area);
    
    m_separator = gtk_hseparator_new();
    gtk_container_add(GTK_CONTAINER(m_vbox), m_separator);
    
    m_hbox = gtk_hbox_new(FALSE, 4);
    
    m_start_button = gtk_button_new_with_label("Start");
    //g_signal_connect(GTK_BUTTON(m_start_button), "click", G_CALLBACK(startGame), grid);
    
    m_stop_button = gtk_button_new_with_label("Stop");
    
    gtk_box_pack_end(GTK_BOX (m_hbox), m_start_button, FALSE, FALSE, 0);
    gtk_box_pack_end(GTK_BOX (m_hbox), m_stop_button, FALSE, FALSE, 0);
    
    gtk_container_add(GTK_CONTAINER(m_vbox), m_hbox);
    gtk_container_add(GTK_CONTAINER(m_main_window), m_vbox);
}