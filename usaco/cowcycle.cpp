/*
ID:wysovie1
LANG:C++
TASK:cowcycle
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
#define DEB(x) cout << #x << " : " << x << endl
#define DEBA(a, n) REP(i, n) cout << #a << "[" << i << "] : " << a[i] << endl

using namespace std;

int f[10], r[20], af[10], ar[20];
double d[200], s, s2;
int F, R, f1, f2, r1, r2;
double best = 1e200;

void gao(){
	double t;
	if (f[F-1] * r[R-1] < 3 * f[0] * r[0]) return;
	int n = 0;
	REP(i, F) REP(j, R) d[n++] = 1.00 * f[i] / r[j];
	sort(d, d + n); n--;
	s = s2 = 0;
	REP(i, n) {t = d[i + 1] - d[i]; s += t; s2 += t * t; }
	double cur = s2 / n - s / n * s / n;
	if (cur < best) { 
		best = cur;
		memcpy(af, f, F * 4);
		memcpy(ar, r, R * 4);
	}
}

void gaor(int k, int x) {
	if (k == R) { gao(); return; }
	for (int i = x; i <= r2 - R + k + 1; i++) {
		r[k] = i;
		gaor(k + 1, i + 1);
	}
}
	
void gaof(int k, int x) {
	if (k == F) { gaor(0, r1); return; }
	for (int i = x; i <= f2 - F + k + 1; i++) {
		f[k] = i;
		gaof(k + 1, i + 1);
	}
}

int main() {
	freopen("cowcycle.in", "r", stdin);
	freopen("cowcycle.out", "w", stdout);

	cin >> F >> R >> f1 >> f2 >> r1 >> r2;
	gaof(0, f1);

	REP(i, F - 1) cout << af[i] << " ";
	cout << af[F - 1] << endl;
	REP(i, R - 1) cout << ar[i] << " ";
	cout << ar[R - 1] << endl;
	
	return 0;
}


