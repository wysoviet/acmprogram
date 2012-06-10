/*
ID:wysovie1
LANG:C++
TASK:schlnet
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

const int maxn = 200;
int id[maxn], low[maxn], ins[maxn], tim[maxn];
int outd[maxn], ind[maxn], root, leaf;
int s[maxn], ns, idx;
vector<int> e[maxn];
int n, scc, t;

int cnt;
void gao(int x) {
	tim[x] = low[x] = ++idx;
	s[ns++] = x;
	ins[x] = 1;
	TR(it, e[x]) if (!tim[*it]) {
		gao(*it);
		low[x] = min(low[x], low[*it]);
	}else if (ins[*it]) low[x] = min(low[x], low[*it]);
	if (low[x] == tim[x]) {
		scc++;
		do {
			id[s[--ns]] = scc;
			ins[s[ns]] = 0;
		}while(s[ns] != x);
	}
}

int main() {
	freopen("schlnet.in", "r", stdin);
	freopen("schlnet.out", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		while (scanf("%d", &t), t) {
			e[i].PB(t);
		}
	}
	
	for (int i = 1; i <= n; i++) 
		if (!tim[i]) gao(i);
	
	for (int i = 1; i <= n; i++) 
		TR(it, e[i]) if (id[i] != id[*it])
			ind[id[*it]]++, outd[id[i]]++;

	for (int i = 1; i <= scc; i++) {
		if (ind[i] == 0) root++;
		if (outd[i] == 0) leaf++;
	}
	cout << root << endl;
	if (scc==1) cout << 0 << endl;
	else cout << max(leaf,root) << endl;
	return 0;
}


