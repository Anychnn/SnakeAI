//
// Created by Administrator on 2017/5/13.
//

#ifndef SNAKEAI_POS_H
#define SNAKEAI_POS_H

#include "Direction.h"
#include <vector>
#include <string>
#include <cstddef>
#include <ostream>

class Pos {
public:
    typedef std::size_t SizeType;
    Pos(const SizeType x_=0,const SizeType y_=0);
    ~Pos();
    SizeType getX() const;
    SizeType getY() const;
    void setX(const SizeType x_);
    void setY(const SizeType y_);

    friend Pos operator+(const Pos &a,const Pos &b);
    friend bool operator==(const Pos &a,const Pos &b);
    friend bool operator!=(const Pos &a,const Pos &b);

    std::string toString() const;

    Direction getDirectionTo(const Pos &p) const;

    Pos getAdj(const Direction d) const;
    std::vector<Pos> getAllAdj() const;


    friend std::ostream &operator<<(std::ostream &os, const Pos &pos);

private:
    SizeType x;
    SizeType y;
};


#endif //SNAKEAI_POS_H
