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

const int maxv = 1e5 + 10;
const int inf = 0x7fffffff;
int type[maxv], type[maxv];
int f[maxv], last[maxv], queue[maxv];
int n;

int main() {
	int T, cas = 0;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", type + i, height + i);
		int l = 0, head = 0, tail = 0;
		f[0] = 0;
		for (int i = 1; i <= n; i++) {
			l = max(l, last[type[i]]);
			last[type[i]] = i;
			while (head < tail && queue[head] <= l) head++;
			while (head < tail && height[queue[tail-1]] <= height[i]) tail--;
			queue[tail++] = i;
			f[i] = inf;
			for (int j = head; j < tail; j++) {
				int pos = (j == head)?l:queue[j-1];
				f[i] = min(f[i], f[pos]+height[queue[j]]);
			}
		}
		printf("Case %d: %d\n", ++cas, f[n]);
	}
			
	return 0;
}


