// A:List | 2022 程序设计实习之STL专项练习8选6 | http://cxsjsx.openjudge.cn/hw202209/A/
#include <cstdio>
#include <iostream>
#include <list>
using namespace std;

int n, x, y;
char s[10];
list<int> l[10000];

int main() {
	scanf("%d", &n);
	while (n--) {
		scanf("%s%d", s, &x);
		if (s[0] == 'n') {
			l[x].clear();
		}
		if (s[0] == 'a') {
			scanf("%d", &y);
			list<int>::iterator it = l[x].begin();
			while (it != l[x].end() && *it < y) ++it;
			l[x].insert(it, y);
		}
		if (s[0] == 'm') {
			scanf("%d", &y);
			l[x].merge(l[y]);
		}
		if (s[0] == 'u') {
			l[x].unique();
		}
		if (s[0] == 'o') {
			for (list<int>::iterator it = l[x].begin(); it != l[x].end(); ++it) cout << *it << " ";
			cout << endl;
		}
	}
}
