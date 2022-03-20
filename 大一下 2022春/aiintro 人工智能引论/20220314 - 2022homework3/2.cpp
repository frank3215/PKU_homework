// 2:Super Star  2022homework3  http://aiintro.openjudge.cn/2022hw3/2/
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
using namespace std;

const int maxn = 110, MX = 10005;
const double inf = 1e10, eps = 1e-7, factor = 0.98, pi = acos(-1.0);

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

double solve() {
	double xx = 0, yy = 0, zz = 0, step = 200;
	while (step > eps) {
		int k = -1;
		double tmp, mx = 0;
		for (int i = 0; i < n; ++i) {
			if ((tmp = sqrt(sqr(xx-x[i]) + sqr(yy-y[i]) + sqr(zz-z[i]))) > mx) {
				mx = tmp;
				k = i;
			}
		}
		xx += (x[k]-xx) / mx * step;
		yy += (y[k]-yy) / mx * step;
		zz += (z[k]-zz) / mx * step;
		step *= factor;
	}
	return calc(xx, yy, zz);
}

int main() {
	cout << fixed << setprecision(5);
	while ((cin >> n) && n) {
		for (int i = 0; i < n; ++i) {
			scanf("%lf%lf%lf", x+i, y+i, z+i);
		}
		printf("%.5f\n", solve());
	}
}
