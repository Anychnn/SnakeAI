//
// Created by Administrator on 2017/5/18.
//

#ifndef SNAKEAI_POINT_H
#define SNAKEAI_POINT_H


#include "Pos.h"

class Point {
public:
    enum Type{
        EMPTY,
        SNAKE_BODY,
        SNAKE_TAIL,
        SNAKE_HEAD,
        WALL,
        FOOD
    };
    Point();

    virtual ~Point();

    void setType(Type type);

private:
    Pos pos;
    Type type;
};


#endif //SNAKEAI_POINT_H
