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

int v[9][9];
char s[3];
int gx, gy, tx, ty, t;
const int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
const int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};
int sx[100], sy[100], st[100];

int main(){
	cin >> s;
	gx = s[0] - 'a' + 1;
	gy = s[1] - '0';
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> s;
		tx = s[0] - 'a' + 1;
		ty = s[1] - '0';
		v[tx][ty] = 1;
	}

	if (gx == 1 && gy == 1) {cout << 0 << endl; return 0;}
	int h = -1, q = 0;
	sx[0] = sy[0] = v[1][1] = 1;	
	st[0] = 0;
	while (h < q) {
		++h;
		for (int i = 0; i < 8; i++){
			tx = sx[h] + dx[i];
			ty = sy[h] + dy[i];
			t = st[h] + 1;
			if (tx < 1 || tx > 8) continue;
			if (ty < 1 || ty > 8) continue;
			if (v[tx][ty]) continue;
			v[tx][ty] = 1;
			if (tx == gx && ty == gy) { cout << t << endl; return 0;}
			q++;
			sx[q] = tx, sy[q] = ty, st[q] = t;
		}
	}

	cout << "not reachable" << endl;
	return 0;
}

//f1 10 c1 c2 c3 c4 c5 d1 d2 d3 d4 d5
