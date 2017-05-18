//
// Created by Administrator on 2017/5/18.
//

#include "Pos.h"

Pos::Pos(int x, int y) : x(x), y(y) {}

Pos::~Pos() {

}

int Pos::getX() const {
    return x;
}

int Pos::getY() const {
    return y;
}
