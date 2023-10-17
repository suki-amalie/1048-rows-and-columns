//
// Created by ADMIN on 16-Oct-23.
//

#ifndef ROWS_N_COLUMNS_BOARD_H
#define ROWS_N_COLUMNS_BOARD_H

#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include "Object.h"

using namespace std;

class Board {
private:
    static const int N = 7;
    Object* board[N][N];
    static int counterNumbers;
public:
    Board();
    void generateBoard();

    string getDetails(Object* dicePtr);
    char getPix(int x, int y);
    Object* getObject(int x, int y);

    void setLocation(char pix, int x, int y);
    void updateLocation(Object* object);
};


#endif //ROWS_N_COLUMNS_BOARD_H
