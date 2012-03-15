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

#define lowbit(x) ((x)&(-(x)))
#define REP(i, a) for (int i = 0; i < a; i++)
#define REPD(i, a) for (int i = a - 1; ~i; i--)
#define TR(it, a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define PB(i) push_back(i)
#define MS(a, i) memset(a, i, sizeof(a))
#define DEB(x) cout << #x << " : " << x << endl
#define DEBA(a, n) REP(i, n) cout << #a << "[" << i << "] : " << a[i] << endl

using namespace std;

const int maxn = 2000100;
char str[110];
bool f[maxn];
vector<int> s[27], p[27];
int n, m;

int get(int k, int x) {
	int ret = 0;
	for (; x; x -= lowbit(x))
		ret += s[k][x];
	return ret;
}

int add(int k, int x, int t, int mx) {
	for (; x < mx; x += lowbit(x))
		s[k][x] += t;
}

int main() {
	int times;

	for (int i = 0; i < 26; i++) {
		s[i].clear();
		p[i].clear();
		s[i].PB(0);
		p[i].PB(0);
	}

	scanf("%d%s%d", &times, str, &n);
	m = strlen(str);
	for (int j = 0; j < times; j++) 
		for (int i = 0; i < m; i++) { 
			int t = str[i] - 'a';
			p[t].PB(j * m + i);
		}

	for (int i = 0; i < 26; i++)
		for (int j = 1; j < p[i].size(); j++)
			s[i].PB(lowbit(j));
	
			
	while (n--) {
		int x, l, u, mid, t;
		char c;
		scanf("%d%*c%c", &x, &c);
		c -= 'a';
		l = 1, u = p[c].size() - 1;
		while (l <= u) {
			mid = l + u >> 1;
			t = get(c, mid);
			if (t >= x) u = mid - 1;
			else l = mid + 1;
		}
		f[p[c][u + 1]] = 1;
		add(c, u + 1, -1, s[c].size());
	}

	for (int i = 0; i < times * m; i++)
		if (!f[i]) printf("%c", str[i % m]);
	puts("");

	return 0;
}


