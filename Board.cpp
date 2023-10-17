//
// Created by ADMIN on 16-Oct-23.
//

#include "Board.h"

int Board::counterNumbers = 0;


Board::Board() {
    generateBoard();
}

void Board::generateBoard() {
    for (int row=0; row < N; row++) {
        for (int col= 0; col < N; col ++) {
            board[row][col] = new Object('.', col, row);
        }
    }
}

string Board::getDetails(Object* dicePtr ) {\
    stringstream details;
    details << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    for (int row=0; row < N; row++) {
        string rowDetails = "";
        for (int col= 0; col < N; col ++) {
            rowDetails += Board::getPix(col, row);
            rowDetails += " ";

        }
        details << "\t" << row << " " << rowDetails << endl;
    }
    stringstream rowdetails;
    for  (int col= 0; col < N; col ++) {
        rowdetails <<  " " << col;
    }
    details  <<  "\t " << rowdetails.str();
    details << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

    return details.str();
}

char Board::getPix(int x, int y) {
    if (0 <= x <= N && 0 <= y <= N) {
        return board[y][x]->getPix();
    } else {
        return '.';
    }
}

void Board::setLocation(char pix, int x, int y) {
    if (0 <= x <= N && 0 <= y <= N) {

        board[y][x]->setPix(pix);

    }
}

void Board::updateLocation(Object *object) {
    int newX = object->getXLoc();
    int newY = object->getYLoc();
    if (0 <= newX <= N && 0 <= newY <= N) {
        if (board[newY][newX]->getPix()) {
            board[newY][newX] = object;
            counterNumbers ++;
            setLocation(object->getPix(), newX, newY);
        }
    }
}

Object *Board::getObject(int x, int y) {
    return board[y][x];
}



