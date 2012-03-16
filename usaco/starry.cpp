/*
ID:wysovie1
LANG:C++
TASK:starry
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

vector< vector<int> > a[510];
int w, h;
char tmp[110];
int g[110][110], f[510];
const int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
const int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};

void gao(int x, int y, int c) {
	int tx, ty;
	g[x][y] = c;
	REP(i, 8) {
		tx = x + dx[i], ty = y + dy[i];
		if (g[tx][ty] == 1) gao(tx, ty, c);
	}
}

int main() {
	freopen("starry.in", "r", stdin);
	freopen("starry.out", "w", stdout);

	cin >> w >> h;
	for (int i = 1; i <= h; i++) {
		scanf("%s", tmp + 1);
		for (int j = 1; j <= w; j++) 
			g[i][j] = tmp[j] - '0';
	}

	int c = 1;
	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= w; j++)
			if (g[i][j] == 1) gao(i, j, ++c);
			
	for (int i = 1; i <= h; i++) 
		for (int j = 1; j <= w; j++) 
			if (g[i][j]) {
				int t = 0, tc = g[i][j];
				vector<int> tmp;
				for (int p = i + 1; g[p][j] == tc; p++, t++); tmp.PB(t), t = 0;
				for (int p = i - 1; g[p][j] == tc; p--, t++); tmp.PB(t), t = 0;
				for (int p = j + 1; g[i][p] == tc; p++, t++); tmp.PB(t), t = 0;
				for (int p = j - 1; g[i][p] == tc; p--, t++); tmp.PB(t), t = 0;
				sort(ALL(tmp));
				a[tc].PB(tmp);
			}

	for(int i = 2; i <= c; i++)
		sort(ALL(a[i])); 

	int cur = 0;
	for (int i = 2; i <= c; i++) if (!f[i]) {
		f[i] = ++cur;
		for (int j = i + 1; j <= c; j++) 
			if (a[i] == a[j]) f[j] = cur;
		
	}
	
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++)
			if (g[i][j]) printf("%c", f[g[i][j]] + 'a' - 1);
			else printf("0");
		puts("");
	}

	return 0;
}


