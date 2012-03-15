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

const int maxn = 210;
int y[maxn];
bool flag[maxn], e[maxn][maxn];
int m, n;

bool find(int x) {
	REP(i, 1, m) if (e[x][i] && !flag[i]) {
		flag[i] = 1;
		if (y[i] == -1 || find(y[i])) {
			y[i] = x;
			return 1;
		}
	}
	return 0;
}

				
int main(){
	freopen("stall4.in", "r", stdin);
	freopen("stall4.out", "w", stdout);

	cin >> n >> m;

	REP(i, 1, n) {
		int k, j;
		cin >> k;
		while (k--) { cin >> j; e[i][j] = 1;}
	}

	MS(y, -1);
	
	int ans = 0;
	
	REP(i, 1, n) {
		MS(flag, 0);
		ans += find(i);
	}
	
	cout << ans << endl;
	return 0;
}


