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

int cnt = 0;
long long gao(long long n) {
	long long l = 0, t = n;
	while (t) l++, t >>= 1;
	long long maxt = 1<<l-1, ret = n;
	t = n;
	cnt++;
	REP(i, l) {
		if (t > maxt) ret = min(ret, t);
		t = (t >> 1) + ((t & 1) << l-1);
		//if (cnt == 1) cout << t << endl;
	}
	//DEB(ret);
	return ret;
}

int main() {
	long long ans, n, t;
	cin >> n;
	if (gao(n)==n) cout << n << endl;
	else {
		long long a[40], m;
		while (n) a[m++] = (n & 1), n >>= 1;
		int cnt = 0;
		for (int i = m - 1; i >= 0; i--) 
			if (a[i] == 0), 
	}
	return 0;
}


