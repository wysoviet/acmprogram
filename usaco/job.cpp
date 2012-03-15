/*
ID:wysovie1
LANG:C++
TASK:job
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
#define DEB(x) cout << #x << " : " << x << endl
#define DEBA(a, n) REP(i, 0, n - 1) cout << #a << "[" << i << "] : " << a[i] << endl

using namespace std;

const int maxn = 1010;
int n, m1, m2;
int a[maxn], b[maxn], sa[maxn], sb[maxn], da[maxn], db[maxn];

void gao(int a[], int m, int d[], int s[]) {
	for (int i = 1; i <= n; i++) {
		int md = 0x7fffffff, id = -1;
		for (int j = 1; j <= m; j++)
			if (md > d[j] + a[j]) {
				md = d[j] + a[j];
				id = j;
			}
		d[id] += a[id];
		s[i] = d[id];
	}
}

int main() {
	freopen("job.in", "r", stdin);
	freopen("job.out", "w", stdout);

	cin >> n >> m1 >> m2;	
	REP(i, m1) cin >> a[i + 1];	
	REP(i, m2) cin >> b[i + 1];
	gao(a, m1, da, sa);
	gao(b, m2, db, sb);

	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans = max(ans, sa[i] + sb[n - i + 1]);

	cout << sa[n] << " " << ans << endl;
	return 0;
}


