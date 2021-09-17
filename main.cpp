#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <time.h>

using namespace std;

int main()
{
    srand(time(NULL));
    do {
        system("cls");
        string visibletab[10][10];
        int hiddentab[10][10];
        int l[10];
        int hitsleft = 10;
        int hitships = 0;
        int triesintotal = 1;

        for(int x = 0; x < 10; x++) {
            for (int y = 0; y < 10; y ++) {
                visibletab[x][y] = "O";
                hiddentab[x][y] = 0;
            }
        }
        for (int k = 0; k < 10; k++) {
         int y = rand()%10;
         if(hiddentab[k][y] != 1) hiddentab[k][y] = 1;
         else k--;
        }

        do {
        system("cls");
        cout << "Legend: \nQ - missed\nX - hit\nO - not checked" << endl;
        cout << hitsleft << " ships left!\nU hit " << hitships << " ships" << endl;
        cout << triesintotal << " tries in total!" << endl;

        int variablex, variabley;
        for(int x = 0; x < 10; x++) {
            for (int y = 0; y < 10; y ++) {
                cout << visibletab[x][y] << "|";
            }
            cout << endl;
        }
        cout << endl;

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
        cout << "Congratulations! U hit all ships possible in the game with " << triesintotal << "ties!";
        system("pause >nul");
        break;
    } while (true);

}
