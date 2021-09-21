#pragma once
#include <iostream>

namespace Write
{
    class Menu
    {
        public:
        static void tutorial()
        {
            // game "tutorial"
            system("cls");
            std::cout << "How to Play\n\n";
            std::cout << "To play this game you need to guess X and Y of ship position. \n";
            std::cout << "If you guess the right spot of the ship on the screen you get X.\n";
            std::cout << "If you do not guess the right spot of the ship you are going to get N.\n";
            std::cout << "If you did not check the spot you are going to have O on the board.\n";
            std::cout << "\n";
            std::cout << "Press ENTER to get back to menu...";
            std::cin.ignore();
            std::cin.get();
        }
        static int menu()
        {
            system("cls");
            int num;
            std::cout << "Simple Ships Game\n\n";
            std::cout << "1. Start game\n";
            std::cout << "2. Tutorial\n";
            std::cout << "0. Quit\n";
            std::cout << "\nType selected option: ";
            std::cin >> num;
            return num;
        }
    };
    class Game
    {
        private:
        static void print_game_info(int hitsleft, int triesintotal)
        {
            system("cls");
            std::cout << "Legend: \nN - missed \nX - hit\nO - not checked\n";
            std::cout << hitsleft+1 << " ships left and you made " << triesintotal << " tries. \nType 0 to go to main menu.\n";
        }
        static void print_game_board(std::string array[10][10])
        {
            for(int x = 0; x < 10; x++) {
                for (int y = 0; y < 10; y ++) {
                    std::cout << array[x][y] << "|";
                }
                std::cout << std::endl;
            }
        }
        public:
        static void print_game(std::string array[10][10], int hits, int tries)
        {
            print_game_info(hits, tries);
            std::cout << std::endl;
            print_game_board(array);
        }
        static void ending(int tries)
        {
            std::cout << "Congratulations! You guessed the place of all ships on the map! It took " << tries << " tries in total.\n\n";
            std::cout << "Press ENTER to get back to menu...";
            std::cin.ignore();
            std::cin.get();
        }
    };
}