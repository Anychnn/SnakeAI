#include <windows.h>
#include <glut.h>
#include <iostream>
#include <cstdlib>
#include <SnakeManager.h>

using namespace std;

int main(int argc, char ** argv) {
	SnakeManager snakeManager;
	snakeManager.init(&argc,argv);
    //����ˢ��Ƶ��
    snakeManager.setInterval(1000);
    //���õ�ͼ��С
    snakeManager.setRowCount(10);
    snakeManager.setColCount(10);

	snakeManager.startGame();
	system("pause");
	return(0);
}
