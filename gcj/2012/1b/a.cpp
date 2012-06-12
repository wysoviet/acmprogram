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

int main() {
	freopen("A-large.in", "r", stdin);
	freopen("a.ans", "w", stdout);
	
	int T;
	int n, a[300];
	double ans[300];
	bool v[300];
	cin >> T;

	for (int ca = 1; ca <= T; ca++) {
		cin >> n;
		REP(i, n) cin >> a[i];
		double sum = 0;
		REP(i, n) sum += a[i];
		MS(v, 0);
		double s, p;
		int cnt;
		do {
			s = cnt =  0;
			REP(i, n) if(!v[i]) s += a[i], cnt++;
			p = (s + sum) / cnt;	
			cnt = 0;
			REP(i, n) if (!v[i] && a[i] > p) cnt++, v[i] = 1;
		}while(cnt);
		printf("Case #%d:", ca);
		REP(i, n) if(v[i]) printf(" 0.0");
		else printf(" %.6f", (p-a[i])/sum*100);

		cout << endl;
	}
	return 0;
}

