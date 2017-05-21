//
// Created by Administrator on 2017/5/18.
//

#ifndef SNAKEAI_SNAKEMANAGER_H
#define SNAKEAI_SNAKEMANAGER_H

#include <windows.h>
#include <glut.h>
#include "Snake.h"
#include "Board.h"
#include <thread>
#include <mingw.thread.h>

class SnakeManager {
public:
    SnakeManager();

    int getInterval() const;
    void setInterval(int interval);

    void setRowCount(int rowCount);
    void setColCount(int colCount);
    int getRowCount() const;
    int getColCount() const;
    void init(int * argc,char ** argv);
    void startGame();
    void drawFood(Pos &food);
    void drawMap();
    void draw();
    void initSnake();
    void initBoard();
public:
    Snake snake;
    Board *board= nullptr;
private:
    int rowCount=4;
    int colCount=4;
    int interval=200;
};


#endif //SNAKEAI_SNAKEMANAGER_H
