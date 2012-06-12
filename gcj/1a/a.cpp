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

const int maxn = 2e6;

double p[maxn];

int main() {
	int T;
	int a, b;

	freopen("a.in", "r", stdin);
	freopen("a.ans", "w", stdout);

	cin >> T;
	for (int ca = 1; ca <= T; ca++) {
		cin >> a >> b;
		REP(i, a) cin >> p[i];
		double ps = 1, pd = 1;
		REP(i, a) ps = ps * p[i];
		double ans1 = ps * (b - a + 1) + (1-ps) * (b-a+1+b+1);
		double ans3 = b + 2;
		double ans2 = 1e100;
		REP(i, a) {
			ans2 = min(ans2, a-i+b-i+1+(1-pd)*(b+1));
			pd *= p[i];
		}
		double ans = min(ans1, ans2);
		printf("Case #%d: %.7f\n", ca, min(ans, ans3));
	}
	return 0;
}


