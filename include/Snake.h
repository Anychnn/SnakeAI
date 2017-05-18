//
// Created by Administrator on 2017/5/18.
//

#ifndef SNAKEAI_SNAKE_H
#define SNAKEAI_SNAKE_H

#include "Direction.h"
#include "Pos.h"
#include "Board.h"
#include <list>

class Snake{
public:
    std::list<Pos> bodies;
    Board *board= nullptr;
public:
    void move();
    void move(Direction &direc);
    void addBody(const Pos &pos);
    void setBoard(Board *const board);
};
#endif //SNAKEAI_SNAKE_H
