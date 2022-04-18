// C:魔兽世界之二：装备
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int N = 5, inf = 99999999;
const char *str[] = {"dragon", "ninja", "iceman", "lion", "wolf"}, *wpname[3] = {"sword", "bomb", "arrow"};
const int redp[] = {2,3,4,1,0}, bluep[] = {3,0,1,2,4};

int h[N], M, mn = inf;

class headquarter{
public:
	int hp, cur, tot;
	vector<int> cnt, p;
	bool stopped;
	string name;
	headquarter(): stopped(false), cur(0), tot(0), hp(0), cnt(N), p(N), name() {}
	bool make(int t) {
		if (stopped) {
			return false;
		}
		printf("%03d ", t);
		if (hp < mn) {
			cout << name << " headquarter stops making warriors" << endl;
			stopped = true;
			return false;
		}
		//cout << "(" << p[cur] << ")" << endl;
		while (h[p[cur]] > hp) cur = (cur + 1)%N;
		//cout << "(" << p[cur] << ")" << endl;
		hp -= h[p[cur]];
		cnt[p[cur]]++;
		cout << name << " " << str[p[cur]] << " " << t+1 << " born with strength " << h[p[cur]] << "," << cnt[p[cur]] << " " << str[p[cur]] << " in " << name << " headquarter" << endl;
		switch (p[cur]) {
			case 0: // dragon
				printf("It has a %s,and it's morale is %.2f\n", wpname[(t+1)%3], hp/(double)h[p[cur]]);
				break;
			case 1: // ninja
				printf("It has a %s and a %s\n", wpname[(t+1)%3], wpname[(t+2)%3]);
				break;
			case 2: // iceman
				printf("It has a %s\n", wpname[(t+1)%3]);
				break;
			case 3: // wolf
				printf("It's loyalty is %d\n", hp);
				break;
		}
		cur = (cur+1)%N;
		return true;
	}
};

void solve() {
	cin >> M;
	mn = inf;
	for (int i = 0; i < N; ++i) {
		cin >> h[i];
		mn = min(h[i], mn);
	}
	headquarter red, blue;
	red.name = "red";
	red.hp = M;
	red.p = vector<int>{2,3,4,1,0};
	blue.name = "blue";
	blue.hp = M;
	blue.p = vector<int>{3,0,1,2,4};
	bool flag = true;
	for (int i = 0; flag; i++) {
		bool flag_red = red.make(i), flag_blue = blue.make(i);
		flag = flag_red || flag_blue;
	}
}

int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		cout << "Case:" << i << endl;
		solve();
	}
}

/* 写到一半想起来可以直接复制之前的代码
#include <cstdio>
#include <iostream>

string sdname[5] = {"dragon", "ninja", "iceman", "lion", "wolf"}, wpname[3] = {"sword", "bomb", "arrow"};

int M, hp[5];

class hq {
public:
	string name;
	int curhp, turn;
	hq(char *s): name(s) {}
	void make() {
	}
	bool make_sd(int i) {
		if (curhp < hp[i]) return false;
		switch (sdname[i]) {
		case "dragon":
			
		}
		return true;
	}
	void stop() {
	}
}

void solve() {
	cin >> m;
	for (int i = 0; i < 5; ++i) cin >> hp[i];
	hq red("red"), blue("blue")
}

int main() {
	int t;
	cin >> t;
	while (t--) solve();
}
*/
