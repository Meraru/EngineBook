// PushBox.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
using namespace std;

// prototypes
void print(char ground[5][8]);
int xPosition(char ground[5][8]);
int yPosition(char ground[5][8]);
bool win(char ground[5][8]);
void move(int xPos, int yPos, char action, char ground[5][8]);

int main()
{
    char ground[5][8] = {
        {'#','#','#','#','#','#','#','#'},
        {'#',' ','.','.',' ','p',' ','#'},
        {'#',' ','o','o',' ',' ',' ','#'},
        {'#',' ',' ',' ',' ',' ',' ','#'},
        {'#','#','#','#','#','#','#','#'}
    };
    print(ground);

    //int xPos = 1;
    //int yPos = 5;
    char action;

    while (win(ground) == false) {
        cout << "a:left s:right w:up z:down. command?" << endl;
        cin >> action;
        move(xPosition(ground), yPosition(ground), action, ground);

        print(ground);
    }

    cin.get();
}

//print the playground
void print(char ground[5][8]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 8; j++)
        {
            if (j == 7) {
                cout << ground[i][j] << endl;
            }
            else
            {
                cout << ground[i][j];
            }
        }
    }
}

// check player position
int xPosition(char ground[5][8]) {

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 8; j++)
        {
            if (ground[i][j] == 'p' || ground[i][j] == 'P') {
                return i;
            }
        }
    }
}

int yPosition(char ground[5][8]) {

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 8; j++)
        {
            if (ground[i][j] == 'p' || ground[i][j] == 'P') {
                return j;
            }
        }
    }
}

