#pragma once
#include <write_array.h>
#include <write_info.h>
#include <check.h>
#include <iostream>

namespace CheckShip
{
    class Check
    {
        private:
        static int check_for_ship(int arrayone[10][10], std::string arraytwo[10][10], int vx, int vy, int tries, int left)
        {
            if(arrayone[vx-1][vy-1] == 1)
            {
                arraytwo[vx-1][vy-1] = Array::Visible::write_value(0);
                return 1;
            } else {
                arraytwo[vx-1][vy-1] = Array::Visible::write_value(1);
                return 0;
            }
        }
        public:
        static int question(int arrayone[10][10], std::string arraytwo[10][10], int tries, int total)
        {
            int vx, vy, check_if_correct;
            do {
            std::cout << "Give X and Y: ";
            std::cin >> vy;
            CheckInVariables::CheckVar::check_for_menu(vy);
            std::cin >> vx;
            CheckInVariables::CheckVar::check_for_menu(vx);
            check_if_correct = CheckInVariables::CheckVar::check_for_correct(vx, vy);
            } while (check_if_correct == 0);
            int h = check_for_ship(arrayone, arraytwo, vx, vy, tries, total);
            return h;
        }
    };
}