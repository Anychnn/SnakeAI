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

Pos Pos::getAdj(const Direction &direc) {
    switch (direc){
        case LEFT:
            if(x){
                return Pos(x-1,y);
            }
        case RIGHT:
            return Pos(x+1,y);
        case UP:
            return Pos(x,y+1);
        case DOWN:
            if(y){
                return Pos(x,y-1);
            }
        default:
            break;
    }
    return *this;
}

std::vector<Pos> Pos::getAdjAll() {
    std::vector<Pos> adj;
    for(int i=1;i<=4;i++){
        Pos p=getAdj((Direction)i);
        if (p != *this) {
            adj.push_back(p);
        }
    }
    return adj;
}

bool operator==(const Pos &a, const Pos &b) {
    return a.x==b.x&&b.y==a.y;
}

bool operator!=(const Pos &a, const Pos &b) {
    return !(a==b);
}

Direction Pos::getDirectionTo(Pos &pos) {
    if(x==pos.x){
        if(pos.y-1==y){
            return UP;
        }else if(pos.y+1==y){
            return DOWN;
        }
    }else if(pos.y==y){
        if(pos.x+1==x){
            return LEFT;
        }else if(pos.x-1==x){
            return RIGHT;
        }
    }
    return NONE;
}
