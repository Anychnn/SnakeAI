#include <windows.h>
#include <glut.h>
#include <iostream>
#include <cstdlib>
#include <SnakeManager.h>

using namespace std;

int main(int argc, char ** argv) {
	SnakeManager snakeManager;
	snakeManager.init(&argc,argv);
    //调整刷新频率
    snakeManager.setInterval(1000);
    //设置地图大小
    snakeManager.setRowCount(10);
    snakeManager.setColCount(10);

	snakeManager.startGame();
	system("pause");
	return(0);
}
