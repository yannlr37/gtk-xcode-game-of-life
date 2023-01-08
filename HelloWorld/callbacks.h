//
//  callbacks.h
//  HelloWorld
//
//  Created by yann on 19/12/2022.
//  Copyright (c) 2022 yann. All rights reserved.
//

#ifndef __HelloWorld__callbacks__
#define __HelloWorld__callbacks__

#include <stdio.h>
#include <gtk/gtk.h>
#include "Grid.h"
#include "Cell.h"

gboolean initGrid(GtkWidget *widget, GdkEventExpose *event, gpointer data);
gboolean startGame();
void stopGame();

#endif /* defined(__HelloWorld__callbacks__) */
