//
// Created by Administrator on 2017/5/18.
//

#include <iostream>
#include <util.h>
#include <iostream>
#include "SnakeManager.h"

SnakeManager *snakeManager;
const GLfloat Pi = 3.1415926536f;
const int dotCount = 100;
std::list<Direction> path;
SnakeManager::SnakeManager() {

}

void drawBackGround() {
    glClearColor(0.96, 0.96, 0.863, 1.0);//000黑色,111白色
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
    glutSwapBuffers();
}

void reshape(int x, int y) {
}
void paint(){
    snakeManager->draw();
}

void intervalProc(int id) {
    if(!snakeManager->snake.isDead()){
        snakeManager->snake.decideNext();
        snakeManager->snake.move();
        if(!snakeManager->board->hasFood()){
            snakeManager->board->createRandomFood();
        }
        if(snakeManager->board->isAllBody()){
            std::cout<<"completed!!!"<<std::endl;
        }
        snakeManager->draw();
        glutTimerFunc(snakeManager->getInterval(), intervalProc, 1);
    }else{
        snakeManager->draw();
        snakeManager->initBoard();
        snakeManager->initSnake();
        glutTimerFunc(4000, intervalProc, 1);
    }
}

void KeyDown(unsigned char key, int x, int y) {

}

void SpecialKeyDown(int key, int x, int y) {

}

int SnakeManager::getInterval() const {
    return interval;
}

void SnakeManager::setInterval(int interval) {
    SnakeManager::interval = interval;
}

void SnakeManager::setRowCount(int rowCount) {
    SnakeManager::rowCount = rowCount;
}

void SnakeManager::setColCount(int colCount) {
    SnakeManager::colCount = colCount;
}

void SnakeManager::init(int *argc, char **argv) {
    snakeManager = this;
    glutInit(argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE); //设置显示方式
    //glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);//双缓冲、RGB模式
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Gluttonous Snake");//窗口标题
    glShadeModel(GL_SMOOTH);//设置为光滑明暗模式
    /*绘制与显示*/
    glutReshapeFunc(reshape);//窗口大小发生改变时采取的行为
    glutDisplayFunc(drawBackGround);//显示绘制图形
    glutKeyboardFunc(KeyDown);
    glutSpecialFunc(SpecialKeyDown);
}

void SnakeManager::startGame() {
    initBoard();
    initSnake();
    glutDisplayFunc(paint);
    glutTimerFunc(getInterval(), intervalProc, 1);
    glutMainLoop();//循环
}
void SnakeManager::initBoard() {
    board = new Board(this->rowCount, this->colCount);
}
void SnakeManager::initSnake() {
    this->snake=Snake();
    snake.setDead(false);
    snake.setBoard(board);
    snake.addBody(Pos(4, 2));
    snake.addBody(Pos(3, 2));
    snake.addBody(Pos(2, 2));
    board->createRandomFood();
    snake.findMinPathToFood(path);
}


void SnakeManager::draw() {
    drawBackGround();
    drawMap();
//    Direction right=Direction ::RIGHT;
//    snake.move(right);
}

void SnakeManager::drawMap() {
    using namespace util;
    for (int i = 1; i <= rowCount; i++) {
        for (int j = 1; j <= colCount; j++) {
            Point point = board->getPoint(Pos(i, j));
            switch (point.type) {
                case Point::EMPTY:
                    break;
                case Point::WALL:
                    glColor3f(0.8, 0.8, 0.8);
                    glRectf(coordinateXConversion(point.getX(), colCount),
                            coordinateYConversion(point.getY(), rowCount),
                            coordinateXConversion(point.getX() + 1, colCount),
                            coordinateYConversion(point.getY() + 1, rowCount));
                    glEnd();
                    break;
                case Point::SNAKE_HEAD:
                    glColor3f(1, 0, 0);
                    glRectf(coordinateXConversion(point.getX(), colCount),
                            coordinateYConversion(point.getY(), rowCount),
                            coordinateXConversion(point.getX() + 1, colCount),
                            coordinateYConversion(point.getY() + 1, rowCount));
                    glEnd();
                    break;
                case Point::SNAKE_BODY:
                    glColor3f(0, 0, 0);
                    glRectf(coordinateXConversion(point.getX(), colCount),
                            coordinateYConversion(point.getY(), rowCount),
                            coordinateXConversion(point.getX() + 1, colCount),
                            coordinateYConversion(point.getY() + 1, rowCount));
                    glEnd();
                    break;
                case Point::SNAKE_TAIL:
                    glColor3f(0, 1, 0);
                    glRectf(coordinateXConversion(point.getX(), colCount),
                            coordinateYConversion(point.getY(), rowCount),
                            coordinateXConversion(point.getX() + 1, colCount),
                            coordinateYConversion(point.getY() + 1, rowCount));
                    glEnd();
                    break;
                case Point::FOOD: {
                    float colR = 1 / (float) colCount;
                    float rowR = 1 / (float) rowCount;
                    glColor3f(0, 0, 1);
                    glBegin(GL_POLYGON);
                    for (int i = 0; i < 100; i++) {
                        glVertex2f(colR-1+2*colR*(point.pos.getX()-1)+colR*cos(2 * Pi / dotCount * i),
                                    rowR-1+2*rowR*(point.pos.getY()-1)+rowR*sin(2 * Pi / dotCount * i));
                    }
                    glEnd();
                }
                    break;
                default:
                    break;
            }
        }
    }
    glFlush();
    glutSwapBuffers();
}


int SnakeManager::getRowCount() const {
    return rowCount;
}

int SnakeManager::getColCount() const {
    return colCount;
}




