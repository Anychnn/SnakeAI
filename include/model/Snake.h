//
// Created by Administrator on 2017/5/13.
//

#ifndef SNAKEAI_SNAKE_H
#define SNAKEAI_SNAKE_H


#include "Map.h"

class Snake {
public:
    typedef Map::SizeType SizeType;
    Snake();
    ~Snake();
    void setDirection(const Direction &d);
    void setMap(Map * const m);
    Direction getDirection() const;
    bool isDead() const;

    /*
     * Testing methods
     */
    void testMinPath(const Pos &from,const Pos &to,std::list<Direction> &path);
    void testMaxPath(const Pos &from,const Pos &to,std::list<Direction> &path);
    void testHamilton();

    void addBody(const Pos &p);
    void move();
    void move(const std::list<Direction> &path);
    void enableHamilton();

    void decideNext();
private:
    Map* map= nullptr;
    std::list<Pos> bodies;

    Direction direc=NONE;
    bool dead=false;
    bool hamiltonEnabled=false;
    void removeTail();
    const Pos& getHead()const;
    const Pos& getTail() const;
    void findMinPathToFood(std::list<Direction> &path);
    void findMaxPathToFood(std::list<Direction> &path);
    void findPathTo(const int type,const Pos &to,std::list<Direction> &path);
    void findMinPath(const Pos &from,const Pos &to,std::list<Direction> &path);
    void findMaxPath(const Pos &from,const Pos &to,std::list<Direction> &path);
    void buildPath(const Pos &from,const Pos &to,std::list<Direction> &path)const;
    void buildHamilton();
};


#endif //SNAKEAI_SNAKE_H
