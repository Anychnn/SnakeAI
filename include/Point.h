//
// Created by Administrator on 2017/5/18.
//

#ifndef SNAKEAI_POINT_H
#define SNAKEAI_POINT_H


#include "Pos.h"
#include <cstdint>
class Point {
public:
    static const int MAX_VALUE=UINT32_MAX;
    enum Type{
        EMPTY,
        SNAKE_BODY,
        SNAKE_TAIL,
        SNAKE_HEAD,
        WALL,
        FOOD
    };

    Point(const Pos &pos=Pos(-1,-1));

    virtual ~Point();
    void setType(Type type);
    int getX();
    int getY();

    int getDist() const;
    void setDist(int dist);

    const Pos &getParent() const;

    void setParent(const Pos &parent);

    bool isVisited() const;

    void setVisited(bool visited);

    Type type;
    Pos pos;
    Pos parent;
    int dist;
    bool visited;
private:

};


#endif //SNAKEAI_POINT_H
