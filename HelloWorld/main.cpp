//
//  main.cpp
//  HelloWorld
//
//  Created by yann on 12/12/2022.
//  Copyright (c) 2022 yann. All rights reserved.
//

#include <iostream>
#include <vector>
#include <time.h>
#include <gtk/gtk.h>
#include "Grid.h"
#include "Application.h"
#include <sys/time.h>

double microtime(){
    return (double(std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count()) / double(1000000));
}

int main(int argc, char * argv[])
{
    srand(time(NULL));
    std::cout << "Bienvenue dans le Jeu de la Vie\n" << std::endl;
    
    Application *app = new Application(&argc, &argv);
    app->run();
    
    return EXIT_SUCCESS;
}
