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

const int maxn = 100000 + 10;
struct seg{
	int bl, br, wl, wr, mb, mw, v;
}a[maxn * 4];

inline void pop(seg &p, seg &ls, seg &rs, int l, int r, int m) {
	p.bl = ls.bl, p.wl = ls.wl, p.br = rs.br, p.wr = rs.wr;
	if (p.bl == m - l + 1) p.bl += rs.bl;
	if (p.wl == m - l + 1) p.wl += rs.wl;
	if (p.br == r - m) p.br += ls.br;
	if (p.wr == r - m) p.wr += ls.wr;
	p.mb = max(ls.mb, rs.mb), p.mw = max(ls.mw, rs.mw);
	p.mb = max(ls.br + rs.bl, p.mb);
	p.mw = max(ls.wr + rs.wl, p.mw);
}

inline void gaov(seg &p, int l, int r) {
	p.v ^= 1;
	swap(p.mb, p.mw); swap(p.bl, p.wl);
	swap(p.br, p.wr); 
}
	
inline void push(seg &p, seg &ls, seg &rs, int l, int r, int m) {
	if (p.v == 0) return;
	gaov(ls, l, m);
	gaov(rs, m + 1, r);
	p.v = 0;
}

void gao(int t, int l, int r, int nl, int nr) {
	seg &p = a[t];
	if (l == nl && r == nr) { gaov(p, l, r); return;}
	int m = l + r >> 1, c = t << 1;
	seg &ls = a[c], &rs = a[c + 1];
	push(p, ls, rs, l, r, m);
	if (nr <= m) gao(c, l, m, nl, nr);
	else if (nl > m) gao(c + 1, m + 1, r, nl, nr);
	else gao(c, l, m, nl, m), gao(c + 1, m + 1, r, m + 1, nr);
	pop(p, ls, rs, l, r, m);
}

int cha(int t, int l, int r, int nl, int nr) {
	seg &p = a[t];
	if (l == nl && r == nr) return p.mb;
	int m = l + r >> 1, c = t << 1;
	seg &ls = a[c], &rs = a[c + 1];
	int t1 = 0, t2 = 0, tt = 0;
	push(p, ls, rs, l, r, m);
	if (nr <= m) tt = cha(c, l, m, nl, nr);
	else if (nl > m) tt = cha(c + 1, m + 1, r, nl, nr);
	else { t1 = cha(c, l, m, nl, m); 
	       t2 = cha(c + 1, m + 1, r, m + 1, nr);
	       tt = max(t1, t2);
	       nl = max(nl, m - ls.br + 1),
	       nr = min(nr, m + rs.bl);
	       tt = max(nr - nl + 1, tt);
	}
	pop(p, ls, rs, l, r, m);
	return tt;
 }

void init(int t, int l, int r) {
	seg &p = a[t];
	p.mw = p.wl = p.wr = r - l + 1;
	p.mb = p.bl = p.br = p.v = 0;
	if (l == r) return;
	int m = l + r >> 1, c = t << 1;
	init(c, l, m);
	init(c + 1, m + 1, r);
}

int main() {
	int n, t, m, x, y;

	while (~scanf("%d", &n)) {
		init(1, 1, n);		
		for (int i = 1; i <= n; i++) {
			scanf("%d", &t);
			if (t == 0) continue;
			gao(1, 1, n, i, i);
		}
		scanf("%d", &m);
		while (m--) {
			scanf("%d%d%d", &t, &x, &y);
			if (t) gao(1, 1, n, x, y);
			else printf("%d\n", cha(1, 1, n, x, y));
		}
	}

	return 0;
}


