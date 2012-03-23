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

const int maxn = 5000 + 10;
int s[maxn], a[maxn];

int sum(int x) {
	int ret = 0;
	for (; x; x -= x & -x)
		ret += s[x];
	return ret;
}

int add(int x) {
	for ( ; x < maxn; x += x & -x)
		 s[x]++;
}

int main() {
	int n;

	while (~scanf("%d", &n)) {
		MS(s, 0);
		int t, ss = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &t);
			ss += i - 1 - sum(t + 1);
			a[i] = t, add(t + 1);
		}
		int ret = n * n;
		for (int i = 1; i <= n; i++) {
			ss = ss - a[i] + n - a[i] - 1;
			ret = min(ret, ss);
		}
		printf("%d\n", ret);
	}

	return 0;
}


