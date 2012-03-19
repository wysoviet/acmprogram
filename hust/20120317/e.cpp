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

int n, m;
vector<int> e[10010];
vector< pair<int, int> > a;
int ans[10010];
bool v[10010];
int cur, cnt;

void gao(int x, int p, int s, int &t) {
	cnt++, v[x] = 1;
	if (s > cur) t = x, cur = s; 
	TR(i, e[x]) if (*i != p) 
		gao(*i, x, s + 1, t);
}
		
int main() {
	int T, cas = 0;
	cin >> T;

	while (T--) {
		scanf("%d%d", &n, &m);
		REP(i, n + 1) e[i].clear();
		a.clear();
		REP(i, m) {
			int x, y;
			scanf("%d%d", &x, &y);
			e[x].PB(y), e[y].PB(x);
		}
		int x, y;

		for (int i = 1; i <= n; i++)
			if (!v[i]) {
				cur = cnt = 0;
				gao(i, -1, 1, x);
				cur = cnt = 0;
				gao(x, -1, 1, y);
				a.PB(MP(-cur, cnt));
			}	
		sort(ALL(a));
		TR(i, a) i->FI = -(i->FI);
		int l = 0;
		MS(ans, -1);
		TR(i, a) {
			for (int j = l + 1; j <= i->SE; j++) 
				if (j <= i->FI) ans[j] = j - 1;
				else ans[j] = (j - i->FI) * 2 + i->FI - 1;
			l = i->SE;
		}
		
		scanf("%d", &l);
		printf("Case %d\n", ++cas);
		while (l--) {
			int t;
			scanf("%d", &t);
			if (ans[t] == -1) puts("impossible");
			else printf("%d\n", ans[t]);
		}
	}

	return 0;
}


