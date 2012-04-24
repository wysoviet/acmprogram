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

const int maxn = 1e6;
char s[100];
int gao(int x, int y) {
	if (y < x) return -1;
	int ret = 0;
	if (s[x] == '0' && y > x) return -1;
	for (int i = x; i <= y; i++) {
		ret = ret * 10 + s[i] - '0';
		if (ret > maxn) return -1;
	}
	return ret;
}

int main() {

	cin >> s;
	int n = strlen(s);

	int ans = -1;
	for (int i = 1; i < n; i++)
		for (int j = i + 1; j < n; j++) {
				int t1 = gao(0, i - 1);
				int t2 = gao(i, j - 1);
				int t3 = gao(j, n - 1);
				if (t1 == -1 || t2 == -1 || t3 == -1) continue;
				//printf("%d %d\n", i, j);
				ans = max(ans, t1 + t2 + t3);
			}

	cout << ans << endl;
	return 0;
}


