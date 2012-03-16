/*
ID:wysovie1
LANG:C++
TASK:fc
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

using namespace std;

const double eps = 1e-8;
struct pt{
	double x, y;
	pt(double a = 0, double b = 0) {x = a; y = b;}
	bool operator < (const pt &p1) const {return y < p1.y - eps ||
		fabs(y - p1.y) < eps && x < p1.x;}
}p[10010], f[10010];

int n, top;

double dis(pt &a, pt &b) {
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double cpr(pt &a, pt &b, pt &c){
	return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}

void make_ch(pt *p, pt *f, int n, int &top) {
	top = 0;
	sort(p, p + n);
	for (int i = 0; i < 2 * n - 1; i++) {
		int j = (i < n) ? i : 2 * (n - 1) - i;
		while (top > 1 && cpr(f[top - 2], f[top - 1], p[j]) 
				< -eps) top--;
		f[top++] = p[j];
	}
	top--;
}

int main() {
	freopen("fc.in", "r", stdin);
	freopen("fc.out", "w", stdout);
			
	scanf("%d", &n);
	REP(i, n) scanf("%lf%lf", &p[i].x, &p[i].y);

	make_ch(p, f, n, top);
	double ans = 0;
	REP(i, top) ans += dis(f[i], f[i + 1]); 
	printf("%.2f\n", ans);

	return 0;
}


