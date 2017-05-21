//
// Created by Administrator on 2017/5/18.
//

#include "Point.h"


Point::~Point() {
}

void Point::setType(Point::Type type) {
    this->type = type;
}

int Point::getX() {
    return pos.getX();
}

int Point::getY() {
    return pos.getY();
}

Point::Point(const Pos &pos) : pos(pos) {}

int Point::getDist() const {
    return dist;
}

void Point::setDist(int dist) {
    Point::dist = dist;
}

const Pos &Point::getParent() const {
    return parent;
}

void Point::setParent(const Pos &parent) {
    Point::parent = parent;
}

bool Point::isVisited() const {
    return visited;
}

void Point::setVisited(bool visited) {
    Point::visited = visited;
}
