注意，以下程序虽然和[c.pdl](./c.pdl)很相似，但无法通过！（获得Wrong Answer）

```pdl
#input
	n of int in [1,100];
	a of (int in [1, 1000])[1~n][1~n];

#required
	r of (int in [1,n])[0~n];
	r[0] = 1;
	r[n] = n;
	ans = summation [a[r[i]][r[i+1]] : forall i];

#objective
	minimize ans;
```

这是因为设置了中间变量，让程序“看起来”不一样了，使得PDL用另外一种有bug的方式优化。

---

另外，树洞上有人提示，TLE是因为多了一行`alldiff`。