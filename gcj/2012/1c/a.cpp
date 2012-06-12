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

const int maxn = 2000;
vector<int> e[maxn];
int v[maxn];
int n;
bool flag;

void gao(int x) {
	v[x] = 1;
	TR(i, e[x]) if (v[*i]) flag = 1;
	else gao(*i); 
}

bool solve(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int t, p;
		e[i].clear();
		cin >> t;
		REP(j, t) {
			cin >> p;
			e[i].PB(p);
		}
	}
	
	flag = 0;
	for (int i = 1; i <= n && !flag; i++) {
		MS(v, 0);
		gao(i);
		if (flag) return 1;
	}
	return 0;
}

int main() {
	//freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-large.in", "r", stdin);
	freopen("a.ans", "w", stdout);

	int T;
	cin >> T;
	REP(ca, T) {
		printf("Case #%d: ", ca + 1);
		bool ans = solve();
		if (ans) puts("Yes");
		else puts("No");
	}
	return 0;
}


