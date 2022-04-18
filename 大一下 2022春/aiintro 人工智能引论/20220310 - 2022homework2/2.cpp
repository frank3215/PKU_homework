// 2:A Star not a Tree? 2022homework2 http://aiintro.openjudge.cn/2022hw2/2/
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

const int maxn = 110, loops = 10000;
const double step = 0.01, inf = 1e10, eps = 1e-5;

int n, x[maxn], y[maxn];
double xx, yy;

void norm(double &d) {
	d = min(d, inf);
	d = max(d, -inf);
}

void solve() {
	for (int i = 0; i < loops; ++i) {
		double dx = 0, dy = 0, d;
		for (int i = 0; i < n; ++i) {
			double tmp = sqrt((xx - x[i]) * (xx - x[i]) + (yy - y[i]) * (yy - y[i]));
			if (tmp < eps) continue;
			dx += (xx - x[i]) / tmp;
			dy += (yy - y[i]) / tmp;
		}
		norm(dx), norm(dy);
		if (abs(dx) < eps && abs(dy) < eps) break;
		d = sqrt(dx*dx + dy*dy);
		dx /= d;
		dy /= d;
		xx -= dx*step;
		yy -= dy*step;
	}
}

void out() {
	double ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += sqrt((xx - x[i]) * (xx - x[i]) + (yy - y[i]) * (yy - y[i]));
	}
	int ians = round(ans);
	printf("%d\n", ians);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
		xx += x[i];
		yy += y[i];
	}
	xx /= n, yy /= n; // 从重心开始搜索（答案通常在重心附近）
	solve();
	out();
}
