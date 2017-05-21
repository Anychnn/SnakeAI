//
// Created by Administrator on 2017/5/18.
//

#ifndef SNAKEAI_BOARD_H
#define SNAKEAI_BOARD_H

#include <vector>
#include "Point.h"
using std::vector;
class Board{
public:
    Pos food;
    Board(const int rowCnt_,const int colCnt_);
    virtual ~Board();
    void createRandomFood();
    void createFood(Pos &foodPos);
    Point& getPoint(const Pos& pos);
    void setPointType(const Pos& pos,Point::Type type);
    int getRowCnt() const;
    int getColCnt() const;
    bool isEmpty(const Pos & pos);
    bool isEmptyNotVisited(const Pos & pos);
    bool isFood(const Pos & pos);
    bool isInside(const Pos & pos);
    void removeFood();
    bool hasFood();
    bool isAllBody();
    int size();
    int getSnakePointsSize();
private:
    vector<vector<Point>> content;
private:
    vector<Pos> getEmptyPoints();

};
#endif //SNAKEAI_BOARD_H
