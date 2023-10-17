//
// Created by ADMIN on 16-Oct-23.
//

#include "Dice.h"

Dice::Dice(): Object() {
    pix = '+';
}

Dice::Dice(char pix, int x, int y) : Object(pix, x, y) {

}

void Dice::moveDice(int inc, int player_ID) {
    if (player_ID == 1) {
        updatelocY(inc);
    } else {
        updatelocX(inc);
    }
}

int Dice::getPoints() {
    return 0;
}



