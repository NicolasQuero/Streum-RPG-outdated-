#include <iostream>
#include "Oueurj.h"
#include "Pos.h"

using namespace std;

Oueurj::Oueurj() : pos() {

}

Oueurj::Oueurj(Pos p) : pos(p) {

}

Oueurj::Oueurj(int x, int y) : pos(x, y) {

}
