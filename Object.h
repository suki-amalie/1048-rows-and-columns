//
// Created by ADMIN on 16-Oct-23.
//

#ifndef ROWS_N_COLUMNS_OBJECT_H
#define ROWS_N_COLUMNS_OBJECT_H

#include <string>
#include <sstream>

using namespace std;
class Object {
protected:
    int locX;
    int locY;
    char pixel;

public:
    /*constructors */
    Object();
    Object(char pix, int x, int y);

    /* accessors*/

    char getPix();
    int getXLoc();
    int getYLoc();
    virtual int getPoints() {return 0;};
    string getDetails();

    void setPix(char pix);
    void updatelocX(int inc);
    void updatelocY(int inc);

};


#endif //ROWS_N_COLUMNS_OBJECT_H
