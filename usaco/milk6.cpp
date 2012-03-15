/*
ID:wysovie1
LANG:C++
TASK:milk6
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

const int maxn = 40;
const int maxm = 1001;
const int inf = ~0U>>1;

struct node{
	int v, val, next;
	node(int a =0, int b = 0, int c = 0) {v = a, val = b, next = c;}
}e[maxm * 2], a[maxm * 2];
int p[maxm], ind, s[maxm], level[maxm], que[maxm];
int n, m;

void insert(int x, int y, int z) {
	a[ind] = node(y, z, p[x]); p[x] = ind++;
	a[ind] = node(x, 0, p[y]); p[y] = ind++;
}



long long max_flow(int n, int source, int sink) {
	int h, t, cur;
	long long ret = 0;;
	while (1) {
		h = t = 0; 
		MS(level, 0);
		level[source] = 1;
		que[0] = source;
		while (h <= t) {
			cur = que[h++];
			for (int i = p[cur]; ~i; i = e[i].next) 
				if (e[i].val && !level[e[i].v]) {
					level[e[i].v] = level[cur] + 1;
					que[++t] = e[i].v;
				}
		}

		if (!level[sink]) break;
		t = -1;
		for (int i = 0; i <= n; i++) s[i] = p[i];
		while (1) {
			if (t < 0) {
				cur = s[source];
				for (; ~cur; cur = e[cur].next) 
					if (e[cur].val && ~s[e[cur].v] 
					&& level[e[cur].v] == 2) break;
				if (cur == -1) break;
				que[++t] = cur;
				s[source] = e[cur].next;
			}
			int u = e[que[t]].v;
			if (u == sink) {
				int dd = inf, idx = -1;
				REP(i, t + 1) if (dd > e[que[i]].val) {
					dd = e[que[i]].val;
					idx = i;
				}
				ret += dd;
				REP(i, t + 1) {
					e[que[i]].val -= dd;
					e[que[i] ^ 1].val += dd;
				}
				t = idx - 1;
			}else { cur = s[u];
				for (; ~cur; cur = e[cur].next) 
					if (e[cur].val && ~s[e[cur].v] 
			        && level[u] + 1 == level[e[cur].v]) break;
				if (~cur) { que[++t] = cur;
					    s[u] = e[cur].next;
				}else {s[u] = -1, t--;}
			}
		}
	}
	return ret;
}
int main() {
	freopen("milk6.in", "r", stdin);
	freopen("milk6.out", "w", stdout);

	cin >> n >> m;
	int i, j, k;
	MS(p, -1);
	REP(t, m) {
		cin >> i >> j >> k;
		insert(i, j, k * 1001 + 1);
	}

	memcpy(e, a, sizeof(a));
	long long maxf = max_flow(n, 1, n);
	cout << maxf / 1001 << " ";
	vector<int> ans;
	for (int i = 0; i < ind; i+=2) {
		memcpy(e, a, sizeof(a));
		e[i].val = 0;
		long long tf = max_flow(n, 1, n);
		if (maxf - tf == a[i].val) {
			a[i].val = 0;
			maxf = tf;
			ans.PB(i/2 + 1);
		}
	}
	
	cout << ans.size() << endl;;
	TR(i, ans) cout << *i << endl;
	return 0;
}


