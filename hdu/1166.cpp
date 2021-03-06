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

const int maxn = 50000 + 10;
int s[maxn];

int sum(int x) {
	int ret = 0;
	for (; x; x -= x & -x) 
		ret += s[x];
	return ret;
}

void add(int x, int t) {
	for (; x < maxn; x += x & -x) 
		s[x] += t;
}
int main() {
	int T, cas = 0;

	scanf("%d", &T);
	while (T--) {
		printf("Case %d:\n", ++cas);
		int n, t, x, y;
		MS(s, 0);
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &t);
			add(i, t);
		}
		char s[10];
		while (1) {
			scanf("%s", s);
			if (*s == 'E') break;
			scanf("%d%d", &x, &y);
			if (*s == 'Q') printf("%d\n", sum(y) - sum(x - 1));
			else if (*s == 'A') add(x, y);
			else  add(x, -y);
		}
	}

	return 0;
}


