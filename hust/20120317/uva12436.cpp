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

typedef long long ll;
using namespace std;

const int maxn = 260000;
const int inf = 0x7fffffff;

struct seg{
	int v; 
	ll c, k, s;
}a[maxn * 4];

inline void setv(seg &p, int l, int r, int v) {
	p.v = v, p.c = p.k = 0;
	p.s = 1ll * (r - l + 1) * v;
}

inline void addv(seg &p, int l, int r, int c, int k) {
	p.c += c, p.k += k;
	p.s += 1ll * (2 * c + (r - l) * k) * (r - l + 1) / 2;
}

inline void push(seg &p, seg &ls, seg &rs, int l, int r, int m) {
	if (p.v != inf) {
		setv(ls, l, m, p.v);
		setv(rs, m + 1, r, p.v);
		p.v = inf;
	}
	if (p.c || p.k) {
		addv(ls, l, m, p.c, p.k);
		addv(rs, m + 1 , r, p.c + (m - l + 1) * p.k, p.k);
		p.c = p.k = 0;	
	}
}

inline void pop(seg &p, seg &ls, seg &rs) {
	p.s = ls.s + rs.s;
}

void setc(int t, int l, int r, int nl, int nr, int v) {
	seg &p = a[t];
	if (l == nl && r == nr) { 
		setv(p, l, r, v); 
		return;
	};
	int m = l + r >> 1, c = t << 1;
	seg &ls = a[c], &rs = a[c + 1];
	push(p, ls, rs, l, r, m);
	if (nr <= m) setc(c, l, m, nl, nr, v);
	else if (nl > m) setc(c + 1, m + 1, r, nl, nr, v);
	else setc(c, l, m, nl, m, v), setc(c + 1, m + 1, r, m + 1, nr, v);
	pop(p, ls, rs);
}

void add(int t, int l, int r, int nl, int nr, int cc, int kk) {
	seg &p = a[t];
	if (l == nl && r == nr) {  
		addv(p, l, r, cc, kk);
		return; }
	int m = l + r >> 1, c = t << 1;
	seg &ls = a[c], &rs = a[c + 1];
	push(p, ls, rs, l, r, m);
	if (nr <= m) add(c, l, m, nl, nr, cc, kk);
	else if (nl > m) add(c + 1, m + 1, r, nl, nr, cc, kk);
	else add(c, l, m, nl, m, cc, kk), add(c + 1, m + 1, r, m + 1, nr, cc + (m - nl + 1) * kk, kk);
	pop(p, ls, rs);
}

ll sum(int t, int l, int r, int nl, int nr) {
	seg &p = a[t];
	if (l == nl && r == nr) { 
		  return p.s;
	}
	int m = l + r >> 1, c = t << 1;
	seg &ls = a[c], &rs = a[c + 1];
	push(p, ls, rs, l, r, m);
	ll s1 = 0, s2 = 0;
	if (nr <= m) s1 = sum(c, l, m, nl, nr);
	else if (nl > m) s2 = sum(c + 1, m + 1, r, nl, nr);
	else s1 = sum(c, l, m, nl, m), s2 = sum(c + 1, m + 1, r, m + 1, nr);
	pop(p, ls, rs);
	return s1 + s2;
}

int main() {
	int T;
	
	setc(1, 1, maxn, 1, maxn, 0);
	scanf("%d", &T);
	while (T--) {
		char s[10];
		int x, y, v;
		scanf("%s%d%d", s, &x, &y);
		switch (s[0]) {
			case 'A': add(1, 1, maxn, x, y, 1, 1); break;
			case 'B': add(1, 1, maxn, x, y, y - x + 1, -1); break;
			case 'C': scanf("%d", &v); setc(1, 1, maxn, x, y, v); break;
			case 'S': printf("%lld\n", sum(1, 1, maxn, x, y));
		}
	}
	return 0;
}


