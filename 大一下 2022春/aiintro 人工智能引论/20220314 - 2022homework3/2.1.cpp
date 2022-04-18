// 2:Super Star  2022homework3  http://aiintro.openjudge.cn/2022hw3/2/
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
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

inline double myrand() {
	return (rand()/(double)RAND_MAX);
}

void solve(double &xx, double &yy, double &zz) {
	double T = 100.0, step = 100.0;
	xx = yy = zz = 0;
	double dis = calc(xx, yy, zz);
	while (step > eps) {
		double nx = xx + myrand()*step, ny = yy + myrand() * step, nz = zz + myrand() * step;
		double ndis = calc(nx, ny, nz);
		// printf("(%.5f %.5f %.5f) %.5f &", xx, yy, zz, dis);
		// printf("(%.5f %.5f %.5f) %.5f\n", nx, ny, nz, ndis);
		if (ndis < dis) {
			xx = nx, yy = ny, zz = nz, dis = ndis;
		}
		T *= factor;
		step *= factor;
	}
}

int main() {
	while ((cin >> n) && n) {
		for (int i = 0; i < n; ++i) {
			cin >> x[i] >> y[i] >> z[i];
		}
		double ansx = 0, ansy = 0, ansz = 0, xx, yy, zz;
		for (int i = 0; i < 100; ++i) {
			solve(xx, yy, zz);
			if (calc(xx, yy, zz) < calc(ansx, ansy, ansz)) {
				ansx = xx;
				ansy = yy;
				ansz = zz;
			}
		}
		printf("%.5f\n", calc(xx, yy, zz));
	}
}
