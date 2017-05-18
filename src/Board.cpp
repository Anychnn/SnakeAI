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

Board::Board(const int rowCnt_,const int colCnt):content(rowCnt_,vector<Point>(colCnt)) {
    for(int i=0;i<rowCnt_;i++){
        for(int j=0;j<colCnt;j++){
            Point point;
            point.setType(Point::Type::EMPTY);
            content[i][j]=point;
        }
    }
}


Board::~Board() {

}

Point Board::getPoint(const Pos &pos) {
    return content[pos.getX()][pos.getY()];
}

void Board::setPointType(const Pos &pos, Point::Type type) {
    getPoint(pos).setType(type);
}
