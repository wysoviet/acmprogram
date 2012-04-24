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

const double eps = 1e-8;
const int maxn = 3e2;
double v1[maxn], v2[maxn];
int hp1, hp2, dt1, dt2, l1, l2, r1, r2, p1, p2, t1, t2;

bool gao(double *v, int l, int r, int p, int hp) {
	bool flag = 0;
	
	for (int i = 1; i <= hp; i++) {
		if (v[i] < eps) continue;
		flag = 1;
		double t = (1 - 0.01 * p) * v[i] / (r - l + 1);
		v[i] *= 0.01 * p;
		for (int j = l; j <= r; j++) 
			v[max(i-j, 0)] += t;
	}

	return flag;
}

int main() {
	cin >> hp1 >> dt1 >> l1 >> r1 >> p1;
	cin >> hp2 >> dt2 >> l2 >> r2 >> p2;

	if (p1 == 100) return puts("0"), 0;
	else if (p2 == 100) return puts("1"), 0;

	double ans = 0;
	v1[hp1] = v2[hp2] = 1;
	while (1) if (t1 <= t2) {
		t1 += dt1; 
		v2[0] = 0;
		gao(v2, l1, r1, p1, hp2);
		ans += (1 - v1[0]) * v2[0];
	}else { t2 += dt2;
		if (!gao(v1, l2, r2, p2, hp1)) break;
	}

	printf("%.10f", ans);

	return 0;
}


