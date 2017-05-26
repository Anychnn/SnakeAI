"# SnakeAI" 

Demo:

![SnakeAI](out/snakeBFSAI.gif)

界面基于OpenGl，如果需要编译项目，需要下载Opengl库文件,用cmake文件进行编译


待完善：
1. 使用A*寻路算法代替BFS，BFS并不是最优路径，有可能绕远路


目前算法BFS图搜索，如下步骤：
1. 寻找snake到food的最短路径
2. 如果找到，尝试用snake的拷贝去吃food
3. 如果吃了food后 还能够找到通往snake尾部的路径，就直接通过最短路径吃food
4. 上述无法通过，走通往尾部的最大路径，即hailton回路


发现了一种简单的可以永远吃完的方法:
    比如留出最上面一横行和左边一竖行，在行和列满足要求的情况下，N字形走位，
    可以让hamilton回路沾满所有格子