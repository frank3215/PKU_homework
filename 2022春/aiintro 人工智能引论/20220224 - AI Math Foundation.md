# AI Math Foundation - 2022.2.24

## 1. 简答课前测，字数不限。

### 1) 如何分析一个解决问题的方法的好坏？How to measure the performance of a method corresponding to a given problem？

1. 复杂度。
   1. 对于确定性算法而言，复杂度是较好的衡量标准。
   2. 然而，有时候复杂度更劣的算法可能在硬件上跑得更快。如普通的$O(n^3)$矩阵乘法可能比$O(n^{\log_2{7}})$的Strassen算法更快。此时应该以在硬件上的实际运行速度作为衡量标准。
2. 与最优解的接近程度。
   1. 对于$90\%$和$80\%$接近最优解的算法，明显是前者更优。
   2. 复杂度、轮数、与正确性的关系。有一些$O(n)$近似算法能够保证跑$O(T)$轮后的值是最优解的$(1-(\frac{1}{2})^T)$，有一些则是$(1-(\frac{1}{2})^{\log T})$之类。此时前者更优。此时可能各个算法各有所长，不能严格说哪个更优或更劣。
3. 实际测试结果。
   1. 对于爬山算法、退火算法等效果与数据集关系很大的算法，难以进行理论分析，应该以实际运行效果的优劣来衡量。

### 2) 何为变量间的线性关系？非线性关系？“鸡兔同笼”问题如何求解？ What are Linear and Nonlinear relationships between variables？ How to solve the problem of Chicken and rabbit in the same cage ？

1. 线性关系：若两个变量$x,y$能近似地表示成$y=kx+b$的形式，我们称它们有线性关系。
   1. 在实际场景中，我们通过相关系数（correlation coefficient）来确定两个变量能否成线性关系。
2. 非线性关系：若两个变量$x,y$不能表示成线性关系，称它们有非线性关系。

### 3) 试举出 2 个具有不确定性特点的 Agent 任务场景的例子。 Please give two examples of uncertain/stochastic task environment.

1. 飞行棋。此时不确定性来自骰子结果的无法预知。
2. 自动驾驶。此时不确定性来自对环境（尤其是其它驾驶员）的不完全知识。

### 4) 随机现象(不确定现象)往往还是有规律的，你认为怎样去刻画这些规律？ Random phenomena often have laws. How do you think to characterize these laws？

1. 用统计方式去刻画。我们可以通过概率分布曲线来刻画不同情况出现的概率。例子：玻尔兹曼分布。

### 5) 一个工厂生产了一批新口罩，声称能防病毒，你认为应如何科学判断？ A factory has produced a batch of new masks that claim to be anti -virus. How do you think to judge scientifically？

1. 我们可以通过查阅相关文献，了解口罩防病毒的原理与这个工厂口罩的生产方式来从理论上推测这批口罩的效果。
2. 我们可以通过控制变量，通过实际测试来判断实际效果。
   1. 更具体地，我们用在空气中呈不同浓度的不同病毒，将口罩贴于仿真人脸上，用气泵模拟呼吸，收集通过口罩后的空气后测定病毒浓度。
   2. 我们将有口罩的结果和没口罩的结果进行对比。我们可以更进一步，将这个工厂的口罩与其他工厂的口罩进行对比。

## 2. 袋中有 10 个小球, 4 红 6 绿. 每次任取一只, 不放回地连取 3 次. 求下列事件的概率: A: 3 只都是绿球, B: 2 红 1 绿. 注：参照课堂例题，这里要求的抽样是“不放回”情形。

1. $P(3绿)=\frac{6}{10}\times\frac{5}{9}\times\frac{4}{8}=\frac{120}{720}=\frac{1}{6}$。
2. $P(2红1绿)={3\choose 2}\frac{4\times 3\times 6}{10\times 9\times 8}=\frac{72\times 3}{720}=\frac{3}{10}$。
