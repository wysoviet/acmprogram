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

typedef long long ll;
pair<ll, ll> a[1000];
ll p[1000];

int main() {
	int n;

	cin >> n;
	REP(i, n) cin >> a[i].SE >> a[i].FI;
	sort(a, a + n);
	ll t, f = 1, j = 0, cur = 0, left = 0;
	ll ans = 0, tmp;
	cin >> t;
	REP(i, t) cin >> p[i];
	p[t] = 1e12;
	REP(i, t + 1) {
		cur = cur + left;
		if (j) tmp = a[j-1].FI * left;
		else tmp = 0;
		while (cur < p[i] && j < n) {
			cur += a[j].SE;
			tmp += a[j].FI * a[j].SE;
			j++;
		}
		if (cur > p[i]) {
			left = cur - p[i];
			cur = p[i];
			if(j) tmp -= a[j-1].FI * left;
		}else left = 0;
		ans += tmp * (i + 1);
		//cout << ans << endl;
	}

	cout << ans << endl;
	return 0;
}


