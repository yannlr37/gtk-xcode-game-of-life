//
//  Application.h
//  HelloWorld
//
//  Created by yann on 19/12/2022.
//  Copyright (c) 2022 yann. All rights reserved.
//

#ifndef __HelloWorld__Application__
#define __HelloWorld__Application__

#include <stdio.h>
#include <gtk/gtk.h>
#include "callbacks.h"
#include "View.h"
#include "Grid.h"

class Application {
    
private:
    View *m_view;
    Grid *m_grid;
    void createGui();
    
public:
    Application(int *argc, char ***argv);
    void run();
    
};

#endif /* defined(__HelloWorld__Application__) */
