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
#define REP(i, a, b) for (int i = a; i < b; i++)
#define TR(it, a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define PB(i) push_back(i)
#define MS(a, i) memset(a, i, sizeof(a))
#define DEB(x) cout << x << endl;

using namespace std;

long long f[40][40];

int main(){
	int n, m, t;
	
	REP(i, 1, 31) {
		f[i-1][0] = 1;
		REP(j, 1, i + 1)
		f[i][j] = f[i-1][j] + f[i-1][j-1];
	}	
	cin >> n >> m >> t;
	long long ans = 0;
	REP(i, 4, n + 1){ 
		if (t - i < 1) break;
		if (t - i <= m) ans += f[n][i] * f[m][t-i];
	}
	cout << ans << endl;
	return 0;
}


