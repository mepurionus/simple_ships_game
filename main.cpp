#include "header_files/headers/write_info.h"
#include "header_files/game.h"
#include <stdlib.h>

int main()
{   
    do
    {
        int option;
        option = Write::Menu::menu();
        switch (option)
        {
        case 1:
            Game::StartGame::start_game();
            break;
        case 2:
            Write::Menu::tutorial();
            break;
        case 0:
            exit(0);
        default:
            break;
        }
    } while (true);
    return 0;
}