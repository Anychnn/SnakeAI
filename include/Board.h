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
    Board(const int rowCnt_,const int colCnt_);
    virtual ~Board();
    void createRandomFood();
    Point getPoint(const Pos& pos);
    void setPointType(const Pos& pos,Point::Type type);
private:
    vector<vector<Point>> content;
    Pos *food= nullptr;
    int size;

};
#endif //SNAKEAI_BOARD_H
