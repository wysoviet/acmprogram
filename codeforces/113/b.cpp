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

const double eps=1e-8;

struct pt{
	double x, y;
	pt(double a=0, double b=0) {x = a; y = b;}
	bool operator < (const pt &p1)const{return y < p1.y - eps
	|| fabs(y-p1.y)<eps && x < p1.x;}
	bool operator != (const pt &p1) const {
		return p1.x != x || p1.y != y; }
	void read() { scanf("%lf%lf", &x, &y);}
};

pt a[100000 + 10], b[30000], c[200000], f[200000];
int top, n, m, nc;

double cpr(pt &a, pt &b, pt &c){
	return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}

void make_ch(pt *p, pt *f, int n, int &top){
	top = 0;
	sort(p, p + n);
	for (int i = 0; i < 2*n-1; i++){
		int j = (i < n) ? i : 2*(n-1)-i;
		while (top > 1 && cpr(f[top-2], f[top-1], p[j]) < -eps)
			top--;
		f[top++] = p[j];
	}
	top--;
}

int main() {
	cin >> n;
	REP(i, n) { a[i].read(); c[nc++] = a[i];}
	cin >> m;
	REP(i, m) { b[i].read(); c[nc++] = b[i];}

	make_ch(c, f, nc, top);
	sort(a, a + n);
	sort(f, f + top);
	if (top != n) { puts("NO"); return 0;}
	else REP(i, n) if (a[i] != f[i]) {puts("NO"); return 0;}
	
	puts("YES");

	return 0;
}


