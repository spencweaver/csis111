//battleship.cpp -- create a battleship game
//CSIS 111-D01_202320

//Include statements
#include <fstream>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

//Global declarations: Constants and type definitions only -- no variables
struct SHOT {
    int x;
    int y;
};

char board[25][25];

//Function prototypes
SHOT fire(int x, int y);


int main()
{
//In cout statement below SUBSTITUTE your name and lab number
cout << "Spencer Weaver -- Lab 8" << endl << endl;
//Variable declarations
int row_counter = 0;
int column_counter = 0;


// ifstream board;
// board.open("board.txt");

char ch;
fstream fin("board.txt", fstream::in);
while (fin >> noskipws >> ch) {
    // if (ch == '~') {
    //     continue;
    // }

    if (ch == '\n') {
        row_counter++;
        column_counter = 0;
        continue;
    }

    board[row_counter][column_counter] = ch;
    column_counter++;
    // for (int i = 0;i < 25;i++){
    //     for (int j = 0; j < 25;j++) {

    //         board[j][i] = ch;
    //     }
    // }
    // cout << ch; // Or whatever


}

while (true) {
    int x, y;
    cout << "\nPlease enter the x and y coordinates: ";
    cin >> x >> y;

    fire(x, y);
}


cout << "\nboard[3][7]: " << board[3][7] << endl;
cout << "\nboard[24][24]: " <<board[24][24] << endl;

return 0;
}

//Function definitions
SHOT fire (int x, int y) {




    SHOT shot;
    shot.x = x;
    shot.y = y;

    if (board[shot.x][shot.y] == '#') {
        cout << "HIT" << endl;
        board[shot.x][shot.y] = 'H';
    } else if (board[shot.x][shot.y] == 'H') {
        cout << "HIT AGAIN" << endl;
    } else {
        cout << "MISS" << endl;
    }
}