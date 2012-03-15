/*
ID:wysovie1
LANG:C++
TASK:shuttle
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

vector<int> ans;

int main() {
	int n;

	freopen("shuttle.in", "r", stdin);
	freopen("shuttle.out", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; i++) 
		if (i & 1) for (int j = 1; j <= 2 * i + 1; j += 2)
			ans.PB(j + n - i);
		else for (int j = 2 * i + 1; j >= 1; j -= 2)
			ans.PB(j + n - i);

	int cur = (n & 1) ? n * 2 + 1 : 1;
	for (int i = n; i >= 1; i--) 
		if (i & 1) {cur++; REP(j, i) cur-=2, ans.PB(cur);} 
		else {cur--; REP(j, i) cur+=2, ans.PB(cur);};

	for (int i = 0; i < ans.size(); i++)
		if (i % 20 == 19 || i == ans.size() - 1) 
			cout << ans[i] << endl;
		else cout << ans[i] << " ";
	return 0;
} 

