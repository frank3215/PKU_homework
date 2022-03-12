// 2:Sudoku
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <iostream>
#define cl(x) memset(x, 0, sizeof(x))

using namespace std;

const int full = (1<<9)-1;

int a[9][9], r[9], c[9], e[9];
int popcnt[1<<9], lg[1<<9];


inline int cell(int i, int j) {
	return (i/3)*3+(j/3);
}

void update(int x, int y, int i) {
	// printf("%d %d %d\n", x, y, i);
	r[x] ^= 1<<i;
	c[y] ^= 1<<i;
	e[cell(x,y)] ^= 1<<i;
}

bool dfs(int level = 0) {
	int x = 0, y = 0, mn = -1;
	for (int i = 0; i < 9; ++i)
		for (int j = 0; j < 9; ++j) {
			// cout << i << j << endl;
			if (a[i][j] == 0) {
				// cout << r[i] << " " << c[j] << " " << e[cell(i,j)] << endl;
				int cnt = popcnt[r[i]|c[j]|e[cell(i,j)]];
				// cout << 1 << endl;
				if (cnt == 9) return false;
				// cout << 1 << endl;
				if (cnt > mn) {
					mn = cnt;
					x = i, y = j;
				}
				// cout << 1 << endl;
			}
		}
	// printf("%d %d %d %d\n", level, x, y, mn);
	if (mn == -1) return true;
	int mask = r[x]|c[y]|e[cell(x,y)];
	for (int i = 0; i < 9; ++i) {
		if ((mask & (1<<i)) == 0) {
			a[x][y] = i+1;
			update(x, y, i);
			if (dfs(level+1)) return true;
			a[x][y] = 0;
			update(x, y, i);
		}
	}
	return false;
}

void solve() {
	cl(r), cl(c), cl(e);
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			char c;
			cin >> c;
			a[i][j] = c-'0';
			if (a[i][j]) update(i, j, a[i][j]-1);
		}
	}
	// cout << "Start!" << endl;
	dfs();
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			cout << a[i][j];
		}
		cout << endl;
	}
}

int main() {
	int t;
	cin >> t;
	lg[0] = -1;
	for (int i = 1; i < (1<<9); ++i) {
		popcnt[i] = popcnt[i>>1] + (i&1);
		lg[i] = lg[i>>1] + 1;
	}
	while (t--) solve();
}
