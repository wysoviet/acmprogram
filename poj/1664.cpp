#include <iostream>
#include <cstring>
#define MS(a, i) memset(a, i, sizeof(a))

using namespace std;
const int maxn = 30;
int f[maxn][maxn][maxn];

int gao(int n, int k, int m) {
	if (n < 0) return 0;
	if (~f[n][k][m]) return f[n][k][m];
	if (n == 0) return f[n][k][m] = 1;
	if (m == 0 || k == 0) return f[n][k][m] = 0;
	return f[n][k][m] =  gao(n, k - 1, m) + gao(n - k, k, m - 1);
}

int main() {
	MS(f, -1);		
	int T;
	cin >> T;
	int n, m;
	while (T--) {
		cin >> n >> m;
		int ans = 0;
		cout << gao(n, n, m) << endl;
	}
	return 0;
}


