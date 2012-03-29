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

const long long  mod =1000000007;
void mul(long long a[2][2], long long b[2][2]) {
	long long c[2][2] = {0};
	for (long long i = 0; i < 2; i++)
		for (long long j = 0; j < 2; j++)
			for (long long k = 0; k < 2; k++)
				c[i][j] = c[i][j] + a[i][k] * b[k][j] % mod;
	for (long long i = 0; i < 2; i++)
		for (long long j = 0; j < 2; j++)
			a[i][j] = c[i][j] % mod;
}

int  main() {
	long long n;
	cin >> n;
	if (n == 1) printf("0\n");
	else if (n == 2) printf("3\n");
	else if (n == 3) printf("6\n");
	else { long long a[2][2] = {2, 1, 3, 0};
	       long long b[2][2] = {1, 0, 0, 1};
	       for (n -= 3; n; n >>= 1) { 
		       if (n & 1) mul(b, a);
		       mul(a, a);
	       }
	       long long ans = (6 * b[0][0] + 3 * b[1][0]) % mod;
	       cout << ans << endl;
	}
         return 0;
}


