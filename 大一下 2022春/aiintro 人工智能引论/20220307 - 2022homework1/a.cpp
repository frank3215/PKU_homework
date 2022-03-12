// 1:The missionaries and cannibals
#include <cstdio>
#include <algorithm>
#include <queue>
#include <map>
#include <iostream>
#include <cstring>
#define mp make_pair
#define se second
#define fi first

using namespace std;

typedef pair<int,int> pii;
typedef pair<pii, bool> st;

const int N = 200000, inf = 0x3f3f3f3f, P = 100019;

int n, m, tot;
queue<st> q;
int dis[N];
map<st, int> ap;
st state[N];
// map<st, st> pre;

int ax, ay, bx, by;

void send(int i, int j) {
	ax -= i, bx += i;
	ay -= j, by += j;
}

bool check(int x, int y) {
	return x == 0 || x >= y;
}

inline int id(st u) {
	// return (u.fi.fi*667 + u.fi.se*233 + u.se) % P;
	 int &res = ap[u];
	 return res ? res : (state[++tot] = u, res = tot);
}

int cmin(int &u, int v) {
	return v < u ? u = v : u;
}

int main() {
	cin >> m >> n;
	st s = mp(mp(m, m), false), t = mp(mp(0, 0), true);
	q.push(s);
	memset(dis, 0x3f, sizeof(dis));
	dis[id(s)] = 0;
	while (!q.empty()) {
		st u = q.front(); q.pop();
		int curdis = dis[id(u)];
		if (t == u) {
			/*
			for (int i = 0; i < curdis; ++i) {
				printf("%d %d %d\n", u.fi.fi, u.fi.se, u.se);
				u = pre[u];
			}
			*/
			return printf("%d\n", curdis), 0;
		}
		if (u.se == 0) {
			ax = u.fi.fi, ay = u.fi.se, bx = m - ax, by = m - ay;
			for (int i = 0; i <= ax; ++i) {
				for (int j = 0; j <= ay && i+j <= n; ++j) {
					send(i,j);
					st v = mp(mp(ax,ay), true);
					if (i+j >= 1 && check(i,j) && check(ax, ay) && check(bx, by) && dis[id(v)] == inf) {
						// pre[v] = u;
						dis[id(v)] = curdis+1;
						q.push(v);
					}
					send(-i,-j);
				}
			}
		} else {
			ax = u.fi.fi, ay = u.fi.se, bx = m - ax, by = m - ay;
			for (int i = 0; i <= bx; ++i) {
				for (int j = 0; j <= by && i+j <= n; ++j) {
					send(-i,-j);
					st v = mp(mp(ax,ay), false);
					if (i+j >= 1 && check(i,j) && check(ax, ay) && check(bx, by) && dis[id(v)] == inf) {
						// pre[v] = u;
						dis[id(v)] = curdis+1;
						q.push(v);
					}
					send(i,j);
				}
			}
		}
	}
	puts("-1");
}
