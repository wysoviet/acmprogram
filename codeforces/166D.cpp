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

const int maxn = 1e5 + 10;
struct node{
 	int c, s, idx;
	bool operator < (const node &a) const { return c > a.c; }
}a[maxn];
int g[maxn];
map<int, int> s;
vector<int> e[maxn];
bool flag[maxn];

bool gao(int x) {
	TR(i, e[x]) if (!flag[*i]){
		flag[*i] = 1;	
		if (g[*i] == -1 || gao(g[*i])) {
			g[*i] = x;
			return 1;
		}
	}
	return 0;
}

int main() {
	int n, m;

	cin >> n;
	REP(i, n) {
		scanf("%d%d", &a[i].c, &a[i].s);
		a[i].idx = i; 
	}

	sort(a, a + n);
	REP(i, n) s[a[i].s] = i;

	cin >> m;
	REP(i, m) {
		int cost, size;
		scanf("%d%d", &cost, &size);
		if (s.count(size) && a[s[size]].c <= cost) 
			e[s[size]].PB(i);
	
		if (s.count(size+1) && a[s[size+1]].c <= cost)
			e[s[size+1]].PB(i);
	}

	long long ans = 0;
	int cnt = 0;

	MS(g, -1);
	REP(i, n) { MS(flag, 0); if (gao(i)) {ans += a[i].c; cnt++;} }
	cout << ans << endl << cnt << endl;
	REP(i, m) if (~g[i]) cout << i + 1 << " " << a[g[i]].idx + 1 << endl;	
	return 0;
}
