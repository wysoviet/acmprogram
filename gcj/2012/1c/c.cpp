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

typedef long long ll;

const int maxn = 110;
pair<ll, ll> a[maxn], b[maxn];
ll f[maxn][maxn];
int n, m;

ll solve(){
	cin >> n >> m;
	REP(i, n) cin >> a[i+1].FI >> a[i+1].SE;
	REP(i, m) cin >> b[i+1].FI >> b[i+1].SE;
	ll ans = 0;
	MS(f, 0);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
		if (a[i].SE != b[j].SE) 
			f[i][j] = max(f[i-1][j], f[i][j-1]);
		else {
			ll tmp = 0;
			ll t1 = 0;	
			for (int k = i; k >= 1; k--) {
				if (a[k].SE == a[i].SE) t1 += a[k].FI;
				ll t2 = 0;
				for (int l = j; l >= 1; l--) {
					if (b[j].SE == b[l].SE) t2 += b[l].FI;
					tmp = max(min(t1,t2)+f[k-1][l-1], tmp);
				}
			}
			f[i][j] = tmp;	 
		}	
		ans = max(ans, f[i][j]);
	}
	return ans;
}

int main() {
	//freopen("C-small-attempt2.in", "r", stdin);
	freopen("C-large.in", "r", stdin);
	freopen("c.ans", "w", stdout);

	int T;
	cin >> T;
	REP(ca, T) {
		printf("Case #%d: ", ca + 1);
		cout << solve() << endl;
	}
	return 0;
}


