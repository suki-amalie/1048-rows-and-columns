//
// Created by ADMIN on 16-Oct-23.
//

#ifndef ROWS_N_COLUMNS_PLAYER_H
#define ROWS_N_COLUMNS_PLAYER_H

#include <string>
#include <iostream>
#include <sstream>

#include "Dice.h"
using namespace std;
class Player {
private:
    string playerName;
    int score;
    int ID;
public:
    Player();
    Player(string name, int newScore, int newID);

    string getName();
    int getScore();
    int getID();
    string getDetails();

    void updateScore(int val);
    void setScore(int val);
    void setName(string name);


};


#endif //ROWS_N_COLUMNS_PLAYER_H
