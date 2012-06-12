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

#define lowbit(x) ((x)&(-(x)))

using namespace std;

const int maxn = 3e5;
int s[maxn], p[maxn];

void add(int x, int t) {
	for (; x < maxn; x += lowbit(x))
		s[x] += t;
}

int sum(int x) {
	int ret = 0;
	for (; x; x -= lowbit(x))
		ret += s[x];
	return ret;
}

int main() {
	int T, n, m, t;
	cin >> T;

	while (T--) {
		scanf("%d%d", &n, &m);
		int top = 1.5e5;
		MS(s, 0); MS(p, 0);
		for (int i = 1; i <= n; i++)
			p[i] = top + i, add(top + i, 1);
		for (int i = 1; i <= m; i++) {
			scanf("%d", &t);
			printf("%d", sum(p[t] - 1));
			if (i != m) putchar(' ');
			else puts("");
			add(p[t], -1);	
			p[t] = top--;
			add(p[t], 1);
		}
	}

	return 0;
}


