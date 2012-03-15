/*
ID:wysovie1
LANG:C++
TASK:
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

using namespace std;

const int maxn = 1010;
int n, k;
vector< pair<int, int> > c[2], a[maxn];

int main() {
	cin >> n >> k;
	REP(p, n) {
		int i, j;
		cin >> i >> j;
		c[j-1].PB(MP(i, p + 1));
	}

	sort(ALL(c[0]));
	sort(ALL(c[1]));

	int i = 0, j = 0;
	if (c[0].size() > k) { 
		for ( ;i < c[0].size() - k; i++) 
			a[0].PB(c[0][i]);
	}
	for ( ; i < c[0].size(); i++)
		a[j++].PB(c[0][i]); 
	if (c[0].size() >= k) {
		for (i = 0; i < c[1].size(); i++)
			a[0].PB(c[1][i]);
	}else {
		int t = k - c[0].size();
		for (i = 0; i < t; i++)
			a[c[0].size() + i].PB(c[1][i]);
		for (i; i < c[1].size(); i++)
			a[c[0].size()].PB(c[1][i]);
	}

	int m = min(k, (int)c[0].size());
	double ans = 0;

	REP(i, k) {
		sort(ALL(a[i]));
		TR(j, a[i]) ans += 1.0 * (j->first);
		if (i < m) ans -= a[i][0].first / 2.0;
	}

	printf("%.1f\n", ans);
	REP(i, k) {
		cout << a[i].size();
		TR(j, a[i]) cout << " " << j->second;
		cout << endl;
	}
	return 0;
}


