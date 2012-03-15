/* 
 PROB: nuggets
 LANG: C++
 ID: wysovie1
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

#define REP(i, a, b) for (int i = a; i <= b; i++)
#define TR(it, a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define ALL(a) a.begin(),a.end()
#define PB(i) push_back(i)
#define MS(a, i) memset(a, i, sizeof(a))
#define DEB(x) cout << #x << " : " << x << endl
#define DEBA(a, n) REP(i, 0, n - 1) cout << #a << "[" << i << "] : " << a[i] << endl

using namespace std;

const int maxn = 256 * 256;
int s[11], n;
bool f[maxn + 300];

int main(){
	freopen("nuggets.in", "r", stdin);
	freopen("nuggets.out", "w", stdout);

	cin >> n;
	REP(i, 0, n - 1) cin >> s[i];

	int ans = 0;
	f[0] = 1;
	REP(i, 1, maxn + 256) {
		REP(j, 0, n - 1) if (i - s[j] >= 0) f[i] = f[i] || f[i - s[j]];
		if (!f[i]) ans = i;
	}

	if (ans <= maxn) cout << ans << endl;
	else cout << 0 << endl;
		
	return 0;
}


