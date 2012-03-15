/*
ID:wysovie1
LANG:C++
TASK:prime3
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
#define DEB(x) cout << #x << " : " << x << endl
#define DEBA(a, n) REP(i, n) cout << #a << "[" << i << "] : " << a[i] << endl

using namespace std;

int a[5][5], sy[5];
int f[10000], fd[10000];
vector<int> tmp;

int n, sum;

void gao2(){
	if (sum++) puts("");
	REP(i, 5){ REP(j, 4) printf("%d", a[i][j]);
		printf("%d\n", a[i][4]);
	}
}

void gao(int x, int y, int s, int sd1, int sd2) {
	if (x == 5) {gao2(); return;}
	if (y == 5) {gao(x + 1, 0, 0, sd1, sd2); return;}
	int t = f[s] & f[sy[y]], d1 = (x == y), d2 = (x + y == 4);
	if (d1) t &= f[sd1];
	if (d2) t &= fd[sd2];

	for (int i = 0; i < 10 && t; i++, t >>= 1)
		if (t & 1) {
			sy[y] = sy[y] * 10 + i;
			a[x][y] = i;
			gao(x, y + 1, s * 10 + i, 
			 d1?sd1*10+i:sd1, d2?sd2*10+i:sd2);
			sy[y] /= 10;
		}
}

int main() {
	freopen("prime3.in", "r", stdin);
	//freopen("prime3.out", "w", stdout);

	cin >> n >> a[0][0];

	for (int i = 10000; i < 100000; i++) {
		bool flag = 1;
		for (int j = 2; j * j <= i && flag; j++)
			if (i % j == 0) flag = 0;
		int s = 0, t1, t2;
		tmp.clear();
		for (int j = i; j; j /= 10) 
			s += j % 10, tmp.PB(j % 10);
		if (flag && s == n) {
			t1 = t2 = 0;
			REP(j, 5) { 
				fd[t1] |= 1 << tmp[j];
				t1 = t1 * 10 + tmp[j];
				f[t2] |= 1 << tmp[4 - j];
				t2 = t2 * 10 + tmp[4 - j];
			}	
		}
	}

	sy[0] = a[0][0];
	gao(0, 1, a[0][0], a[0][0], 0);
	if (!sum) cout << "NONE" << endl;
	return 0;
}


