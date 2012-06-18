/*
ID:wysovie1
LANG:C++
TASK:tour
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

map<string, int> mp;
vector<int> e[200];
int f[200][200];
int n, m;
string str, st1, st2;

int main() {
	freopen("tour.in", "r", stdin);
	freopen("tour.out", "w", stdout);

	cin >> n >> m;
	REP(i, n) {
		cin >> str;
		mp[str] = i;
	}
	REP(i, m) {
		cin >> st1 >> st2;
		int t1 = mp[st1], t2 = mp[st2];
		if (t1 > t2) swap(t1, t2);
		e[t1].PB(t2);
	}
	f[0][0] = 1;
	REP(i, n) REP(j, n)
		if (f[i][j] && (i < j || !i)) {
			TR(it, e[i]) if (*it >= j) {
				int &t = f[j][*it];
				t = max(t, f[i][j]+(j!=n-1));
			}
			TR(it, e[j]) if (*it > j)  {
				int &t  = f[i][*it];
				t = max(t, f[i][j]+1);
			}
		}

	/*	
	REP(i, n) {
		cout << i << " " << e[i].size() << " ";
		TR(j, e[i]) cout << *j << " ";
		cout << endl;
	}
	cout << endl;
	REP(i, n) {
		REP(j, n) cout << f[i][j] << " ";
		cout << endl;
	}
	*/	
	cout << max(f[n-1][n-1],1) << endl;
	
	return 0;
}


