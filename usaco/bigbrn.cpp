/*
ID:wysovie1
LANG:C++
TASK:bigbrn
*/

#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <string>

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
int a[maxn][maxn], f[maxn][maxn];
int n;

int main() {
	freopen("bigbrn.in", "r", stdin);
	freopen("bigbrn.out", "w", stdout);
	int t, p, q;
	cin >> n >> t;
	REP(i, t) { 
		cin >> p >> q;
		a[p][q] = 1;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) 
			if (!a[i][j]) {
				f[i][j] = min(f[i-1][j], f[i][j-1]);
				f[i][j] = min(f[i][j], f[i-1][j-1]);
				ans = max(ans, ++f[i][j]);
			}
	/*
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) 
			cout << f[i][j] << ' ';
		puts("");
	}
	*/
	cout << ans << endl;
	return 0;
}


