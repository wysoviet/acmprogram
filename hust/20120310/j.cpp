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
#define DEB(x) cout << #x << " : " << x << endl
#define DEBA(a, n) REP(i, n) cout << #a << "[" << i << "] : " << a[i] << endl

using namespace std;

const long long mod = 1000000007;
const int maxn = 10000100;
bool isnpri[maxn] = {0};
int pri[700000], npri = 0, inv[700000];
long long f[maxn];

long long mod_exp(long long a, long long b, long long c){
	long long ret = 1;
	for (a %= c; b; b >>= 1, a = a * a % c)
		if (b & 1) ret = ret * a % c;
	return ret;
}


int main() {
	int T, n;

	f[0] = f[1] = 1;
	for (int i = 2; i < maxn; i++) {
		f[i] = f[i - 1] * i % mod;	
		if (!isnpri[i]) pri[npri++] = i;
		for (int j = 0; pri[j] * i < maxn; j++) {
			isnpri[pri[j] * i] = 1;
			if (i % pri[j] == 0) break;
		}
	}
	
	REP(i, npri) inv[i] = mod_exp(pri[i], mod - 2, mod);
	while (scanf("%d", &n), n){
		long long ans = f[n];
		REP(i, npri) {
			int t = n, cnt = 0;
			while (t) cnt ^= (t / pri[i]) & 1, t/= pri[i];
			if (cnt) ans = ans * inv[i] % mod;
		}
		cout << ans << endl;
	}	
	return 0;
}
