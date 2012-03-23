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

const int maxn = 10000 + 10;
const int maxr = 5000 + 10;
struct seg{
	bool l, r;
	int v, n, s;
}a[maxn * 2 * 4];

struct seg2{ 
	int l, r, h, v;
	bool operator < (const seg2 & a) const { return h < a.h;}
	seg2() {}
	seg2(int a, int b, int c, int d):l(a), r(b), h(c), v(d) {}
}b[maxr * 2];

inline void pop(seg &p, seg &ls, seg &rs) {
	p.n = ls.n + rs.n, p.s = ls.s + rs.s;
	p.l = ls.l, p.r = rs.r;
	if (ls.r && rs.l) p.n--;
}

inline void addv(int t, int l, int r, int v) {
	seg &p = a[t];
	p.v += v;
	if (p.v) p.n = p.l = p.r = 1, p.s = r - l + 1;
	else if (l == r) p.n = p.l = p.r = p.s = 0;
	else { int m = l + r >> 1, c = t << 1;
		seg &ls = a[c], &rs = a[c + 1];
		pop(p, ls, rs);
	}
}

void add(int t, int l, int r, int nl, int nr, int v) {
	seg &p = a[t];
	if (l == nl && r == nr) { addv(t, l, r, v); 
	//printf("[%d, %d] s = %d, n = %d, v = %d, l = %d, r = %d\n", l, r, p.s, p.n, p.v, p.l, p.r);
	return;}
	int m = l + r >> 1, c = t << 1;
	seg &ls = a[c], &rs = a[c + 1];  
	if (nr <= m) add(c, l, m, nl, nr, v);
	else if (nl > m) add(c + 1, m + 1, r, nl, nr, v);
	else add(c, l, m, nl, m, v), add(c + 1, m + 1, r, m + 1, nr, v);
	addv(t, l, r, 0);
	//printf("[%d, %d] s = %d, n = %d, v = %d, l = %d, r = %d\n", l, r, p.s, p.n, p.v, p.l, p.r);
}

int main() {
	int n, x1, y1, x2, y2, r = 0;
	scanf("%d", &n);
	REP(i, n) {
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		b[r++] = seg2(x1, x2, y1, 1);
		b[r++] = seg2(x1, x2, y2, -1);
	}

	sort(b, b + r);

	int ans = 0, curh = 0, curs = 0, curn = 0;
	REP(i, r) {
		add(1, -maxn, maxn, b[i].l, b[i].r-1, b[i].v);
		ans += abs(curs - a[1].s);
		ans += (b[i].h - curh) * curn * 2;
		curs = a[1].s; curh = b[i].h; curn = a[1].n;
		//printf("[%d, %d, %d] %d\n", b[i].l, b[i].r, b[i].h, b[i].v);
		//cout << ans << endl << endl;
	}	

	printf("%d", ans);
	return 0;
}


