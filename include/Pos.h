//
// Created by Administrator on 2017/5/18.
//

#ifndef SNAKEAI_POS_H
#define SNAKEAI_POS_H


#include <vector>
#include "Direction.h"

class Pos {
public:
    Pos(const int x=0, const int y=0);
    virtual ~Pos();

    int getX() const;
    int getY() const;
    Pos getAdj(const Direction &direc);
    std::vector<Pos> getAdjAll();
    Direction getDirectionTo(Pos &pos);
    friend bool operator==(const Pos &a,const Pos &b);
    friend bool operator!=(const Pos &a,const Pos &b);
private:
    int x;
    int y;
};


#endif //SNAKEAI_POS_H
