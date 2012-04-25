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

const int maxn = 1e5 + 10;
const long long inf = 1e16;
long long f[maxn], a[maxn], s[maxn];
long long q[maxn], id[maxn];

int main() {
	int n, m, head, tail;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		scanf("%lld", a + i);
		if (a[i] > m) {
			puts("-1");
			return 0;
		}
		s[i] = s[i - 1] + a[i];
	}
	head = tail = 1;
	for (int i = 1; i <= n; i++) {
		f[i] = inf;
		while (head < tail && q[tail-1] < a[i]) tail--;
		for (int j = 0; head < tail; j++, head++) {
			int tmp = j ? id[head-1] : id[head] - 1;
			if (s[i] - s[tmp] <= m) break;
		}
		id[tail] = i, q[tail++] = a[i];
		for (int j = head; j < tail; j++) {
			//cout << id[j] << " ";
			int pos = (j == head) ? id[j] - 1: id[j-1];
			f[i] = min(f[i], f[pos] + q[j]);
		}
		//puts("");
		//cout << f[i] << endl;
		//puts("");
	}
	cout << f[n] << endl;

	return 0;
}


