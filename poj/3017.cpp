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
long long a[maxn], s[maxn], q[maxn], f[maxn];
map<int, long long> h1;
map<long long, long long> h2;
multiset<long long> h;
int id[maxn], head, tail;
int n, m;

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		scanf("%lld", a + i);
		if (a[i] > m) {
			puts("-1");
			return 0;
		}
		s[i] = s[i - 1] + a[i];
	}
	for (int i = 1; i <= n; i++) {
		while (head < tail && q[tail-1]<a[i]) {
			tail--;
			h.erase(h1[id[tail]]);
			h1.erase(id[tail]);
		}
		while (head < tail && s[i] - s[id[head]-1] > m) {
			h.erase(h1[id[head]]);
			h1.erase(id[head]);
			head++;
		}
		int tmp;
		if (a[i] <= m) {
			if (head < tail) tmp = f[id[tail-1]] + a[i];
			else if (i) tmp = f[i-1] + a[i];
			     else tmp = a[i];
			h.insert(tmp);
			h1[i] = tmp;
		}
		id[tail] = i, q[tail++] = a[i];
		if (!h.empty()) f[i] = *h.begin();	
		if (s[i] <= m) if (f[i]) f[i] = min(f[i], a[id[head]]);
				else f[i] = a[id[head]];
		//for (int j = head; j < tail; j++)
		//	printf("[%d, %lld, %lld] ",id[j], q[j], h1[id[j]]);
		//puts("");
		//TR(j, h) printf("%lld ", *j);
		//puts("");
		//printf("f[%d] = %lld\n", i, f[i]);
		//puts("");
	}

	cout << f[n] << endl;
	return 0;
}


