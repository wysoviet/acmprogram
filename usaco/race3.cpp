/*
ID:wysovie1
LANG:C++
TASK:race3
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

using namespace std;

const int maxn = 50;
bool v[maxn], v2;
bool e[maxn][maxn], f[maxn][maxn];
vector<int> ans1, ans2;
int n;

void gao(int x) {
	memcpy(f, e, sizeof(e));
	REP(i, n) f[x][i] = 0;
	REP(k, n) REP(i, n) REP(j, n)
		f[i][j] = f[i][j] || f[i][k] && f[k][j];
	if (!f[0][n-1]) {
		ans1.PB(x);
		MS(v, 0);
		REP(i, n) if (f[0][i] && f[i][x]) v[i] = 1;
		v[0] = v[x] = 1;
		bool flag = 1;
		REP(i, n) if (v[i] && i != x) REP(j, n)
			if (e[i][j] && !v[j]) flag = 0;
		if (!flag) return;
		memcpy(f, e, sizeof(e));
		REP(i, n) f[i][x] = 0;
		REP(k, n) REP(i, n) REP(j, n)
			f[i][j] = f[i][j] || f[i][k] && f[k][j];
		REP(i, n) if (i != x && f[x][i] && f[i][n-1] && v[i]) 
			flag = 0; 
		if (!flag) return;
		v[n - 1] = v[x] = 0;
		REP(i, n) if (!v[i]) REP(j, n)
			if (e[i][j] && v[j]) flag = 0;
		if (!flag) return;
		ans2.PB(x);
	}
}

int main() {
	int t;

	freopen("race3.in", "r", stdin);
	freopen("race3.out", "w", stdout);

	while (scanf("%d", &t), ~t) {
		e[n][t] = 1;
		while (t != -2) { 
			e[n][t] = 1;
			scanf("%d", &t);
		}
		n++;
	}

	for (int i = 1; i < n - 1; i++)
		gao(i);

	cout << ans1.size();
	TR(i, ans1) cout << " " << *i;
	cout << endl << ans2.size();
	TR(i, ans2) cout << " " << *i;
	cout << endl;
	return 0;
}


