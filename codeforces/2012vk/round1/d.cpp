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

using namespace std;

int f[50010][510];
vector<int> e[50010];
long long ans;
int n, k;

int gao(int x, int p) {
	f[x][0]++;
	TR(i, e[x]) { 
		if (*i == p) continue;
		gao(*i, x);
		REP(j, k) ans += 1LL * f[x][j] * f[*i][k-j-1];
		REP(j, k) f[x][j + 1] += f[*i][j];
	}
}

int main() {

	cin >> n >> k;
	REP(p, n - 1) {
		int i, j;
		scanf("%d%d", &i, &j);
		e[i].PB(j);
		e[j].PB(i);
	}
	gao(1, -1);
	cout << ans << endl;
	return 0;
}


