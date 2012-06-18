/*
ID:wysovie1
LANG:C++
TASK:betsy
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

const int maxn = 8;
int f[2][maxn][1<<2*maxn];
int n; 

int gao3(int y, int m) {
	int s = 0;
	for (int i = 2*y+4; i<2*n+2; i += 2) {
		if ((m >> i & 3) == 2) s++;
		else if ((m >> i & 3)==3) s--;
		if (s < 0) return i;
	}
}

int gao2(int y, int m) {
	int s = 0;
	for (int i = 2*y-2; i >= 0; i -= 2) {
		if ((m >> i & 3) == 3) s++;
		else if ((m>> i & 3) == 2) s--;
		if (s < 0) return i;
	}
}

void gao(int x, int y, int m) {
	int tx = x & 1;
	int t1 = m >> (2*y) & 3, t2 = m >> 2*(y+1) & 3;
	if (t1 == 0 && t2 == 0) {
		if (x!=1 || y!=0) f[tx][y+1][m|14<<(2*y)] += f[tx][y][m];
		else {
			f[tx][y+1][m|1<<(2*y)] += f[tx][y][m];
			f[tx][y+1][m|4<<(2*y)] += f[tx][y][m];
		}
	}else if (t1==0 || t2==0) {
		int s = ((t1+t2)*5)<<2*y;
		f[tx][y+1][m^s] += f[tx][y][m];
		f[tx][y+1][m] += f[tx][y][m];
	}else if (t1*t2==2) {
		int s, i = gao3(y, m);
		s = m ^ ((m>>2*y&15)<<2*y) ^ (2 << i);
		f[tx][y+1][s] += f[tx][y][m];
	}else if (t1*t2==3) {
		int s, i = gao2(y, m);
		s = m ^ ((m>>2*y&15)<<2*y) ^ (3 << i);
		f[tx][y+1][s] += f[tx][y][m];
	}else if (t1==3 && t2==2){
		f[tx][y+1][m^((m>>2*y&15)<<2*y)] += f[tx][y][m];
	}else if (t1==t2) {
		int s, i; 
		if (t1 == 2) i = gao3(y, m);
		else i = gao2(y, m);
		s = m ^ ((m>>2*y&15)<<2*y) ^ (1 << i);
		f[tx][y+1][s] += f[tx][y][m];
	}
}

int main() {
	freopen("betsy.in", "r", stdin);
	freopen("betsy.out", "w", stdout);

	cin >> n;
	f[0][n][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 1<<2*n; j++)
			 if (f[i-1&1][n][j])
				 f[i&1][0][j<<2] = f[i-1&1][n][j];
		MS(f[i-1&1], 0);
		for (int j = 0; j < n; j++)
			for (int k = 0; k < 1<<2*n+2; k++)
				if (f[i&1][j][k]) gao(i, j, k);
	}

	cout << f[n&1][n][1] << endl;
	return 0;
}


