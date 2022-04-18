# 作业

> 假设一个计算过程可表达为：
> $$
> \hat{y} = f(x_0,x_1,w_0,w_1,w_2)=\frac{1}{1+e^{-(w_0x_0+w_1x_1+w_2)}}
> L = (\hat{y} - y)^2
> $$
> 请分别给出 a, b, …, s 对应的值，保留 2 位小数精度。

![截屏2022-04-05 20.51.31](/Users/chengefei/Documents/GitHub/PKU_homework/大一下 2022春/aiintro 人工智能引论/20220328 - homework-05/截屏2022-04-05 20.51.31.png)

1. $a = w_0x_0 = 2.00 \times (-1.00) = -2.00$
2. $b = a + 6.00 = 4.00$
3. $c = b + w_2 = 4.00 + (-3.00) = 1.00$
4. $d = c\times(-1) = -1.00$
5. $e = e^d = e^{-1.00} = \frac{1}{e} = 0.37$
6. $f = e + 1 = 1 + \frac{1}{e} = 1.37$
7. $g = \frac{\delta (x+y)}{\delta x}\bigg|_{x = \frac{e}{e + 1}} \times (-0.54) = -0.54$
8. $h = \frac{\delta (1/x)}{\delta x}\bigg |_{x = f} \times g = (-1.53)\times (-0.54) = 0.83$
9. $i = h = 0.83$
10. $j = \frac{\delta(e^x)}{\delta x}\bigg |_{x = d} \times i = e^{-1.00} \times 0.83 = 0.37 \times 0.83 = 0.31$
11. $k = -j = -0.31$
12. $l = k = -0.31$
13. $m = l = -0.31$
14. $n = l = -0.31$
15. $o = x_0m = 0.31$
16. $p = w_0m = 0.62$
17. $q = x_1n = 0.62$
18. $r = w_1n = 0.93$
19. $s = k = -0.31$