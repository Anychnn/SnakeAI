#include <iostream>
#include "Draw.h"
const GLfloat Pi = 3.1415926536f;
const GLfloat unitOne = 1 / boardSize;
using namespace std;

//int random(int begin, int end) {
//	return begin + (end - begin)*rand() / (RAND_MAX );
//}
void Draw::DrawGrid() {
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	float temp = -1;
	for (int i = 0; i < boardSize*2-1; i++) {
		temp += 1 / boardSize;
		glVertex2f(temp, 1); 
		glVertex2f(temp, -1);

		glVertex2d(-1, temp);
		glVertex2d(1, temp);
	}
	glEnd();
}

void Draw::DrawFood(Food* food) {
	//游戏已经结束 不再画food
	if (food->pos.x == -1 || food->pos.y == -1) {
		return;
	}
	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	int dotCount = 100;
	for (int i = 0; i < 100; i++) {
		glVertex2f(food->pos.x*unitOne+unitOne / 2 -1+unitOne/2*cos(2 * Pi / dotCount*i), food->pos.y*unitOne + unitOne / 2-1+unitOne / 2 *sin(2 * Pi / dotCount*i));
	}
	glEnd();
}

void Draw::DrawSnake(Snake * snake) {
	int size = snake->body.size();
	glBegin(GL_TRIANGLES);
	structPos pos = snake->body.at(0);
	if (snake->direction == Snake::up) {
		glVertex2f(-1 + (pos.x ) / boardSize, -1 + (pos.y ) / boardSize);
		glVertex2f(-1 + (pos.x+1) / boardSize, -1 + (pos.y ) / boardSize);
		glVertex2f(-1 + (pos.x + 0.5) / (boardSize), -1 + (pos.y+1) / boardSize);
	}else if (snake->direction == Snake::down) {
		glVertex2f(-1 + (pos.x ) / boardSize, -1 + (pos.y+1) / boardSize);
		glVertex2f(-1 + (pos.x+1) / boardSize, -1 + (pos.y+1) / boardSize);
		glVertex2f(-1 + (pos.x + 0.5) / (boardSize), -1 + (pos.y) / boardSize);
	}
	else if (snake->direction == Snake::left) {
		glVertex2f(-1 + (pos.x ) / boardSize, -1 + (pos.y + 0.5) / boardSize);
		glVertex2f(-1 + (pos.x+1) / boardSize, -1 + (pos.y ) / boardSize);
		glVertex2f(-1 + (pos.x+1) / (boardSize), -1 + (pos.y+1) / boardSize);
	}
	else if (snake->direction == Snake::right) {
		glVertex2f(-1 + (pos.x ) / boardSize, -1 + (pos.y ) / boardSize);
		glVertex2f(-1 + (pos.x ) / boardSize, -1 + (pos.y+1) / boardSize);
		glVertex2f(-1 + (pos.x+1) / boardSize, -1 + (pos.y + 0.5) / boardSize);
	}
	glEnd();
	glColor3f(0, 0, 0);
	for (int i = 1; i < size; i++) {
		structPos pos = snake->body.at(i);
		glRectf(-1 + (pos.x+1) / boardSize, -1 + (pos.y+1) / boardSize, -1 + (pos.x) / boardSize, -1 + (pos.y) / boardSize);
	}
	
	glEnd();
	
	glFlush();
}