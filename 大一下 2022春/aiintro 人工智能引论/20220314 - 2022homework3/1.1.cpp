// 1:Run Away  2022homework3  http://aiintro.openjudge.cn/2022hw3/1/
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

const int maxn = 110, MX = 10005;
const double inf = 1e10, eps = 1e-7, factor = 0.9, pi = acos(-1.0);

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
	yy = max(0.0, min(xx, (double)Y));
}

void solve() {
	srand(time(NULL));
	cin >> X >> Y >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
	}
	double T = MX/1000, step = MX;
	double xx = X/2.0, yy = Y/2.0;
	double dis = calc(xx, yy);
	while (T > eps) {
		printf("(%.1f, %.1f) %.1f\n", xx, yy, dis);
		double theta = rand() / (double)RAND_MAX * 2 * pi;
		double nx = xx + cos(theta) * step, ny = yy + cos(theta) * step;
		norm(nx, ny);
		double ndis = calc(nx, ny);
		if (ndis > dis || exp((dis-ndis)/T) * RAND_MAX > rand())
			xx = nx, yy = ny, dis = ndis;
		T *= factor;
		step *= factor;
	}
	printf("The safest point is (%.1f, %.1f).\n", xx, yy);
}

int main() {
	int t;
	cin >> t;
	while (t--) solve();
}
