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

const int maxn = 100;
long long a[maxn][maxn], b[maxn][maxn], c[maxn], t[maxn];
char s[maxn], next[maxn];
int n, m;
const long long mod = 1e9 + 7;

void mul(long long a[maxn][maxn], long long b[maxn][maxn]) {
	long long c[maxn][maxn] = {0};
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			for (int k = 0; k <= n; k++) {
				c[i][j] += a[i][k] * b[k][j];
				c[i][j] %= mod;
			}
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			a[i][j] = c[i][j];
}

void preg(char s[]) {
	a[0][0] = a[0][1] = 1;
	for (int i = 1; i <= n; i++) {
		a[i-1][i] = 1;
		s[i] -= '0';
	}
	
	int t, j;
	next[1] = j = 0;
	for (int i = 2; i <= n; i++) {
		t = j;
		while (j && s[j+1]!=s[i]) j = next[j];	
		while (t && s[t+1]==s[i]) t = next[t]; 
		if (s[j+1]==s[i]) j++;
		if (s[t+1]!=s[i]) t++;
		next[i] = j; 
		a[i-1][t] = 1;
	}
}

int main() {
	scanf("%s%d", s+1, &m);
	n = strlen(s+1);	
	preg(s);
	for (int i = 0; i <= n; i++) 
		b[i][i] = 1;

	for ( ; m; m >>= 1) {
		if (m & 1) mul(b, a);
		mul(a, a);
	}

	long long ans = 0;
	for (int i = 0; i < n; i++) {
		ans += b[0][i];
		ans %= mod;
	}
	cout << b[0][n] << endl;
	return 0;
}


