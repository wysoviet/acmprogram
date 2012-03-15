/*
ID:wysovie1
LANG:C++
TASK:buylow
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

const int maxn = 5010;
int f[maxn], s[maxn][100], a[maxn];
int n;

int add(int a[], int b[], int f) {
	int l = max(a[0], b[0]);
	
	for (int i = 1; i <= l; i++) {
		a[i] += f * b[i];
		if (a[i] >= 10) a[i + 1] += 1, a[i] -= 10;
		if (a[i] < 0) a[i + 1] -= 1,  a[i] += 10;
	}

	if (a[l + 1]) l++;
	else if (!a[l]) l--;	
	a[0] = l;
}

int main() {
	freopen("buylow.in", "r", stdin);
	freopen("buylow.out", "w", stdout);

	scanf("%d", &n);
	REP(i, n) scanf("%d", a + i + 1);

	s[0][0] = s[0][1] = 1;a[0] = 0x7fffffff;
	int ans[100] = {0}, mf = 0;
	for (int i = 1; i <= n; i++) {
		int tf = 0;
		int ts[100] = {0};
		REP(j, i) if (a[j] > a[i]) 
			if (f[j] + 1 > tf) {
				tf = f[j] + 1; 
				memcpy(ts, s[j], 400);
			}
			else if (f[j] + 1 == tf) add(ts, s[j], 1);
		REP(j, i) if (a[j] == a[i] && f[j] == tf) add(ts, s[j], -1);
		f[i] = tf; 
		memcpy(s[i], ts, 400);
		if (tf > mf) {
			mf = tf;
			memcpy(ans, ts, 400);
		}else if (tf == mf) add(ans, ts, 1);
	}

	cout << mf << " ";
	for (int i = ans[0]; i; i--)
		printf("%d", ans[i]);
	cout << endl;
	return 0;
}


