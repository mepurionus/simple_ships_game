#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <time.h>

using namespace std;

string visibletab[10][10];
int hiddentab[10][10];

void write_to_array()
{
    for(int x = 0; x < 10; x++) {
            for (int y = 0; y < 10; y ++) {
                visibletab[x][y] = "O";
                hiddentab[x][y] = 0;
            }
        }
}

void rand_to_array()
{
    for (int k = 0; k < 10; k++) {
         int y = rand()%10;
         if(hiddentab[k][y] != 1) hiddentab[k][y] = 1;
         else k--;
        }
}

void start_informations()
{
    cout << "Basic informations about the game: \n1. One mine in one line\n2. Type only numbers from 1 to 10\n3. Have fun.\n";
    cout << "To begin press ENTER" << endl;
    cin.get();
}

void top_thing(int hitsleft, int hitships, int triesintotal)
{
    system("cls");

    cout << "Legend: \nQ - missed\nX - hit\nO - not checked" << endl;
    cout << hitsleft << " ships left!\nU hit " << hitships << " ships" << endl;
    cout << triesintotal << " tries in total!" << endl;
}

void print_game_board()
{
    for(int x = 0; x < 10; x++) {
            for (int y = 0; y < 10; y ++) {
                cout << visibletab[x][y] << "|";
            }
            cout << endl;
        }
    cout << endl;
}

int main()
{
    srand(time(NULL));

    int hitsleft = 10;
    int hitships = 0;
    int triesintotal = 1;

    write_to_array();
    rand_to_array();
    start_informations();

    do {
        int variablex, variabley;
        top_thing(hitsleft, hitships, triesintotal);    
        print_game_board();  

        cout << "Give X and Y: ";
        cin >> variabley >> variablex;
        if(hiddentab[variablex-1][variabley-1] == 1) {
            visibletab[variablex-1][variabley-1] = "X";
            hitsleft = hitsleft - 1;
            hitships = hitships + 1;
        } else {
            visibletab[variablex-1][variabley-1] = "N";
        }

        triesintotal = triesintotal + 1;
        } while (hitsleft > 0);

        cout << "Congratulations! U hit all ships possible in the game with " << triesintotal << " tries!";

        cin.ignore();
        cin.get();
        return 0;
}
