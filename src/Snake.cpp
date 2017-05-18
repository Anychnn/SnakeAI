#include "Snake.h"
//Snake::Snake() {
//	structPos pos(boardSize , boardSize);
//	//structPos pos2(boardSize + 2, boardSize + 2);
//	body.push_back(pos);
//	//body.push_back(pos2);
//
//}
//void Snake::move() {
//	int size = body.size();
//	switch (direction)
//	{
//	case up:
//		if (body.at(0).y == boardSize * 2 - 1) {
//			return;
//		}
//		for (int i = size-1; i >=0; i--) {
//			if (i == 0) {
//				body.at(i).y++;
//			}
//			else {
//				body.at(i).x = body.at(i - 1).x;
//				body.at(i).y = body.at(i - 1).y;
//			}
//		}
//		break;
//	case down:
//		if (body.at(0).y == 0) {
//			return;
//		}
//		for (int i = size - 1; i >= 0; i--) {
//			if (i == 0) {
//				body.at(0).y--;
//			}
//			else {
//				body.at(i).x = body.at(i - 1).x;
//				body.at(i).y = body.at(i - 1).y;
//			}
//		}
//		break;
//	case left:
//		if (body.at(0).x == 0) {
//			return;
//		}
//		for (int i = size - 1; i >= 0; i--) {
//			if (i == 0) {
//				body.at(0).x--;
//			}
//			else {
//				body.at(i).x = body.at(i - 1).x;
//				body.at(i).y = body.at(i - 1).y;
//			}
//		}
//		break;
//	case right:
//		if (body.at(0).x == boardSize * 2 - 1) {
//			return;
//		}
//		for (int i = size - 1; i >= 0; i--) {
//			if (i == 0) {
//				body.at(0).x++;
//			}
//			else {
//				body.at(i).x = body.at(i - 1).x;
//				body.at(i).y = body.at(i - 1).y;
//			}
//		}
//		break;
//	default:
//		break;
//	}
//}

void Snake::setBoard(Board *const board) {
    this->board=board;
}

void Snake::addBody(const Pos &pos) {
    bodies.push_back(pos);
    if(bodies.size()==0){
        board->setPointType(pos,Point::SNAKE_HEAD);
    }else{
        board->setPointType(pos,Point::SNAKE_BODY);
    }
    board->setPointType(bodies.front(),Point::SNAKE_TAIL);
}
