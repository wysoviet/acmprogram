/*
ID:wysovie1
LANG:C++
TASK:snail
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

const int maxn = 130; 
int v[maxn][maxn];
int n, b;
char s[10];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int ans;

int cnt = 0;
void gao(int x, int y, int d, int s) {
	v[x][y]= -1;
	int tx = x + dx[d], ty = y + dy[d];
	if (v[tx][ty] == 0) { gao(tx, ty, d, s+1); v[x][y]=0; return; }
	else if (v[tx][ty] == -1) { ans = max(ans, s); v[x][y]=0;return; }
	bool flag = 0;
	for (int i = 3; i<=5; i+=2) {
		tx = x + dx[(d+i)%4], ty = y + dy[(d+i)%4];
		if (v[tx][ty] == 0) {
			flag = 1;
			gao(tx, ty, (d+i)%4, s+1);
		}
	}
	if (!flag) ans = max(ans, s);
	v[x][y] = 0;
}

int main() {
	char *p;
	freopen("snail.in", "r", stdin);
	freopen("snail.out", "w", stdout);

	cin >> n >> b;
	for (int i = 0; i <= n + 1; i++) 
		v[0][i] = v[n + 1][i] = v[i][0] = v[i][n + 1] = 1;
	REP(i, b) {
		cin >> s;
		int t = 0;
		for (p=s+1; *p; p++) t = t * 10 + (*p) - '0';
		v[t][s[0]-'A'+1] = 1;
	}
	
	gao(1, 1, 0, 1);
	gao(1, 1, 1, 1);
	cout << ans << endl;
	return 0;
}


