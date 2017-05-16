//
// Created by Administrator on 2017/5/13.
//

#ifndef SNAKEAI_GAMECTRL_H
#define SNAKEAI_GAMECTRL_H


#include <mingw.thread.h>
#include <mingw.mutex.h>
#include "model/Map.h"
#include "model/Point.h"
#include "model/Snake.h"

class GameCtrl {
public:
    typedef Map::SizeType SizeType;
    static const Point::ValueType  EMPTY_VALUE=99999;
    ~GameCtrl();
    static GameCtrl* getInstance();

    void setFPS(const double fps_);
    void setEnableAI(const bool enableAI_);
    void setEnableHamilton(const bool enableHamilton_);
    void setMoveInterval(const long ms);
    void setRecordMovements(const bool b);
    void setRunTest(const bool b);
    void setMapRow(const SizeType n);
    void setMapCol(const SizeType n);
    int run();
private:
    static const std::string MSG_BAD_ALLOC;
    static const std::string MSG_LOSE;
    static const std::string MSG_WIN;
    static const std::string MSG_ESC;
    static const std::string MAP_INFO_FILENAME;
    double fps=60.0;
    bool enableAI=true;
    bool enableHamilton=true;
    long moveInterval=30;
    bool recordMovements=true;
    bool runTest=false;
    SizeType  mapRowCount=10;
    SizeType  mapColCount=10;
    Map *map= nullptr;
    Snake snake;
    volatile bool pause=false;
    volatile bool runMainThread=true;
    volatile bool runSubThread=true;
    std::thread drawThread;
    std::thread keyboardThread;
    std::thread moveThread;

    std::mutex mutexMove;
    std::mutex mutexExit;

    FILE *movementFile= nullptr;

    GameCtrl();

    void sleepFPS() const;
    void exitGame(const std::string &msg);

    void exitGameErr(const std::string &msg);

    void printMsg(const std::string &msg);
    void moveSnake();

    void writeMapToFile()const;
    void init();
    void initMap();
    void initSnake();
    void initFiles();
    void startThreads();

    void draw();
    void drawMapContent() const;
    void drawTestPoint(const Point &p,const ConsoleColor &consoleColor) const;

    void keyboard();
    void keyboardMove(Snake &s,const Direction d);

    void autoMove();

    void test();
    void testFood();
    void testSearch();
    void testHamilton();
};



#endif //SNAKEAI_GAMECTRL_H
