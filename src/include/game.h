#pragma once
#include <iostream>
#include <write_array.h>
#include <write_info.h>
#include <check_for_ship.h>

namespace Game
{
    class StartGame
    {
        private:
        static void hidden_tab(int array[10][10])
        {
            // writing stuff to the hidden array
            Array::Hidden::write_null_array(array);
            Array::Hidden::write_ships_to_array(array);
        }
        static void visible_tab(std::string array[10][10])
        {
            // writing stuff to the visible array
            Array::Visible::write_empty(array);
        }
        public:
        static void start_game()
        {
            // write stuff to the hidden tab + write ships
            int hiddentab[10][10];
            hidden_tab(hiddentab);
            
            // write stuff to the visible tab to user
            std::string visibletab[10][10];
            visible_tab(visibletab);
            // declare how much hits you need to make + how much tries
            int hits = 9, tries = 1;

            // just do a game till centrain point
            do {
                // write visible stuff
                Write::Game::print_game(visibletab, hits, tries);
                
                // check if hit
                int p = CheckShip::Check::question(hiddentab, visibletab, tries, hits);
                
                // do stuff if sth happen
                if(p == 1)
                {
                    // u hit
                    hits--;
                    tries++;
                } else {
                    // u miss
                    tries++;
                }
            } while (hits >= 0); // continues till u hit all ships
            
            // game ending and back to menu
            Write::Game::ending(tries);
        }
    };
}