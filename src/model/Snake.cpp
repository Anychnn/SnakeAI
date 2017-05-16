//
// Created by Administrator on 2017/5/13.
//

#include "../../include/model/Snake.h"
#include "../../include/GameCtrl.h"

Snake::Snake() {}
Snake::~Snake() {}

void Snake::setDirection(const Direction &d) {
    direc=d;
}

void Snake::setMap(Map* const map) {
    this->map=map;
}

Direction Snake::getDirection() const {
    return direc;
}

bool Snake::isDead() const {
    return dead;
}

void Snake::testMinPath(const Pos &from, const Pos &to, std::list<Direction> &path) {
    map->setTestEnabled(true);
    findMaxPath(from,to,path);
    Pos cur=from;
    for(const Direction d:path){
        map->getPoint(cur).setDist(GameCtrl::)
    }
}

void Snake::addBody(const Pos &p) {
    if(bodies.size()==0){
        map->get
    }
}