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
#define FI first
#define SE second

using namespace std;

const int maxn = 200000 + 10;

struct seg{
	int m;
}a[maxn * 4];

inline void pop(seg &p, seg &ls, seg &rs) {
	p.m = max(ls.m, rs.m);
}

int getm(int t, int l, int r, int nl, int nr) {
	seg &p = a[t];
	if (l == nl && r == nr) return p.m;
	int m = l + r >> 1, c = t << 1;
	seg &ls = a[c], &rs = a[c + 1];
	if (nr <= m) return getm(c, l, m, nl, nr);
	else if (nl > m) return getm(c + 1, m + 1, r, nl, nr);
	else return max(getm(c, l, m, nl, m), getm(c + 1, m + 1, r, m + 1, nr));
}

void update(int t, int l, int r, int nl, int nr, int v) {
	seg &p = a[t];
	if (l == nl && r == nr) { p.m = v; return ;}
	int m = l + r >> 1, c = t << 1;
	seg &ls = a[c], &rs = a[c + 1];
	if (nr <= m) update(c, l, m, nl, nr, v);
	else update(c + 1, m + 1, r, nl, nr, v);
	pop(p, ls, rs);
}

int main() {
	int n, m;

	while (~scanf("%d%d", &n, &m)) {
		int t;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &t);
			update(1, 1, maxn, i, i, t);
		}
		int x, y;
		char s[10];
		while (m--) {
			scanf("%s%d%d", s, &x, &y);
			if (*s == 'Q') printf("%d\n", getm(1, 1, maxn, x, y));
			else update(1, 1, maxn, x, x, y);
		}
	}

	return 0;
}


