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
const int maxn = int(1e5 + 10);
int a[maxn], b[maxn];
int n, m, x, y;
vector< pair<int, int> > ans;

int main() {
	cin >> n >> m >> x >> y;
	REP(i, n) scanf("%d", a + i);
	REP(i, m) scanf("%d", b + i);

	int j = 0;
	REP(i, n) {
		for (;j < m && b[j] <= a[i] + y; j++)
			if (b[j] >= a[i] - x) {
				ans.PB(MP(i,j++));
				break;
			}
	}
	cout << ans.size() << endl;
	TR(i, ans) printf("%d %d\n", i->first + 1, i->second + 1);
	return 0;
}


