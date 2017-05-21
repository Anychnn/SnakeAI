"# SnakeAI" 

界面基于OpenGl

待完善：
1. 使用A*寻路算法代替BFS，BFS并不是最优路径，有可能绕远路


目前算法BFS图搜索，如下步骤：
1. 寻找snake到food的最短路径
2. 如果找到，尝试用snake的拷贝去吃food
3. 如果吃了food后 还能够找到通往snake尾部的路径，就直接通过最短路径吃food
4. 上述无法通过，走通往尾部的最大路径，即hailton回路
