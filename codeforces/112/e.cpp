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

int n, a[1000100], d[1<<22];

int main() {
	cin >> n;
	REP(i, 1 << 22) d[i] = -1;
	REP(i, n) scanf("%d", a + i), d[a[i]] = a[i];
	REP(i, 1 << 22) if (d[i] < 0)
		REP(j, 22) if (((i>>j)&1) && d[i^(1<<j)]>=0) 
			d[i] = d[i ^ (1<<j)];
		
	REP(i, n) printf("%d ", d[(1<<22)-a[i]-1]);
	return 0;
}


