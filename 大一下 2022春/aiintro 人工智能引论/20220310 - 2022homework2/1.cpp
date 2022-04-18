// 1:Find the Winning Move
#include <cstdio>
#include <iostream>

using namespace std;

char c, s[4][5];
int ansx, ansy, cnt[100];

int search(char cur, bool first=false, int lev=0) {
	cnt[lev]++;
	char op = 'x' ^ 'o' ^ cur;
	for (int i = 0; i < 4; ++i) {
		bool lose = true;
		for (int j = 0; j < 4; ++j) if (s[i][j] != op) lose = false;
		if (lose) return -1;
	}
	for (int i = 0; i < 4; ++i) {
		bool lose = true;
		for (int j = 0; j < 4; ++j) if (s[j][i] != op) lose = false;
		if (lose) return -1;
	}
	{
		bool lose = true;
		for (int j = 0; j < 4; ++j) if (s[j][j] != op) lose = false;
		if (lose) return -1;
	}
	{
		bool lose = true;
		for (int j = 0; j < 4; ++j) if (s[j][3-j] != op) lose = false;
		if (lose) return -1;
	}
	{
		bool draw = true;
		for (int i = 0; i < 4; ++i) for (int j = 0; j < 4; ++j) {
			if (s[i][j] == '.') draw = false;
		}
		if (draw) return cur == 'x' ? -1 : 1;
	}
	int ans = 1;
	for (int i = 0; i < 4; ++i) for (int j = 0; j < 4; ++j) if (s[i][j] == '.') {
		s[i][j] = cur;
		ans = min(ans, search(op, false, lev+1));
		s[i][j] = '.';
		if (ans == -1) {
			if (first) ansx = i, ansy = j;
			return -ans;
		}
	}
	return -ans;
}

int main() {
	while (1) {
		scanf(" %c", &c);
		if (c == '$') break;
		for (int i = 0; i < 4; ++i)
			scanf(" %s", s[i]);
		if (search('x',true) == 1) {
			printf("(%d,%d)\n", ansx, ansy);
		} else {
			puts("#####");
		}
	}
}
