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

int main() {
	int T, n, s, p;
	pair<int,int> a[200];
	int b[3] = {1, 1, 2};

	freopen("b.in", "r", stdin);
	freopen("b.ans", "w", stdout);

	cin >> T;
	for (int cas = 1; cas <= T; cas++) {
		cin >> n >> s >> p;
		for (int i = 0; i < n; i++) {
			cin >> a[i].SE;
			a[i].FI = a[i].SE / 3 + (a[i].SE % 3 != 0);
			a[i].FI = -a[i].FI;
			a[i].SE = -a[i].SE;
		}
		sort(a, a + n);
		for (int i = 0; i < n; i++){
			a[i].FI = -a[i].FI;
			a[i].SE = -a[i].SE;
			//cout << a[i].FI << " " << a[i].SE << endl;
		}

		int ans = 0;
		for (int i = 0; i < n; i++)
			if (a[i].FI >= p) ans++;
			else if (s) {
				int t1 = a[i].SE / 3, t2 = a[i].SE / 3;
				if (a[i].SE % 3 == 2) t1 += 2;
				if (a[i].SE % 3 == 1) t1 += 1;
				if (a[i].SE % 3 == 0 && t2 > 0) t1 += 1;
				if (t1 >= p) ans++, s--;
			}
		printf("Case #%d: %d\n", cas, ans);
	}

	return 0;
}


