//
// Created by ADMIN on 16-Oct-23.
//

#include "Object.h"

Object::Object() {
    setPix(' ');
    locX = 0;
    locY = 0;
}

Object::Object(char pix, int x, int y) {
    setPix(pix);
    locX = x;
    locY = y;
}

char Object::getPix() {
    return pixel;
}

int Object::getXLoc() {
    return locX;
}

int Object::getYLoc() {
    return locY;
}

string Object::getDetails() {
    stringstream details;
    details << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    details << "Pix: " << getPix() << "\tLocation x, y: " << getXLoc() << " , " << getYLoc() << endl;
    details << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    return details.str();
}

void Object::setPix(char pix) {
    pixel = (pix != ' ') ? pix:'.';
}

void Object::updatelocX(int inc) {
    locX += inc;
}

void Object::updatelocY(int inc) {
    locY += inc;
}



