//
// Created by ADMIN on 16-Oct-23.
//

#ifndef ROWS_N_COLUMNS_COUNTER_H
#define ROWS_N_COLUMNS_COUNTER_H

#include "Object.h"

class Counter: public Object {
private:
    int points;
    char pixle;
public:
    Counter();
    Counter(char pix, int val, int newX, int newY);

    int getPoints();

    void setPoints(int val);
};


#endif //ROWS_N_COLUMNS_COUNTER_H
