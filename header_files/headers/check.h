#pragma once
#include <iostream>
#include "write_info.h"

namespace CheckInVariables
{
    class CheckVar
    {
        public:
        static void check_for_menu(int value)
        {
            if(value == 0)
            {
                Write::Menu::menu();
            }
        }
        static int check_for_correct(int vx, int vy)
        {
            int x = (vx > 0 && vx < 11);
            int y = (vy > 0 && vy < 11);
            if(x == 1 && y == 1) 
            {
                return 1;
            } else {
                return 0;
            }
        }
    };
}  