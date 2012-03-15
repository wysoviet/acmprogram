/*
ID:wysovie1
LANG:C++
TASK:ditch
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

#define lowbit(x) ((x)&(-(x)))
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define REPD(i, b, a) for (int i = b; i >= a; i--)
#define TR(it, a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define ALL(a) a.begin(),a.end()
#define PB(i) push_back(i)
#define MS(a, i) memset(a, i, sizeof(a))
#define DEB(x) cout << #x << " : " << x << endl
#define DEBA(a, n) REP(i, 0, n - 1) cout << #a << "[" << i << "] : " << a[i] << endl

using namespace std;

const int maxn = 300;
const int maxm = 300000;
const int inf = 0x7fffffff;
struct node {
	int v, next, val;
}s[maxm * 2];

int level[maxm], p[maxm], que[maxm], out[maxm], ind;
void init(){
	ind = 0;
	MS(p, -1);
}

inline void insert(int x, int y, int z){
	s[ind].v = y;
	s[ind].val = z;
	s[ind].next = p[x];
	p[x] = ind++;
	s[ind].v = x;
	s[ind].val = 0;
	s[ind].next = p[y];
	p[y] = ind++;
}

int max_flow(int n, int source, int sink) {
	int ret = 0, h, r;
	while (1) {
		MS(level, 0);
		h = r = 0;
		level[source] = 1;
		que[0] = source;
		while (h <= r) {
			int t = que[h++];
			for (int i = p[t]; ~i; i = s[i].next) 
				if (s[i].val && level[s[i].v] == 0) {
					level[s[i].v] = level[t] + 1;
					que[++r] = s[i].v;
				}
		}
		if (level[sink] == 0) break;
		for (int i = 0; i < n; i++) out[i] = p[i];
		int q = -1;
		while (1) { 
			if (q < 0) {
				int cur = out[source];
				for (; ~cur; cur = s[cur].next) 
					if (s[cur].val && ~out[s[cur].v] && level[s[cur].v] == 2) break;
				if (cur >= 0) {
					que[++q] = cur;
					out[source] = s[cur].next;
				}else break;
			}
			int u = s[que[q]].v;
			if (u == sink) { 
				int dd = inf, index = -1;
				for (int i = 0; i <= q; i++) 
					if (dd > s[que[i]].val) {
						dd = s[que[i]].val;
						index = i;
					}
				ret += dd;
				for (int i = 0; i <= q; i++) {
					s[que[i]].val -= dd;
					s[que[i]^1].val += dd;
				}
				q = index - 1;
			}else { int cur = out[u];
				for (; ~cur; cur = s[cur].next) 
					if (s[cur].val && ~out[s[cur].v] && level[u] + 1 == level[s[cur].v]) break;
				if (~cur) {
					que[++q] = cur;
					out[u] = s[cur].next;
				}else { out[u] = -1, q--;}
			}
		}
	}
	return ret;
}

int n, m;

int main(){
//	freopen("ditch.in", "r", stdin);
//	freopen("ditch.out", "w", stdout);

	scanf("%d%d", &m, &n);
	init();
	for (int i = 0; i < m; i++) {
		int from, to, cost;
		scanf("%d%d%d", &from, &to, &cost);
		insert(from, to, cost);
	}
	
	cout << max_flow(n, 1, n) << endl;
	return 0;
}


