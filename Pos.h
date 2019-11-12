#ifndef POSITION_H_INCLUDED
#define POSITION_H_INCLUDED
#include <iostream>

class Pos {
public:
    int x, y;
    Pos(int x = -1, int y = -1);
    int getX() const;
    int getY() const;
    void setX(int &x);
    void setY(int &y);
    void setPos(int &x, int &y);
    double dist(Pos &P) const;

};


#endif // POSITION_H_INCLUDED
