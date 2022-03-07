#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 100;

int n, f[N][N];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%d", &f[i][j]);
	for (int k = 0; k < n; ++k)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				f[i][j] = min(f[i][j], f[i][k]+f[k][j]);
	printf("%d\n", f[0][n-1]);
}
