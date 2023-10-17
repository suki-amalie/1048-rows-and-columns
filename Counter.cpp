//
// Created by ADMIN on 16-Oct-23.
//

#include "Counter.h"


Counter::Counter():Object() {
    setPoints(0);
    pixle = 'G';
}

Counter::Counter(char pix, int val, int newX, int newY): Object(pix, newX, newY) {
    setPoints(val);
    if (pixle != '.') {
    }
}

int Counter::getPoints() {
    return points;
}

void Counter::setPoints(int val) {
    points = (val >= 0) ? val:0;
}






