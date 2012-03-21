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

const int maxn = 50000 + 10;
struct seg{
	int m, ml, mr;
	int l, r, v;
}a[maxn * 4];

int ansl, ansr;

inline void pop(seg &p, seg &ls, seg &rs, int l, int r, int m) {
	p.m = p.ml = p.mr = p.l = p.r = 0;
	if (ls.m > p.m) p.m = ls.m, p.ml = ls.ml, p.mr = ls.mr;
	if (ls.r + rs.l > p.m) p.m = ls.r + rs.l, p.ml = m - ls.r + 1, p.mr = m + rs.l;
	if (rs.m > p.m) p.m = rs.m, p.ml = rs.ml, p.mr = rs.mr;
	if (ls.l == m - l + 1) p.l = ls.l + rs.l;
	else p.l = ls.l;
	if (rs.r == r - m) p.r = rs.r + ls.r;
	else p.r = rs.r;
}

inline void setv(seg &p, int l, int r, int v) {
	p.v = v;
	if (v == 1) p.m = p.ml = p.mr = p.l = p.r = 0;
	else p.m = p.l = p.r = r - l + 1, p.ml = l, p.mr = r;
}

inline void push(seg &p, seg &ls, seg &rs, int l, int r, int m) {
	if (!p.v) return;
	setv(ls, l, m, p.v);
	setv(rs, m + 1, r, p.v);
	p.v = 0;
}

void gao(int t, int l, int r, int nl, int nr, int v) {
	seg &p = a[t];
	if (l == nl && r == nr) { setv(p, l, r, v); return; }
	int m = l + r >> 1, c = t << 1;
	seg &ls = a[c], &rs = a[c + 1];
	push(p, ls, rs, l, r, m);
	if (nr <= m) gao(c, l, m, nl, nr, v);
	else if (nl > m) gao(c + 1, m + 1, r, nl, nr, v);
	else gao(c, l, m, nl, m, v), gao(c + 1, m + 1, r, m + 1, nr, v);
	pop(p, ls, rs, l, r, m);
}

void cha(int t, int l, int r, int k) {
	seg &p = a[t];
	if (p.m < k) return;
	int m = l + r >> 1, c = t << 1;
	seg &ls = a[c], &rs = a[c + 1];
	push(p, ls, rs, l, r, m);
	ansl = min(ansl, p.ml);
	if (ls.r + rs.l >= k) ansl = min(ansl, m - ls.r + 1);
	if (l != r) {cha(c, l, m, k);
	if (ansl > m) cha(c + 1, m + 1, r, k);}
	pop(p, ls, rs, l, r, m);
}

int main() {
	int n, m, x, y, v;

	scanf("%d%d", &n, &m);
	gao(1, 1, n, 1, n, 2);
	while (m--) {
		scanf("%d%d", &v, &x); 
		if (v == 1) { 
			ansl = 0x7fffffff;
			cha(1, 1, n, x);
			if (ansl == 0x7fffffff) ansl = 0;
			printf("%d\n", ansl);
			if (ansl) gao(1, 1, n, ansl, ansl + x - 1, 1);
		}else { scanf("%d", &y);
			gao(1, 1, n, x, x + y - 1, 2);
		}
	}

	return 0;
}


