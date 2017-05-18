//
// Created by Administrator on 2017/5/18.
//

#include <iostream>
#include <util.h>
#include "SnakeManager.h"

SnakeManager *snakeManager;
SnakeManager::SnakeManager() {

}

void paint() {
    glClearColor(0.96, 0.96, 0.863, 1.0);//000黑色,111白色
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

void reshape(int x, int y) {
}

void intervalProc(int id) {
    std::cout << "interval" << std::endl;
    glutTimerFunc(snakeManager->getInterval(), intervalProc, 1);
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
    glutDisplayFunc(paint);//显示绘制图形
    glutKeyboardFunc(KeyDown);
    glutSpecialFunc(SpecialKeyDown);
}
void SnakeManager::startGame() {
    board=new Board(this->rowCount,this->colCount);
    initSnake();
    glutTimerFunc(getInterval(), intervalProc, 1);
    glutMainLoop();//循环
}

void SnakeManager::initSnake() {
    snake.setBoard(board);
    snake.addBody(Pos(1,1));
    snake.addBody(Pos(1,2));
    snake.addBody(Pos(1,3));
}


