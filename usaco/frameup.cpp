/*
ID:wysovie1
LANG:C++
TASK:frameup
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

char g[40][40];
bool e[26][26];
bool v[26];
pair<int, int> a[26][2];
int h, w, d[26];
char ans[27];
int n;
vector<string> s;

int cnt;
void gao(int k) {
	if (k == n) {
		ans[n] = 0;
		s.PB(ans);
		return;
	}
	bool t[26];
	int td[26];
	REP(i, 26) if(d[i] == 1) {
		ans[k] = i + 'A';
		memcpy(t, e[i], sizeof(e[i]));
		memcpy(td, d, sizeof(d));
		REP(j, 26) d[j] -= e[i][j], e[i][j] = 0;
		gao(k + 1);
		memcpy(e[i], t, sizeof(t));
		memcpy(d, td, sizeof(td));
	}
}

int main() {
	freopen("frameup.in", "r", stdin);
	freopen("frameup.out", "w", stdout);

	cin >> h >> w;
	REP(i, 26) {
		a[i][0] = MP(40, 40);
		a[i][1] = MP(-1, -1);
	}

	REP(i, h) {
		cin >> g[i];
		REP(j, w) if (g[i][j] >= 'A' && g[i][j] <= 'Z') {
			g[i][j] -= 'A';
			int t = g[i][j];
			v[t] = 1;
			a[t][0] = MP(min(a[t][0].first, i), min(a[t][0].second, j)); 
			a[t][1] = MP(max(a[t][1].first, i), max(a[t][1].second, j)); 
		}
	}

	REP(p, 26) if (v[p]) {
		pair<int, int> t1 = a[p][0], t2 = a[p][1];
		for (int i = t1.first; i <= t2.first; i++)
			e[g[i][t1.second]][p] = e[g[i][t2.second]][p] = 1;
		for (int i = t1.second; i <= t2.second; i++)
			e[g[t1.first][i]][p] = e[g[t2.first][i]][p] = 1;
	}
	
	REP(i, 26) n += e[i][i];
	REP(i, 26) REP(j, 26) d[i] += e[j][i];

	gao(0);
	
	TR(i, s) reverse(i->begin(), i->end());
	sort(s.begin(), s.end());
	TR(i, s) cout << *i << endl;
	return 0;
}

