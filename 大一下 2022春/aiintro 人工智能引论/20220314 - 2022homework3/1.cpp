// 1:Run Away  2022homework3  http://aiintro.openjudge.cn/2022hw3/1/
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

const int maxn = 1010, MX = 10005;
const double inf = 1e10, eps = 1e-3, factor = 0.95, pi = acos(-1.0);

int n, X, Y, x[maxn], y[maxn];

double calc(double xx, double yy) {
	double res = inf;
	for (int i = 0; i < n; ++i) {
		res = min(res, hypot(xx-x[i], yy-y[i]));
	}
	return res;
}

void norm(double &xx, double &yy) {
	xx = max(0.0, min(xx, (double)X));
	yy = max(0.0, min(yy, (double)Y));
}

double solve(double &xx, double &yy) {
	double T = max(X, Y)/10.0, step = max(X, Y);
	xx = X/2.0, yy = Y/2.0;
	// double xx = 1582.4, yy = 1582.4;
	double dis = calc(xx, yy);
	while (T > eps) {
		double theta = rand() / (double)RAND_MAX * 2.0 * pi;
		double nx = xx + cos(theta) * step, ny = yy + sin(theta) * step;
		norm(nx, ny);
		double ndis = calc(nx, ny);
		double tmp = exp((ndis-dis)/T);
		if (ndis > dis || tmp * RAND_MAX > rand()) {
			xx = nx, yy = ny, dis = ndis;
		}
		T *= factor;
		step *= factor;
	}
	return dis;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> X >> Y >> n;
		for (int i = 0; i < n; ++i) {
			cin >> x[i] >> y[i];
		}
		double ansx = 0, ansy = 0, xx, yy, dis = 0;
		for (int i = 0; i < 100; ++i) {
			double ndis = solve(xx, yy);
			if (ndis > dis) {
				ansx = xx;
				ansy = yy;
				dis = ndis;
			}
		}
		printf("The safest point is (%.1f, %.1f).\n", ansx, ansy);
	}
}
