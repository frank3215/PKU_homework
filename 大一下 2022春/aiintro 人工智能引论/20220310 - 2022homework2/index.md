距离函数
$$
f(x,y) = \sum_k d_i(x,y) = \sum_k \sqrt{(x-x_i)^2+(y-y_i)^2}
$$
其中 $d_i(x,y)$ 表示 $(x,y)$ 与 $(x_i, y_i)$ 之间的距离，求它的偏导：
$$
\frac{\partial f(x,y)}{\partial x} = \frac{x-x_i}{\sqrt{(x-x_i)^2+(y-y_i)^2}}
$$
$y$同理。