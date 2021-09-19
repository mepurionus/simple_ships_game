#pragma once
#include <cstdlib>
#include <time.h>
#include <iostream>

namespace Array
{
    class Hidden 
    {
        private:
        static int random_number()
        {
            int number = rand()%10;
            return number;
        }
        static bool check_array(int array[10][10], int x, int y)
        {
            if(array[x][y] == 1) return false;
            else return true;
        }
        public:
        static void write_null_array(int array[10][10])
        {
            // to make thing easier to check where is no ship
            for(int x = 0; x < 10; x++)
            {
                for(int y = 0; y < 10; y++)
                {
                    array[x][y] = 0;
                }
            }
        }
        static void write_ships_to_array(int array[10][10])
        {
            srand(time(NULL));
            
            // define we need 12 ships in total
            for(int h = 0; h < 12; h++)
            {
                int check = false;
                int x, y;
                do {
                    x = random_number();
                    y = random_number();
                    check = check_array(array, x, y);
                } while(check == false);
                array[x][y] = 1;
            }

        }
    };
    class Visible
    {
        public:
        static void write_empty(std::string array[10][10])
        {
            // write non-checked territory to the visible to user array
            for(int x = 0; x < 10; x++)
            {
                for(int y = 0; y < 10; y++)
                {
                    array[x][y] = "O";
                }
            }
        }
        static std::string write_value(int h)
        {
            // returns the value depending on the check-in
            std::string to_giveback;
            switch(h)
            {
                case 1:
                    // missed
                    to_giveback = "N";
                    break;
                case 0:
                    // hitted
                    to_giveback = "X";
                    break;
            }
            return to_giveback;
        }
    };
}