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

const int maxn = 3000;
pair<int,int> s[maxn];
int a[maxn], b[maxn], c[maxn];
int n;

int main() {
	int T;
	

	freopen("in.in", "r", stdin);
	freopen("b.ans", "w", stdout);

	cin >> T;
	
	for (int ca = 1; ca <= T; ca++) {
		cin >> n;
		REP(i, n) cin >> s[i].FI >> s[i].SE;
		REP(i, n) s[i].SE = -s[i].SE;
		sort(s, s + n);
		REP(i, n) a[i] = s[i].FI, b[i] = -s[i].SE;

		MS(c, 0);
		int k = 1, cur = 0;
		for (; k <= 2 * n; k++) {
			int m = -1, id = -1, ch = -1;
			REP(i, n) if (cur >= b[i] && c[i] <= 2) {
				if (2 - c[i] > m) {
					m = 2 - c[i];
					id = i;
					ch = 1;
				}
			}
			REP(i, n) if (cur >= a[i] && c[i] <= 1) {
				if (1 - c[i] > m) {
					m = 1 - c[i];
					id = i;
					ch = 0;
				}
			}
			//if (ca == 62) cout << id << " " << m << " " << cur << endl;
			if (m == -1) break;
			c[id] = ch + 1;
			cur += m;
			if (cur >= 2 * n) break;
		}
		printf("Case #%d: ", ca);
		if (cur < 2 * n) cout << "Too Bad" << endl;
		else cout << k << endl;
	}
	return 0;
}


