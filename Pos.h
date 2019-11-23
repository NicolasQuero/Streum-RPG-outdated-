#ifndef POSITION_H_INCLUDED
#define POSITION_H_INCLUDED
#include <iostream>
#include <string>

using namespace std;

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
    friend ostream &operator<<(ostream &out, const Pos &pos) {
        out << "(" << pos.x << ", " << pos.y << ")";
        return out;
    }

};




#endif // POSITION_H_INCLUDED
