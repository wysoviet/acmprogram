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

const int maxn = 1000000 + 10;
int s[maxn];
char t[maxn];
int k, n;

int main() {
	cin >> k;
	scanf("%s", t);
	n = strlen(t);
	for (int i = 1; i < n; i++)
		s[i] = s[i - 1] + (t[i] == '1');

	long long ans = 0;
	REP(i, n) {
		int tmp = k - (t[i] == '1');
		int ret = upper_bound(s + i, s + n, s[i] + tmp) 
			- lower_bound(s + i, s + n, s[i] + tmp);
		ans += ret;
	}

	cout << ans << endl;
	return 0;
}


