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

const int maxn = 3e5;
int n, m, k;
int a[maxn]; 
deque<int> q[maxn];
int h, t;

int main() {
	cin >> n >> m >> k;
	int ans = -1;
	REP(i, n) {
		cin >> a[i];
		int c = a[i];
		q[c].PB(i);
		while (q[c].back()-q[c].front()+1-q[c].size()>k)
			q[c].pop_front();
		ans = max(ans, (int)q[c].size());
	}

	cout << ans << endl;
	return 0;
}


