/*
ID:wysovie1
LANG:C++
TASK:charrec
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

const int inf = 1e9;
char font[30][30][30], s[1300][30];
char tab[30] = " abcdefghijklmnopqrstuvwxyz";
int dif[1300][30][30], cost[30][30], f[1300], e[1300], l[1300];
int front[30], rear[30];
int n, N;

int gao(int x, int y, int k) {
	front[0] = rear[0] = 0; 
	int l = k==21?k-1:k;
	for (int i = 1;  i <= l; i++) {
		front[i] = front[i-1] + dif[x-k+i][y][i-1];
		rear[i] = rear[i-1] + dif[x-i+1][y][20-i];
	}
	if (k == 20) return front[20];
	int m = inf;
	for (int i = 0; i <= l; i++) 
		m = min(m, front[i]+rear[l-i]);
	return m;
}

void gaop(int k) {
	if (k < 0) return;
	gaop(k - l[k]);
	putchar(tab[e[k]]);
}

int main() {
	freopen("font.in", "r", stdin);
	scanf("%d", &N);
	REP(i, 27) REP(j, 20) scanf("%s", font[i][j]);
	freopen("charrec.in", "r", stdin);
	freopen("charrec.out", "w", stdout);
	scanf("%d", &n);
	REP(i, n) scanf("%s", s[i]);
	
	REP(i, n) REP(j, 27) REP(k, 20) REP(p, 20)
		dif[i][j][k] += (s[i][p] != font[j][k][p]);
	
	fill(f, f + n, inf);
	for (int i = 18; i < n; i++) 
		REP(j, 27) for (int k = 19; k <= 21; k++) 
			if (i - k >= -1) {
				int t = i-k<0?0:f[i-k], tg = gao(i, j, k);
				if (t + tg < f[i]) {
					f[i] = t + tg;
					e[i] = j; l[i] = k;
				}
			}
		

	gaop(n-1);
	puts("");
	return 0;
}


