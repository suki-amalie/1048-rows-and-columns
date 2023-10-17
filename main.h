//
// Created by ADMIN on 16-Oct-23.
//

#ifndef ROWS_N_COLUMNS_MAIN_H
#define ROWS_N_COLUMNS_MAIN_H

#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>

#include "Player.h"
#include "Dice.h"
#include "Counter.h"
#include "Board.h"

using namespace std;

const int DIMENSION = 7;
const int NCOLORS = 3;
char colors[NCOLORS]= {'R', 'G', 'B'};
Board* theBoard = nullptr;
Dice theDice;

Player player1;
Player player2;

/* SET UP FUNCTIONS*/
void setUpPlayers();
void setUpBoard();
void setUpDice();
void setUpCounters();

/* ~~~~~~~~~~~~ GAME FUNCTIONS ~~~~~~~~~~*/
bool colIsEmpty(int col);
bool rowIsEmpty(int col);
bool hasCounter(int ID, int move);
void makeAMove(Player &player);
void playGame();
void endGame();
/* ~~~~~~~~~~~~ INPUT FUNCTIONS ~~~~~~~~~~*/

int askForNumber(string question, int min, int max);
string askForString(string question);
#endif //ROWS_N_COLUMNS_MAIN_H
