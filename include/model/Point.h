//
// Created by Administrator on 2017/5/13.
//

#ifndef SNAKEAI_POINT_H
#define SNAKEAI_POINT_H
#include <cstdint>
#include "Pos.h"
class Point {
public:
    typedef uint32_t ValueType;
    static const ValueType MAX_VALUE=UINT32_MAX;
    enum Type{
        EMPTY,
        WALL,
        FOOD,
        SNAKE_BODY,
        SNAKE_HEAD,
        SNAKE_TAIL,
        TEST_VISIT,
        TEST_PATH
    };

    Point();

    ~Point();

    void setType(Type type_);
    void setParent(const Pos &p_);
    void setDist(const ValueType dist_);
    void setIndex(const ValueType index_);
    Type getType() const;
    Pos getParent()const;
    bool isVisit() const;
    ValueType getDist() const;
    ValueType getIndex() const;

private:
    Type type=EMPTY;
    Pos parent;
    bool visit;
    ValueType dist;
    ValueType index;
};


#endif //SNAKEAI_POINT_H
