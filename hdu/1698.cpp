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
const int inf = 0x7fffffff;
struct seg{
	int v, s;
}a[maxn * 4];

inline void pop(seg &p, seg &ls, seg &rs) {
	p.s = ls.s + rs.s;
}

inline void setv(seg &p, int l, int r, int v) {
	p.v = v;
	p.s = (r - l + 1) * v;
}

inline void push(seg &p, seg &ls, seg &rs, int l, int r, int m) {
	if (!p.v) return;
	setv(ls, l, m, p.v);
	setv(rs, m + 1, r, p.v);
	p.v = 0;
}

void update(int t, int l, int r, int nl, int nr, int v) {
	seg &p = a[t];
	if (l == nl && r == nr) {setv(p, l, r, v); return;}
	int m = l + r >> 1, c = t << 1;
	seg &ls = a[c], &rs = a[c + 1];
	push(p, ls, rs, l, r, m);
	if (nr <= m) update(c, l, m, nl, nr, v);
	else if (nl > m) update(c + 1, m + 1, r, nl, nr, v);
	else update(c, l, m, nl, m, v), update(c + 1, m + 1, r, m + 1, nr, v);
	pop(p, ls, rs);
}

int sum(int t, int l, int r, int nl, int nr) { 
	seg &p = a[t]; 
	if (l == nl && r == nr) return p.s; 
	int m = l + r >> 1, c = t << 1;
	seg &ls = a[c], &rs = a[c + 1];
	push(p, ls, rs, l, r, m);
	int s1 = 0, s2 = 0;
	if (nr <= m) s1 = sum(c, l, m, nl, nr);
	else if (nl > m) s2 = sum(c + 1, m + 1, r, nl, nr);
	else s1 = sum(c, l, m, nl, m), s2 = sum(c + 1, m + 1, r, m + 1, nr);
	pop(p, ls, rs);
	return s1 + s2;
}

int main() {
	int T, cas = 0; 
	
	scanf("%d", &T);
	while (T--){
		int n, x, y, v, m;
		scanf("%d%d", &n, &m);
		update(1, 1, n, 1, n, 1);
		while (m--) {
			scanf("%d%d%d", &x, &y, &v);
			update(1, 1, n, x, y, v);
		}
		printf("Case %d: The total value of the hook is %d.\n", ++cas, sum(1, 1, n, 1, n));
	}
	
	return 0;
}


