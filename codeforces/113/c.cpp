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
	int n, l, r, m, k, t;
	l = r = m = 0;
	cin >> n >> k;
	REP(i, n) {
		cin >> t;
		if (t < k) l++;
		else if (t == k) m++;
		else r++;
	}
	
	int ans = 0;
	if (m == 0) m++, ans++;
	if (l <= r) {
		if (l + m >= r) ans += 0;
		else ans += r - l - m;
	}else {	if (r + m > l) ans += 0;
		else ans += l - r - m + 1;
	}

	cout << ans << endl;
	return 0;
}