// player movement and constrains
void move(int xPos, int yPos, char action, char ground[5][8]) {
    if (action == 'w') {
        if (ground[xPos][yPos] == 'P') {
            if (ground[xPos - 1][yPos] == ' ') {
                ground[xPos - 1][yPos] = 'p';
                ground[xPos][yPos] = '.';
            }
            if (ground[xPos - 1][yPos] == '.') {
                ground[xPos - 1][yPos] = 'P';
                ground[xPos][yPos] = '.';
            }
            if (ground[xPos - 1][yPos] == 'o') {
                if (ground[xPos - 2][yPos] == '.') {
                    ground[xPos - 2][yPos] = 'O';
                    ground[xPos - 1][yPos] = 'p';
                    ground[xPos][yPos] = '.';
                }
                if (ground[xPos - 2][yPos] == ' ') {
                    ground[xPos - 2][yPos] = 'o';
                    ground[xPos - 1][yPos] = 'p';
                    ground[xPos][yPos] = '.';
                }
            }
            if (ground[xPos - 1][yPos] == 'O') {
                if (ground[xPos - 2][yPos] == '.') {
                    ground[xPos - 2][yPos] = 'O';
                    ground[xPos - 1][yPos] = 'P';
                    ground[xPos][yPos] = '.';
                }
                if (ground[xPos - 2][yPos] == ' ') {
                    ground[xPos - 2][yPos] = 'o';
                    ground[xPos - 1][yPos] = 'P';
                    ground[xPos][yPos] = '.';
                }
            }

        }
        else {
            if (ground[xPos - 1][yPos] == ' ') {
                ground[xPos - 1][yPos] = 'p';
                ground[xPos][yPos] = ' ';
            }
            if (ground[xPos - 1][yPos] == '.') {
                ground[xPos - 1][yPos] = 'P';
                ground[xPos][yPos] = ' ';
            }
            if (ground[xPos - 1][yPos] == 'o') {
                if (ground[xPos - 2][yPos] == '.') {
                    ground[xPos - 2][yPos] = 'O';
                    ground[xPos - 1][yPos] = 'p';
                    ground[xPos][yPos] = ' ';
                }
                if (ground[xPos - 2][yPos] == ' ') {
                    ground[xPos - 2][yPos] = 'o';
                    ground[xPos - 1][yPos] = 'p';
                    ground[xPos][yPos] = ' ';
                }
            }
            if (ground[xPos - 1][yPos] == 'O') {
                if (ground[xPos - 2][yPos] == '.') {
                    ground[xPos - 2][yPos] = 'O';
                    ground[xPos - 1][yPos] = 'P';
                    ground[xPos][yPos] = ' ';
                }
                if (ground[xPos - 2][yPos] == ' ') {
                    ground[xPos - 2][yPos] = 'o';
                    ground[xPos - 1][yPos] = 'P';
                    ground[xPos][yPos] = ' ';
                }
            }
        }
    }
    if (action == 'z') {
        if (ground[xPos][yPos] == 'P') {
            if (ground[xPos + 1][yPos] == ' ') {
                ground[xPos + 1][yPos] = 'p';
                ground[xPos][yPos] = '.';
            }
            if (ground[xPos + 1][yPos] == '.') {
                ground[xPos + 1][yPos] = 'P';
                ground[xPos][yPos] = '.';
            }
            if (ground[xPos + 1][yPos] == 'o') {
                if (ground[xPos + 2][yPos] == '.') {
                    ground[xPos + 2][yPos] = 'O';
                    ground[xPos + 1][yPos] = 'p';
                    ground[xPos][yPos] = '.';
                }
                if (ground[xPos + 2][yPos] == ' ') {
                    ground[xPos + 2][yPos] = 'o';
                    ground[xPos + 1][yPos] = 'p';
                    ground[xPos][yPos] = '.';
                }
            }
            if (ground[xPos + 1][yPos] == 'O') {
                if (ground[xPos + 2][yPos] == '.') {
                    ground[xPos + 2][yPos] = 'O';
                    ground[xPos + 1][yPos] = 'P';
                    ground[xPos][yPos] = '.';
                }
                if (ground[xPos + 2][yPos] == ' ') {
                    ground[xPos + 2][yPos] = 'o';
                    ground[xPos + 1][yPos] = 'P';
                    ground[xPos][yPos] = '.';
                }
            }

        }
        else {
            if (ground[xPos + 1][yPos] == ' ') {
                ground[xPos + 1][yPos] = 'p';
                ground[xPos][yPos] = ' ';
            }
            if (ground[xPos + 1][yPos] == '.') {
                ground[xPos + 1][yPos] = 'P';
                ground[xPos][yPos] = ' ';
            }
            if (ground[xPos + 1][yPos] == 'o') {
                if (ground[xPos + 2][yPos] == '.') {
                    ground[xPos + 2][yPos] = 'O';
                    ground[xPos + 1][yPos] = 'p';
                    ground[xPos][yPos] = ' ';
                }
                if (ground[xPos + 2][yPos] == ' ') {
                    ground[xPos + 2][yPos] = 'o';
                    ground[xPos + 1][yPos] = 'p';
                    ground[xPos][yPos] = ' ';
                }
            }
            if (ground[xPos + 1][yPos] == 'O') {
                if (ground[xPos + 2][yPos] == '.') {
                    ground[xPos + 2][yPos] = 'O';
                    ground[xPos + 1][yPos] = 'P';
                    ground[xPos][yPos] = ' ';
                }
                if (ground[xPos + 2][yPos] == ' ') {
                    ground[xPos + 2][yPos] = 'o';
                    ground[xPos + 1][yPos] = 'P';
                    ground[xPos][yPos] = ' ';
                }
            }
        }
    }
    if (action == 'a') {
        if (ground[xPos][yPos] == 'P') {
            if (ground[xPos][yPos - 1] == ' ') {
                ground[xPos][yPos - 1] = 'p';
                ground[xPos][yPos] = '.';
            }
            if (ground[xPos][yPos - 1] == '.') {
                ground[xPos][yPos - 1] = 'P';
                ground[xPos][yPos] = '.';
            }
            if (ground[xPos][yPos - 1] == 'o') {
                if (ground[xPos][yPos - 2] == '.') {
                    ground[xPos][yPos - 2] = 'O';
                    ground[xPos][yPos - 1] = 'p';
                    ground[xPos][yPos] = '.';
                }
                if (ground[xPos][yPos - 2] == ' ') {
                    ground[xPos][yPos - 2] = 'o';
                    ground[xPos][yPos - 1] = 'p';
                    ground[xPos][yPos] = '.';
                }
            }
            if (ground[xPos][yPos - 1] == 'O') {
                if (ground[xPos][yPos - 2] == '.') {
                    ground[xPos][yPos - 2] = 'O';
                    ground[xPos][yPos - 1] = 'P';
                    ground[xPos][yPos] = '.';
                }
                if (ground[xPos][yPos - 2] == ' ') {
                    ground[xPos][yPos - 2] = 'o';
                    ground[xPos][yPos - 1] = 'P';
                    ground[xPos][yPos] = '.';
                }
            }

        }
        else {
            if (ground[xPos][yPos - 1] == ' ') {
                ground[xPos][yPos - 1] = 'p';
                ground[xPos][yPos] = ' ';
            }
            if (ground[xPos][yPos - 1] == '.') {
                ground[xPos][yPos - 1] = 'P';
                ground[xPos][yPos] = ' ';
            }
            if (ground[xPos][yPos - 1] == 'o') {
                if (ground[xPos][yPos - 2] == '.') {
                    ground[xPos][yPos - 2] = 'O';
                    ground[xPos][yPos - 1] = 'p';
                    ground[xPos][yPos] = ' ';
                }
                if (ground[xPos][yPos - 2] == ' ') {
                    ground[xPos][yPos - 2] = 'o';
                    ground[xPos][yPos - 1] = 'p';
                    ground[xPos][yPos] = ' ';
                }
            }
            if (ground[xPos][yPos - 1] == 'O') {
                if (ground[xPos][yPos - 2] == '.') {
                    ground[xPos][yPos - 2] = 'O';
                    ground[xPos][yPos - 1] = 'P';
                    ground[xPos][yPos] = ' ';
                }
                if (ground[xPos][yPos - 2] == ' ') {
                    ground[xPos][yPos - 2] = 'o';
                    ground[xPos][yPos - 1] = 'P';
                    ground[xPos][yPos] = ' ';
                }
            }
        }
    }
    if (action == 's') {
        if (ground[xPos][yPos] == 'P') {
            if (ground[xPos][yPos + 1] == ' ') {
                ground[xPos][yPos + 1] = 'p';
                ground[xPos][yPos] = '.';
            }
            if (ground[xPos][yPos + 1] == '.') {
                ground[xPos][yPos + 1] = 'P';
                ground[xPos][yPos] = '.';
            }
            if (ground[xPos][yPos + 1] == 'o') {
                if (ground[xPos][yPos + 2] == '.') {
                    ground[xPos][yPos + 2] = 'O';
                    ground[xPos][yPos + 1] = 'p';
                    ground[xPos][yPos] = '.';
                }
                if (ground[xPos][yPos + 2] == ' ') {
                    ground[xPos][yPos + 2] = 'o';
                    ground[xPos][yPos + 1] = 'p';
                    ground[xPos][yPos] = '.';
                }
            }
            if (ground[xPos][yPos + 1] == 'O') {
                if (ground[xPos][yPos + 2] == '.') {
                    ground[xPos][yPos + 2] = 'O';
                    ground[xPos][yPos + 1] = 'P';
                    ground[xPos][yPos] = '.';
                }
                if (ground[xPos][yPos + 2] == ' ') {
                    ground[xPos][yPos + 2] = 'o';
                    ground[xPos][yPos + 1] = 'P';
                    ground[xPos][yPos] = '.';
                }
            }

        }
        else {
            if (ground[xPos][yPos + 1] == ' ') {
                ground[xPos][yPos + 1] = 'p';
                ground[xPos][yPos] = ' ';
            }
            if (ground[xPos][yPos + 1] == '.') {
                ground[xPos][yPos + 1] = 'P';
                ground[xPos][yPos] = ' ';
            }
            if (ground[xPos][yPos + 1] == 'o') {
                if (ground[xPos][yPos + 2] == '.') {
                    ground[xPos][yPos + 2] = 'O';
                    ground[xPos][yPos + 1] = 'p';
                    ground[xPos][yPos] = ' ';
                }
                if (ground[xPos][yPos + 2] == ' ') {
                    ground[xPos][yPos + 2] = 'o';
                    ground[xPos][yPos + 1] = 'p';
                    ground[xPos][yPos] = ' ';
                }
            }
            if (ground[xPos][yPos + 1] == 'O') {
                if (ground[xPos][yPos + 2] == '.') {
                    ground[xPos][yPos + 2] = 'O';
                    ground[xPos][yPos + 1] = 'P';
                    ground[xPos][yPos] = ' ';
                }
                if (ground[xPos][yPos + 2] == ' ') {
                    ground[xPos][yPos + 2] = 'o';
                    ground[xPos][yPos + 1] = 'P';
                    ground[xPos][yPos] = ' ';
                }
            }
        }
    }
}

//check if player win the game
bool win(char ground[5][8]) {
    if ((ground[1][2] == 'O') && (ground[1][3] == 'O')) {
        cout << "Congratualtion!";
        return true;
    }
    else
    {
        return false;
    }
}