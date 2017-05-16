//
// Created by Administrator on 2017/5/13.
//

#ifndef SNAKEAI_MAP_H
#define SNAKEAI_MAP_H


#include "Point.h"
#include <list>

class Map {
public:
    typedef Pos::SizeType SizeType;

    Map(const SizeType rowCnt_, const SizeType colCnt_);

    ~Map();

    Point &getPoint(const Pos &p);
    const Point& getPoint(const Pos &p) const;
    SizeType getRowCount() const;

    SizeType getColCount() const;

    SizeType getSize() const;

    bool isTestEnabled() const;

    void setTestEnabled(bool testEnabled);

    bool isInside(const Pos &p) const;

    bool isEmpty(const Pos &p) const;

    bool isEmptyNotVisit(const Pos &p) const;

    bool isSafe(const Pos &p) const;

    bool isAllBody() const;

    /**
     * Food API
     */
    void createRandFood();

    void createFood(const Pos &pos);

    void removeFood();

    bool hasFood() const;

    const Pos& getFood() const;


    static SizeType distance(const Pos & from,const Pos & to);
    void showPos(const Pos & pos);

    void showPath(const Pos &start,const std::list<Direction> &path);

private:
    static const long TEST_INTERVAL = 20;
    std::vector<std::vector<Point>> content;
    SizeType size;
    Pos food;
    bool testEnabled = false;

    std::vector<Pos> getEmptyPoints() const;

    void testPos(const Pos &p, const Point::Type type);
};


#endif //SNAKEAI_MAP_H
