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
#define FI first
#define SE second

using namespace std;

void gao1(int a[4][4]) {
	int t = a[0][1];
	a[0][1] = a[1][3]; 
	a[1][3] = a[3][2];
	a[3][2] = a[2][0];
	a[2][0] = t;
}

void gao2(int a[4][4]) {
	int t = a[0][2];
	a[0][2] = a[2][3];
	a[2][3] = a[3][1];
	a[3][1] = a[1][0];
	a[1][0] = t;
}

void gao3(int a[4][4]) {
	int t = a[1][1];
	a[1][1] = a[1][2];
	a[1][2] = a[2][2];
	a[2][2] = a[2][1];
	a[2][1] = t;
}

void gao4(int a[4][4]) {
	int t = a[0][0];
	a[0][0] = a[0][3];
	a[0][3] = a[3][3];
	a[3][3] = a[3][0];
	a[3][0] = t;
}

bool gao(int a[4][4]) {
	return a[0][0] == a[0][1] && a[0][1] == a[1][1] && a[1][1] == a[1][0] && a[0][2] == a[0][3] && a[0][3] == a[1][3] && a[1][3] == a[1][2] &&
 a[2][0] == a[2][1] && a[2][1] == a[3][1] && a[3][1] == a[3][0] &&
 a[2][2] == a[2][3] && a[2][3] == a[3][3] && a[3][3] == a[3][2];
}

int main() {
	int ans = 0x7fffffff;
	int b[4][4], a[4][4];
	const int c[4] = {0, 1, 2, 1};

	REP(i, 4) REP(j, 4) cin >> a[i][j];
	REP(t1, 4) REP(t2, 4) REP(t3, 4) REP(t4, 4) {
		memcpy(b, a, sizeof(a));
		REP(i, t1) gao1(b);
		REP(i, t2) gao2(b);
		REP(i, t3) gao3(b);
		REP(i, t4) gao4(b);
		if (gao(b)) ans = min(ans, c[t1]+c[t2]+c[t3]+c[t4]);
	}
	cout << ans << endl;
	return 0;
}


