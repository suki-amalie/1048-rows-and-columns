//
// Created by ADMIN on 16-Oct-23.
//

#ifndef ROWS_N_COLUMNS_DICE_H
#define ROWS_N_COLUMNS_DICE_H

#include "Object.h"

class Dice: public Object{
private:
    char pix;
public:
    Dice();
    Dice(char pix, int x, int y);

    void moveDice(int inc, int player_ID);
    int getPoints();

};


#endif //ROWS_N_COLUMNS_DICE_H
