/*
ID:wysovie1
LANG:C++
TASK:milk4
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

int Q, P, L;
int a[200], r[200];
bool flag, f[40000];

bool gaoc() {
	MS(f, 0);
	f[0] = 1;
	for (int i = 0; i < Q && !f[Q]; i++) 
		if (f[i]) for (int j = 0; j < L; j++)
			f[i+r[j]] = 1;
	if (f[Q]) {
		printf("%d", L);
		REP(i, L) printf(" %d", r[i]);
		puts("");
	}
	return f[Q];
}

void gao(int x, int l) {
	if (flag) return;
	if (l == L) {
		flag = gaoc();
		return;
	}
	for ( ; x < P; x++) {
		r[l] = a[x];
		gao(x + 1, l + 1);
		if (flag) return;
	}
}

int main() {
	freopen("milk4.in", "r", stdin);
	freopen("milk4.out", "w", stdout);

	cin >> Q >> P;
	REP(i, P) cin >> a[i];
	sort(a, a + P);
	for (L = 1; L <= P; L++) 
		gao(0, 0);
		
	return 0;
}


