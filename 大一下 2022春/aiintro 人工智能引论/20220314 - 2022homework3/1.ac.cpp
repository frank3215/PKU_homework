// 1:Run Away  2022homework3  http://aiintro.openjudge.cn/2022hw3/1/
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

const int maxn = 1010, MX = 10005;
const double inf = 1e10, eps = 1e-3, factor = 0.99, pi = acos(-1.0);

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

void solve(double &xx, double &yy) {
	double T = max(X, Y)/10.0, step = max(X, Y);
	xx = X/2.0, yy = Y/2.0;
	// double xx = 1582.4, yy = 1582.4;
	double dis = calc(xx, yy);
	while (T > eps) {
		double theta = rand() / (double)RAND_MAX * 2.0 * pi;
		double nx = xx + cos(theta) * step, ny = yy + sin(theta) * step;
		// double nx = 1433.0, ny = 1669.8;
		norm(nx, ny);
		double ndis = calc(nx, ny);
		double tmp = exp((ndis-dis)/T);
		if (ndis > dis || tmp * RAND_MAX > rand()) {
			// printf("(%.1f, %.1f) %.1f ->(%.1f)-> (%.1f, %.1f) %.1f\n", xx, yy, dis, tmp, nx, ny, ndis);
			xx = nx, yy = ny, dis = ndis;
		}
		T *= factor;
		step *= factor;
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> X >> Y >> n;
		for (int i = 0; i < n; ++i) {
			cin >> x[i] >> y[i];
		}
		double ansx = 0, ansy = 0, xx, yy;
		for (int i = 0; i < 100; ++i) {
			solve(xx, yy);
			// printf("(%.1f, %.1f) %.1f ->(%.1f)-> (%.1f, %.1f) %.1f\n", xx, yy, calc(xx, yy), 0.0, ansx, ansy, calc(ansx, ansy));
			if (calc(xx, yy) > calc(ansx, ansy)) {
				ansx = xx;
				ansy = yy;
			}
		}
		printf("The safest point is (%.1f, %.1f).\n", ansx, ansy);
	}
}
