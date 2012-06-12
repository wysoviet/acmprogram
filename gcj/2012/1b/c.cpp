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
int T, a[21];
const int maxn = 21000000;
vector<int> b[maxn];

int main() {
	freopen("C-large.in", "r", stdin);
	freopen("c.ans", "w", stdout);

	int n;

	cin >> T;
	
	int cnt = 0;
	for (int ca = 1; ca <= T; ca++) {
		cin >> n;
		REP(i, n) cin >> a[i];
		REP(i, maxn) b[i].clear(); 
		bool flag = 0;
		int a1, b1;
		for (int i = 1; i < (1<<20); i++) {
			int s = 0;
			for (int j = 0; j < 20; j++)
				if (i >> j & 1) s += a[j];
			TR(it, b[s]) if (((*it) & i) == 0) {
				flag = 1;			
				a1 = *it, b1 = i;
				break;
			}
			if (flag) break;
			b[s].PB(i);
		}
		printf("Case #%d:\n", ca);
		if (!flag) puts("Impossible");
		else { vector<int> ans1, ans2; 
			REP(i, 20) if (a1 >> i & 1) ans1.PB(a[i]);
			REP(i, 20) if (b1 >> i & 1) ans2.PB(a[i]);
			REP(i, ans1.size()) if (i < ans1.size()-1)
				printf("%d ", ans1[i]);
			else printf("%d\n", ans1[i]);
			REP(i, ans2.size()) if (i < ans2.size()-1)
				printf("%d ", ans2[i]);
			else printf("%d\n", ans2[i]);
		}
	}
	return 0;
}


