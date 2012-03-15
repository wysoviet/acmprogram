/*
ID:wysovie1
LANG:C++
TASK:stall4
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

const int maxn = 600;
const int maxm = 40000;
const int inf = 0x7fffffff;

struct node{
	int v, val, next;
	node(int a = 0, int b = 0, int c = 0) {v = a, val = b, next = c;}
}e[maxm * 2];
int p[maxn], ind, s[maxn], level[maxn], que[maxm];

void insert(int x, int y, int z) {
	e[ind] = node(y, z, p[x]); p[x] = ind++;
	e[ind] = node(x, 0, p[y]); p[y] = ind++;
}

int max_flow(int n, int source, int sink) {
	int h, t, cur, ret = 0;;
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
				REP(i, 0, t) if (dd > e[que[i]].val) {
					dd = e[que[i]].val;
					idx = i;
				}
				ret += dd;
				REP(i, 0, t) {
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

int main(){
	int m, n, k, j;

	freopen("stall4.in", "r", stdin);
	freopen("stall4.out", "w" , stdout);
	
	ind = 0; MS(p, -1);
	cin >> n >> m;
	REP(i, 1, n) {
		cin >> k;
		while (k--) { cin >> j; insert(i, n + j, 1); }
	}
	REP(i, 1, n) insert(0, i, 1);
	REP(i, 1, m) insert(i + n, n + m + 1, 1);
	cout << max_flow(m + n + 1, 0, m + n + 1) << endl;
	return 0;
}


