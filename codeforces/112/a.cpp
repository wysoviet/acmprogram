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

int a[210][2];

int main() {
	int n;
	
	cin >> n;
	REP(i, n) cin >> a[i][0] >> a[i][1];
	
	int ans = 0;
	REP(i, n) {
		bool flag = 1;
		REP(j, n) if (a[i][0] > a[j][0] && a[i][1] == a[j][1])
			flag = 0;
		if (flag) continue;
		flag = 1;
		REP(j, n) if (a[i][0] < a[j][0] && a[i][1] == a[j][1])
			flag = 0;
		if (flag) continue;
		flag = 1;
		REP(j, n) if (a[i][0] == a[j][0] && a[i][1] > a[j][1])
			flag = 0;
		if (flag) continue;
		flag = 1;
		REP(j, n) if (a[i][0] == a[j][0] && a[i][1] < a[j][1])
			flag = 0;
		if (flag) continue;
		ans++;
	}

	cout << ans << endl;
	return 0;
}


