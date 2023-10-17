//
// Created by ADMIN on 16-Oct-23.
//

#include "Player.h"

Player::Player() {
    setName("");
    setScore(0);
}



string Player::getName() {
    return playerName;
}

int Player::getScore() {
    return score;
}

int Player::getID() {
    return ID;
}

void Player::setName(string name) {
    playerName = (name != "" ) ? name: "NONE";
}

void Player::setScore(int val) {
    score = (val >= 0) ? val : 0;
}

void Player::updateScore(int val) {
    setScore(score + val);
}

string Player::getDetails() {
    stringstream details;
    details << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    details << "Player name: " << getName() << "\tScore: " << getScore() << "\tID: "  << ID << endl;
    details << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    return details.str();
}

Player::Player(string name, int newScore, int newID) {
    setName(name);
    setScore(newScore);
    ID = newID;
}







