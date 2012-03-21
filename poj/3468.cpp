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

typedef long long ll;

const int maxn = 100000 + 10;
struct seg {
	ll s, k;
}a[maxn * 4];

inline void setv(seg &p, int l, int r, int k) {
	p.s += 1ll * (r - l + 1) * k;
	p.k += k;
}

inline void pop(seg &p, seg &ls, seg &rs) {
	p.s = ls.s + rs.s;
}

inline void push(seg &p, seg &ls, seg &rs, int l, int r, int m) {
	if (p.k == 0) return;
	setv(ls, l, m, p.k);
	setv(rs, m + 1, r, p.k);
	p.k = 0;
}

void add(int t, int l, int r, int nl, int nr, int k) {
	seg &p = a[t];
	if (l == nl && r == nr) { setv(p, l, r, k); return;}
	int m = l + r >> 1, c = t << 1;
	seg &ls = a[c], &rs = a[c + 1];
	push(p, ls, rs, l, r, m);
	if (nr <= m) add(c, l, m, nl, nr, k);
	else if (nl > m) add(c + 1, m + 1, r, nl, nr, k);
	else add(c, l, m, nl, m, k), add(c + 1, m + 1, r, m + 1, nr, k);
	pop(p, ls, rs);
}

ll read(int t, int l, int r, int nl, int nr) {
	seg &p = a[t];
	if (l == nl && r == nr) return p.s;
	int m = l + r >> 1, c = t << 1;
	seg &ls = a[c], &rs = a[c + 1];
	push(p, ls, rs, l, r, m);
	ll s1 = 0, s2 = 0;
	if (nr <= m) s1 = read(c, l, m, nl, nr);
	else if (nl > m) s2 = read(c + 1, m + 1, r, nl, nr);
	else s1 = read(c, l, m, nl, m), s2 = read(c + 1, m + 1, r, m + 1, nr);
	pop(p, ls, rs);
	return s1 + s2;
}

int main() {
	int n, q;

	scanf("%d%d", &n, &q);
	ll t;
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &t);
		add(1, 1, n, i, i, t);
	}

	char s[10];
	int x, y, v;
	while (q--){
		scanf("%s%d%d", s, &x, &y);
		if (s[0] == 'Q') printf("%lld\n", read(1, 1, n, x, y));
		else { scanf("%d", &v); add(1, 1, n, x, y, v); }
	}

	return 0;
}


