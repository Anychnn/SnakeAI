//
// Created by Administrator on 2017/5/18.
//

#ifndef SNAKEAI_SNAKE_H
#define SNAKEAI_SNAKE_H

#include "Direction.h"
#include "Pos.h"
#include "Board.h"
#include <list>
#include <queue>


class Snake{
public:
    bool dead=false;
    bool completed=false;
    std::list<Pos> bodies;
    Board *board= nullptr;
    Direction direc=NONE;
public:
    void setDirec(Direction direc);
    void move();
    void move(const Direction &direc);
    void move(const std::list<Direction> &path);
    void addBody(const Pos &pos);
    void setBoard(Board *const board);
    Pos getHead();
    Pos getTail();
    void decideNext();
    bool isDead() const;
    void setDead(bool dead);

    bool isCompleted() const;

    void setCompleted(bool completed);

    void findMinPath(const Pos &from,const Pos &to,std::list<Direction> &path);
    void findMaxPath(const Pos &from,const Pos &to,std::list<Direction> &path);
    void findMinPathToFood(std::list<Direction> &path);
    void findMaxPathToTail(std::list<Direction> &path);
private:
    void removeTail();

};
#endif //SNAKEAI_SNAKE_H
