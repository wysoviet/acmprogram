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

int n, l, k;
const int maxn = 2e5;
int a[maxn];

int main() {
	cin >> n >> l;
	REP(i, n) scanf("%d", a + i);
	cin >> k;
	
	long long ans = -1e18;
	REP(sgn, 2) {
		if (sgn) REP(i, n) a[i] = -a[i];
		multiset<int> ns, ps;
		long long s = 0;
		int r = 0;
		REP(i, n) {
			if (a[i] >= 0) s += a[i];
			else if (ps.size() < k) {
				s += -a[i];
				ps.insert(a[i]);
			}else if (k && a[i] < *(--ps.end())) {
				int v = *(--ps.end());
				ps.erase(--ps.end());
				ns.insert(v);
				s -= -v, s += v;
				r = v;
				s += -a[i];
				ps.insert(a[i]);
			}else { s += a[i];
				ns.insert(a[i]);
			}


			int j = i - l;
			if (j >= 0) 
				if (a[j] >= 0) s -= a[j];
				else if (ps.find(a[j])!=ps.end()) {
					ps.erase(ps.find(a[j]));
					s -= -a[j];
					if (!ns.empty()) {
						int v = *ns.begin();
						ns.erase(ns.begin());
						ps.insert(v);
						s -= v, s += -v;
					}
				}else { s -= a[j];
					ns.erase(ns.find(a[j]));
				}
			
			if (j >= -1) ans = max(ans, s);
		}
	}
		
	cout << ans << endl;

	return 0;
}


