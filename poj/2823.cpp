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

const int maxn = 1e6 + 10;
int a[maxn], id[maxn], f[maxn];
int n, k, head, tail;

int main() {
	scanf("%d%d", &n, &k);
	
	REP(i, n) scanf("%d", a + i);

	head = tail = 0;
	int t;
	REP(i, n) {
		t = a[i];
		while (head<tail && i - id[head] + 1 > k) head++;
		while (head<tail && f[tail-1] >= t) tail--;
		id[tail] = i, f[tail++] = t;
		if (i >= k - 1) printf("%d%c", f[head], i<n-1?' ':'\n');
	}
	head = tail = 0;
	REP(i, n) {
		t = a[i];
		while (head<tail && i - id[head] + 1 > k) head++;
		while (head<tail && f[tail-1] <= t) tail--;
		id[tail] = i, f[tail++] = t;
		if (i >= k - 1) printf("%d%c", f[head], i<n-1?' ':'\n');
	}
	return 0;
}


