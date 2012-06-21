/*
ID:wysovie1
LANG:C++
TASK:telecow
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

const int maxn = 210;
int e[maxn][maxn], a[maxn][maxn];
int n, m, start, end;
int d[maxn], q[maxn], front, rear;

bool bfs() { 
	MS(d, 0);
	q[0] = start;
	d[start] = 1;
	front = rear = 0;
	while (front <= rear) {
		int t = q[front++];
		REP(i, n<<1) if (e[t][i]>0 && !d[i]){
			d[i] = d[t] + 1;
			q[++rear] = i;
			if (i == end) return 1;
		}
	}
	return 0;
}

int dfs(int k, int cur) {
	if (k == end) return cur;
	int ans = 0;
	REP(i, n<<1) if (e[k][i]>0 && d[i]==d[k]+1) {
		int flow = dfs(i, min(cur, e[k][i]));
		ans += flow;
		cur -= flow;
		e[k][i] -= flow;
		e[i][k] += flow;
		if (!cur) break;
	}
	return ans;
}

int dinic() {
	memcpy(e, a, sizeof(a));
	int ans = 0;
	while (bfs()) {
		ans += dfs(start, 2 * maxn); 
	}
	return ans;
}

int main() {
	freopen("telecow.in", "r", stdin);
	freopen("telecow.out", "w", stdout);

	cin >> n >> m >> start >> end;
	start = start-1<<1;
	end = end-1<<1^1;
	REP(i, n) a[i<<1][i<<1^1] = 1;
	a[start][start+1] = maxn;
	a[end-1][end] = maxn;
	REP(i, m) {
		int j, k;
		cin >> j >> k;
		j--, k--;
		a[j<<1^1][k<<1] = maxn;
		a[k<<1^1][j<<1] = maxn;
	}

	int ans = dinic();
	cout << ans << endl;

	REP(i, n) {
		if (i == start>>1 || i == end>>1) continue;
		a[i<<1][i<<1^1] = 0;
		int tmp = dinic();	
		if (tmp == ans - 1) {
			cout << i + 1;
			if (--ans) cout << ' ';
			else cout << endl;
		}else a[i<<1][i<<1^1] = 1;
	}
	return 0;
}


