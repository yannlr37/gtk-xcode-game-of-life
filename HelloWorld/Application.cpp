//
//  Application.cpp
//  HelloWorld
//
//  Created by yann on 19/12/2022.
//  Copyright (c) 2022 yann. All rights reserved.
//

#include "Application.h"

Application::Application(int *argc, char ***argv)
{
    m_grid = new Grid(100,100);
    m_view = new View();
    gtk_init(argc, argv);
    createGui();
}

void Application::run()
{
    GtkWidget* window;
    window = m_view->getMainWindow();
    gtk_widget_show_all(window);
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
    gtk_main();
}

void Application::createGui()
{
    m_view->init(m_grid);
}
