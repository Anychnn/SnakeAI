#include <iostream>
#include "Snake.h"

using std::queue;
void Snake::setBoard(Board *const board) {
    this->board = board;
}

void Snake::addBody(const Pos &pos) {
    if (bodies.size() == 0) {
        bodies.push_back(pos);
        board->setPointType(pos, Point::SNAKE_HEAD);
    } else {
        if (board->getPoint(bodies.back()).type == Point::SNAKE_TAIL) {
            board->setPointType(bodies.back(), Point::SNAKE_BODY);
        }
        bodies.push_back(pos);
        board->setPointType(pos, Point::SNAKE_TAIL);
    }

}

void Snake::move() {
    //如果死亡 不移动
    if(direc==NONE){
        setDead(true);
    }
    if (isDead()) {
        return;
    }
    Pos oldHead=getHead();
    Pos newHead = getHead().getAdj(direc);
    if (board->getPoint(newHead).type == Point::FOOD) {
        board->removeFood();
    } else if(board->getPoint(newHead).type == Point::EMPTY
            ||board->getPoint(newHead).type == Point::SNAKE_TAIL){
        removeTail();
    }else{
        setDead(true);
        return;
    }
    board->setPointType(oldHead, Point::SNAKE_BODY);
    board->setPointType(newHead, Point::SNAKE_HEAD);
    bodies.push_front(newHead);
    board->setPointType(getTail(), Point::SNAKE_TAIL);

}

void Snake::move(const Direction &direc) {
    setDirec(direc);
    move();
}

void Snake::move(const std::list<Direction> &path) {
    for (const Direction &direction:path) {
        setDirec(direction);
        move();
    }
}

Pos Snake::getHead() {
    return bodies.front();
}

Pos Snake::getTail() {
    return bodies.back();
}


void Snake::removeTail() {
    board->setPointType(getTail(), Point::EMPTY);
    bodies.pop_back();
}

bool Snake::isDead() const {
    return dead;
}

void Snake::setDead(bool dead) {
    Snake::dead = dead;
}

void Snake::decideNext() {
    std::list<Direction> pathToFood, pathToTail;
    Snake tmpSnake = Snake(*this);
    Board tmpBoard = (*board);
    tmpSnake.setBoard(&tmpBoard);
    // step 1 寻找最短到food的路径
    tmpSnake.findMinPathToFood(pathToFood);
    if (!pathToFood.empty()) {
        //step 2 利用tmpSnake直接试吃
        tmpSnake.move(pathToFood);
        //如果吃完之后游戏完成  就直接吃掉
        if(tmpBoard.isAllBody()){
            this->direc=pathToFood.front();
            return;
        }
        //由于最后可能剩下两个位置吃不完 所以直接吃掉food    组后会剩下一个位置 但是蛇无法移动
        if(tmpBoard.getSnakePointsSize()==tmpBoard.size()-1){
            this->direc=pathToFood.front();
            return;
        }
        //pathToTail不为空 表示 tmpSnake在直接吃food之后  还能够找到尾部 这个时候可以直接吃food
        tmpSnake.findMaxPathToTail(pathToTail);
        if(!pathToTail.empty()){
            this->direc=pathToFood.front();
            return;
        }
    }
    //上述步骤都失败 这个时候只能跟着尾部移动  直到移动到能够到吃food的位置
    findMaxPathToTail(pathToTail);
    if(!pathToTail.empty()){
        this->direc = pathToTail.front();
        return;
    }
    //上述都失败 不移动
    this->direc = NONE;
//    findMinPathToFood(pathToFood);
//    this->direc=pathToFood.front();
}

void Snake::setDirec(Direction direc) {
    Snake::direc = direc;
}

void Snake::findMinPath(const Pos &from, const Pos &to, std::list<Direction> &path) {
    Point::Type tmpType = board->getPoint(to).type;
    board->getPoint(to).setType(Point::EMPTY);
    path.clear();
    for (int i = 1; i <= board->getRowCnt(); i++) {
        for (int j = 1; j <= board->getColCnt(); j++) {
            board->getPoint(Pos(i, j)).setDist(Point::MAX_VALUE);
        }
    }
    board->getPoint(from).setDist(0);
    queue<Pos> openList;
    openList.push(from);
    while (!openList.empty()) {
        Pos curPos = openList.front();
        Point curPoint = board->getPoint(curPos);
        openList.pop();
        if (curPos == to) {
            Pos tmp = to, parent;
            while (tmp != from) {
                parent = board->getPoint(tmp).getParent();
                Direction direc = parent.getDirectionTo(tmp);
                if (direc != Direction::NONE) {
                    path.push_front(direc);
                }
                tmp = parent;
            }
            break;
        }
        vector<Pos> adjPotions = curPos.getAdjAll();
        for (const Pos adjPos:adjPotions) {
            if (board->isEmpty(adjPos) && board->isInside(adjPos)
                && board->getPoint(adjPos).getDist() == Point::MAX_VALUE) {
                board->getPoint(adjPos).setDist(curPoint.getDist() + 1);
                board->getPoint(adjPos).setParent(curPos);
                openList.push(adjPos);
            }
        }
    }
    //恢复to的point类型
    board->getPoint(to).setType(tmpType);
}

