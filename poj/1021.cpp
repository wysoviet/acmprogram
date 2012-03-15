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

#define REP(i, a, b) for (int i = a; i <= b; i++)
#define TR(it, a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define ALL(a) a.begin(),a.end()
#define PB(i) push_back(i)
#define MS(a, i) memset(a, i, sizeof(a))
#define DEB(x) cout << #x << " : " << x << endl
#define DEBA(a, n) REP(i, 0, n - 1) cout << #a << "[" << i << "] : " << a[i] << endl;

using namespace std;

const int maxn = 100 + 10;

bool a[maxn][maxn];
int d1[maxn * maxn], d2[maxn * maxn];
int w, h, n;

void gao(int d[]){
	MS(a, 0);
	int i, j, k;
	REP(k, 0, n - 1){
		scanf("%d%d", &i, &j);
		a[i + 1][j + 1] = 1;
	}
	int s = 0, t;
	REP(i, 1, w) REP(j, 1, h)
		if (a[i][j]) {
			t = 0;
			for (k = i + 1; k <= w && a[k][j]; k++) t++;
			for (k = i - 1; k && a[k][j]; k--) t++;
			for (k = j + 1; k <= h && a[i][k]; k++) t++;
			for (k = j - 1; k  && a[i][k]; k--) t++;
			d[s++] = t;
		}
	sort(d, d + n);
}

int main(){
	int T;

	scanf("%d", &T);
	while (T--){
		scanf("%d%d%d", &w, &h, &n);
		gao(d1); gao(d2);
		bool flag = 1;
		REP(i, 0, n - 1) flag = flag && (d1[i] == d2[i]);
		if (flag) puts("YES");
		else puts("NO");
	}

	return 0;
}


