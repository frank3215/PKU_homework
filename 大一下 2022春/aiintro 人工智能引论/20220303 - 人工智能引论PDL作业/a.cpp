#include <cstdio>
#include <iostream>
#include <map>

using namespace std;

int main() {
	int n;
	cin >> n;
	int a;
	map<int, int> mp;
	for (int i = 0; i < n; ++i) {
		cin >> a;
		if (mp[a]++) cout << a << endl;
	}
}
