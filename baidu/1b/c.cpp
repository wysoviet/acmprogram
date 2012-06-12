#include <algorithm>
#include <iostream>
#include <cstdio>

#define REP(i, a) for (int i = 0; i < a; i++)
#define REPD(i, a) for (int i = a - 1; ~i; i--)
#define TR(it, a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define PB(i) push_back(i)
#define MS(a, i) memset(a, i, sizeof(a))
#define MP(a, b) make_pair(a, b)
#define ALL(a) a.begin(),a.end()
#define DEB(x) cout << #x << " : " << x << endl
#define DEBA(a, n) REP(i, n) cout << #a << "[" << i << "] : " << a[i] << endl
#define FI first
#define SE second

using namespace std;

const int maxn = 1010;
typedef long long lld;
lld f[maxn][maxn], v1[maxn], v2[maxn];
pair<lld,lld > a[maxn];
lld s1, s2, x1, x2, y1, y2;
int n;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%lld%lld", &a[i].FI, &a[i].SE);
	cin >> s1 >> x1 >> y1;
	cin >> s2 >> x2 >> y2;
	for (int i = 1; i <= n; i++) {
		v1[i] = x1*a[i].FI + y1*a[i].SE;
		v2[i] = x2*a[i].FI + y2*a[i].SE;
	}

	for (int i = 1; i <= n; i++)
		for (int j = 0, l = min(1ll*i, s1); j <= l; j++) {
			if (j == 0) f[i][0] = f[i-1][0] + v2[i];
			else {
				f[i][j] = max(f[i][j-1],f[i-1][j-1]+ v1[i]);
				f[i][j] = max(f[i][j], f[i-1][j] + v2[i]);
			}
		}
	cout << f[n][s1] << endl;
	return 0;
}


