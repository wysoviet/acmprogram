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

#define REP(i, a, b) for (int i = a; i <= b; i++)
#define TR(it, a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define ALL(a) a.begin(),a.end()
#define PB(i) push_back(i)
#define MS(a, i) memset(a, i, sizeof(a))
#define DEB(x) cout << #x << " : " << x << endl
#define DEBA(a, n) REP(i, 0, n - 1) cout << #a << "[" << i << "] : " << a[i] << endl;

using namespace std;

const int maxn = 10000 + 10;
const int mini = -100000000;
int a[maxn], f[maxn], s[maxn], p[maxn * 100];
int n, b, c, ans, e;

int gao(int x){
	if (f[x] != mini) return f[x];
	int t = mini;
	REP(i, s[x], s[x + 1] - 1)  t = max(t, a[p[i]] - gao(p[i]));
	if (s[x] == s[x + 1])  t = 0;
	return f[x] = t;
}

int main(){
	int T;

	scanf("%d", &T);
	while (T--){
		scanf("%d%d%d", &n, &b, &c);
		int l = 0, t;
		REP(i, 0, n - 1) { scanf("%d", &t); if (t > 0) a[l++] = t;}
		a[l++] = e = 0;
		sort(a, a + l);
		for (int i = 0; i < l; i++){
			s[i] = e;
			for (int j = i + 1; j < l && a[j] - a[i] <= c; j++)
				if (a[j] - a[i] >= b) p[e++] = j;
		}
		s[l] = e;
		fill(f, f + l, mini);
		printf("%d\n", gao(0));
	}
	return 0;
}


