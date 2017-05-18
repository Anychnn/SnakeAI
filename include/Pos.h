//
// Created by Administrator on 2017/5/18.
//

#ifndef SNAKEAI_POS_H
#define SNAKEAI_POS_H


class Pos {
public:
    Pos(const int x=0, const int y=0);
    virtual ~Pos();

    int getX() const;

    int getY() const;

private:
    int x;
    int y;
};


#endif //SNAKEAI_POS_H
