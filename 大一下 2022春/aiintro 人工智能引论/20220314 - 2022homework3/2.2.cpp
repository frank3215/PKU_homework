// 2:Super Star  2022homework3  http://aiintro.openjudge.cn/2022hw3/2/
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
using namespace std;

const int maxn = 110, MX = 10005;
const double inf = 1e10, eps = 1e-7, factor = 0.95, pi = acos(-1.0);

int n, X, Y;

double x[maxn], y[maxn], z[maxn];

inline double sqr(double x) { return x * x; }

double calc(double xx, double yy, double zz) {
	double res = 0;
	for (int i = 0; i < n; ++i) {
		res = max(res, sqrt(sqr(xx-x[i]) + sqr(yy-y[i]) + sqr(zz-z[i])));
	}
	return res;
}

double solvey(double xx, double yy) {
	double l = 0, r = 100;
	while (r-l > eps) {
		double lr = (2*l + r)/3, rl = (l + 2*r)/3;
		if (calc(xx, yy, lr) > calc(xx, yy, rl)) l = lr;
		else r = rl;
	}
	return calc(xx, yy, l);
}

double solvex(double xx) {
	double l = 0, r = 100;
	while (r-l > eps) {
		double lr = (2*l + r)/3, rl = (l + 2*r)/3;
		if (solvey(xx, lr) > solvey(xx, rl)) l = lr;
		else r = rl;
	}
	return solvey(xx, l);
}

double solve() {
	double l = 0, r = 100;
	while (r-l > eps) {
		double lr = (2*l + r)/3, rl = (l + 2*r)/3;
		if (solvex(lr) > solvex(rl)) l = lr;
		else r = rl;
	}
	return solvex(l);
}


int main() {
	cout << fixed << setprecision(5);
	while ((cin >> n) && n) {
		for (int i = 0; i < n; ++i) {
			scanf("%lf%lf%lf", x+i, y+i, z+i);
		}
		printf("%.5f\n", solve());
		// cout << solve() << endl;
		// printf("%.5f\n", solve());
	}
}
