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
#define DEB(x) cout << #x << " : " << x << endl
#define DEBA(a, n) REP(i, n) cout << #a << "[" << i << "] : " << a[i] << endl

using namespace std;

const int maxn = 1001;
int m, n;
int a[1100][1100], b[1100][1100];

int main() {
	int n, m, s, t;

	cin >> n >> m;
	while (n--) {
		scanf("%d%d", &s, &t);
		a[s][t]++;
	}
	while (m--) {
		scanf("%d%d", &s, &t);
		b[s][t]++;
	}

	int ans = 0, ans2 = 0;
	for (int j = 1; j <= 1000; j++) {
		t = s = 0;
		for (int i = 1; i <= 1000; i++)
			t += a[i][j], s += b[i][j], ans2 += min(a[i][j], b[i][j]);
		ans += min(t, s);
	}

	cout << ans << " " << ans2 << endl;
	return 0;
}


