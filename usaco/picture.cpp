/*
ID:wysovie1
LANG:C++
TASK:picture
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

const int maxn = 1e4+10;
struct line{
	int l, r, h, w;
	line(int a=0,int b=0, int c=0, int d=0) {l=a,r=b,h=c,w=d;}
	bool operator < (const line &a) const { 
		if (h != a.h) return h < a.h; 
		else return w > a.w;
	}
	void print() { printf("%d %d %d %d\n", l, r, h, w);}
}s[maxn];

struct seg{
	int s, l, c;
	bool bl, br;
} a[maxn*20];

void setu(seg &p, seg &pl, seg &pr, int l, int r, int w) {
	if (p.s) { 
		p.l = r - l + 1;
		p.c = p.bl = p.br = 1;
	}else {
		p.l = pl.l + pr.l;
		p.c = pl.c + pr.c - (pl.br && pr. bl);
		p.bl = pl.bl;
		p.br = pr.br;
	}
}

void gao(int n, int l, int r, int nl, int nr, int w) {
	seg &p = a[n];
	int c = l + r >> 1;
	seg &pl = a[n<<1], &pr = a[n<<1|1];
	if (l == nl && r == nr) {
		p.s += w;
		setu(p, pl, pr, l, r, w);
		return ;
	}
	if (nr <= c) gao(n<<1, l, c, nl, nr, w);
	else if (nl > c) gao(n<<1|1, c + 1, r, nl, nr, w);
	else gao(n<<1, l, c, nl, c, w), gao(n<<1|1, c+1, r, c+1, nr, w);
	setu(p, pl, pr, l, r, w);
	//printf("[%d,%d] %d %d \n", l, r, p.s, p.l);
}

int n;
int main() {
	freopen("picture.in", "r", stdin);
	freopen("picture.out", "w", stdout);

	scanf("%d", &n);
	int x1, x2, y1, y2;
	REP(i, n) {
		cin >> x1 >> y1 >> x2 >> y2;
		s[i<<1] = line(x1, x2-1, y1, 1);
		s[i<<1|1] = line(x1, x2-1, y2, -1);
	}
	
	sort(s, s + 2*n);

	gao(1, -maxn, maxn, s[0].l, s[0].r, s[0].w);
	int curh = s[0].h, curl = a[1].l;
	int ans = a[1].l;
	for (int i = 1; i < 2 * n; i++) {
		//DEB(ans);
		ans += 2*a[1].c*(s[i].h-curh);
		//DEB(ans);
		curh = s[i].h;
		gao(1, -maxn, maxn, s[i].l, s[i].r, s[i].w);
		ans += abs(a[1].l - curl);
		//DEB(ans);
		curl = a[1].l;
		//cout << endl;
	}
	cout << ans << endl;
	return 0;
}


