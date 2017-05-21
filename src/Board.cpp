#include <util.h>
#include <iostream>
#include "Board.h"

//int random(int begin, int end) {
//	return begin + (end - begin)*rand() / (RAND_MAX);
//}
//structPos Board::createFood(Snake* snake) {
//	if (snake->win) {
//		return structPos(-1,-1);
//	}
//	structPos pos(random(0, boardSize*2), random(0, boardSize * 2));
//	vector<vector<int>> boardXY;
//	for (int i = 0; i < 2*boardSize; i++) {
//		boardXY.push_back(vector<int>(2*boardSize,0));
//	}
//	for (int i = 0; i < snake->body.size(); i++) {
//		boardXY[snake->body.at(i).x][snake->body.at(i).y] = 1;
//	}
//	for (vector<structPos>::const_iterator it = snake->body.begin(); it != snake->body.end();it++) {
//		boardXY[(*it).x][(*it).y] = 1;
//	}
//	vector<structPos> availablePositions;
//	for (int i = 0; i < 2*boardSize; i++) {
//		for (int j = 0; j < 2*boardSize; j++) {
//			if (boardXY[i][j] == 0) {
//				availablePositions.push_back(structPos(i, j));
//			}
//		}
//	}
//	int index = random(0, availablePositions.size());
//	return availablePositions.at(index);
//	/*cout << pos.x << endl;;
//	cout << pos.y << endl;*/
//	//return pos;
//}

Board::Board(const int rowCnt_, const int colCnt) : content(rowCnt_, vector<Point>(colCnt)) {
    for (int i = 0; i < rowCnt_; i++) {
        for (int j = 0; j < colCnt; j++) {
            Pos pos(i + 1, j + 1);
            Point point(pos);
            if (i == 0 || j == 0 || i == rowCnt_ - 1 || j == colCnt - 1) {
                point.setType(Point::WALL);
            } else {
                point.setType(Point::Type::EMPTY);
            }
            content[i][j] = point;
        }
    }
}


Board::~Board() {

}

Point &Board::getPoint(const Pos &pos) {
    return content[pos.getX() - 1][pos.getY() - 1];
}

void Board::setPointType(const Pos &pos, Point::Type type) {
    getPoint(pos).setType(type);
}

void Board::createRandomFood() {
    vector<Pos> emptyPoints = getEmptyPoints();
    auto random = util::Random<>::getInstance();
    if (!emptyPoints.empty()) {
        int i = random->nextInt(0, emptyPoints.size() - 1);
        setPointType(emptyPoints[i], Point::FOOD);
        Pos foodPos = emptyPoints[i];
        food = foodPos;
    }
}

vector<Pos> Board::getEmptyPoints() {
    vector<Pos> emptyPoints;
    int rowCnt = getRowCnt(), colCnt = getColCnt();
    for (int i = 0; i < rowCnt; i++) {
        for (int j = 0; j < colCnt; j++) {
            if (content[i][j].type == Point::EMPTY) {
                emptyPoints.push_back(content[i][j].pos);
            }
        }
    }
    return emptyPoints;
}

int Board::getRowCnt() const {
    return content.size();
}

int Board::getColCnt() const {
    return content[0].size();
}

bool Board::isEmpty(const Pos &pos) {
    return getPoint(pos).type == Point::EMPTY||isFood(pos);
}

bool Board::isInside(const Pos &pos) {
    return !(pos.getX() == 1
             || pos.getY() == 1
             || pos.getX() == getColCnt()
             || pos.getY() == getRowCnt());
}

void Board::createFood(Pos &foodPos) {
    food = foodPos;
}

void Board::removeFood() {
    if (hasFood()) {
        getPoint(food).setType(Point::Type::EMPTY);
    }
}

bool Board::hasFood() {
    return getPoint(food).type == Point::FOOD;
}

bool Board::isEmptyNotVisited(const Pos &pos) {
    return isEmpty(pos) && getPoint(pos).visited == false && isInside(pos);

}

bool Board::isFood(const Pos &pos) {
    return getPoint(pos).type==Point::FOOD;
}

bool Board::isAllBody() {
    for (int i = 1; i <= getRowCnt(); i++) {
        for (int j = 1; j <= getColCnt(); j++) {
            Point p=getPoint(Pos(i,j));
            if(p.type==Point::EMPTY){
                return false;
            }
        }
    }
    return true;
}

int Board::size() {
    int size=(getRowCnt()-2)*(getColCnt()-2);
    return size;
}

int Board::getSnakePointsSize() {
    int size=0;
    for (int i = 1; i <= getRowCnt(); i++) {
        for (int j = 1; j <= getColCnt(); j++) {
            Point p=getPoint(Pos(i,j));
            if(p.type==Point::SNAKE_HEAD||
                    p.type==Point::SNAKE_BODY||
                    p.type==Point::SNAKE_TAIL){
                size++;
            }
        }
    }
    return size;
}