void Snake::findMaxPath(const Pos &from, const Pos &to, std::list<Direction> &path) {
    findMinPath(from, to, path);
}

void Snake::findMinPathToFood(std::list<Direction> &path) {
    findMinPath(getHead(), board->food, path);
}

void Snake::findMaxPathToTail(std::list<Direction> &path) {
    board->getPoint(getTail()).setType(Point::EMPTY);
    findMinPath(getHead(), getTail(), path);
    for (int i = 1; i <= board->getRowCnt(); i++) {
        for (int j = 1; j <= board->getColCnt(); j++) {
            board->getPoint(Pos(i, j)).setVisited(false);
        }
    }
    Pos cur = getHead();
    for (const Direction &direction:path) {
        board->getPoint(cur).setVisited(true);
        cur = cur.getAdj(direction);
    }
    board->getPoint(cur).setVisited(true);
    for (auto it = path.begin(); it != path.end();) {
        if (it == path.begin()) {
            cur = getHead();
        }
        bool extended=false;
        Direction curDirec = *it;
        Pos next = cur.getAdj(curDirec);
        switch (curDirec) {
            case RIGHT:
            case LEFT: {
                Pos curDown = cur.getAdj(DOWN);
                Pos nextDown = next.getAdj(DOWN);
                if (board->isEmptyNotVisited(curDown)
                    && board->isEmptyNotVisited(nextDown)) {
                    it = path.erase(it);
                    it = path.insert(it, UP);
                    it = path.insert(it, curDirec);
                    it = path.insert(it, DOWN);
                    it = path.begin();
                    board->getPoint(curDown).setVisited(true);
                    board->getPoint(nextDown).setVisited(true);
                    extended=true;
                } else {
                    Pos curUp = cur.getAdj(UP);
                    Pos nextUp = next.getAdj(UP);
                    if (board->isEmptyNotVisited(curUp)
                        && board->isEmptyNotVisited(nextUp)) {
                        it = path.erase(it);
                        it = path.insert(it, DOWN);
                        it = path.insert(it, curDirec);
                        it = path.insert(it, UP);
                        it = path.begin();
                        board->getPoint(curUp).setVisited(true);
                        board->getPoint(nextUp).setVisited(true);
                        extended=true;
                    }
                }
            }
                break;
            case UP:
            case DOWN: {
                Pos curLeft = cur.getAdj(LEFT);
                Pos nextLeft = next.getAdj(LEFT);
                if (board->isEmptyNotVisited(curLeft)
                    && board->isEmptyNotVisited(nextLeft)) {
                    it = path.erase(it);
                    it = path.insert(it, RIGHT);
                    it = path.insert(it, curDirec);
                    it = path.insert(it, LEFT);
                    board->getPoint(curLeft).setVisited(true);
                    board->getPoint(nextLeft).setVisited(true);
                    it = path.begin();
                    extended=true;
                } else {
                    Pos curRight = cur.getAdj(RIGHT);
                    Pos nextRight = next.getAdj(RIGHT);
                    if (board->isEmptyNotVisited(curRight)
                        && board->isEmptyNotVisited(nextRight)) {
                        it = path.erase(it);
                        it = path.insert(it, LEFT);
                        it = path.insert(it, curDirec);
                        it = path.insert(it, RIGHT);
                        board->getPoint(curRight).setVisited(true);
                        board->getPoint(nextRight).setVisited(true);
                        it = path.begin();
                        extended=true;
                    }
                }
            }
                break;
            default:
                break;
        }

        if(!extended){
            it++;
            cur=next;
        }
    }
    //恢复tailPoint的属性
    board->getPoint(getTail()).setType(Point::SNAKE_TAIL);
}

bool Snake::isCompleted() const {
    return completed;
}

void Snake::setCompleted(bool completed) {
    Snake::completed = completed;
}

