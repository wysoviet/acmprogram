/*
TASK:fence8
LANG:C++
ID:wysovie1
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
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define TR(it, a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define ALL(a) a.begin(),a.end()
#define PB(i) push_back(i)
#define MS(a, i) memset(a, i, sizeof(a))
#define DEB(x) cout << #x << " : " << x << endl
#define DEBA(a, n) REP(i, 0, n - 1) cout << #a << "[" << i << "] : " << a[i] << endl

using namespace std;

int b[52], r[1025], t[1025], s;
bool v[1025];
int n, m;
int l, u, mid;

bool gao(int k, int nb, int nr, int w){
	if (nr == mid) return 1;
	if (nb == n) return 0;
	if (w > s - t[mid - 1]) return 0;  
	for (int i = k; i >= 0; i--) 
		if (!v[i] && b[nb] >= r[i]) {
			if (i < mid - 1 && !v[i + 1] && r[i] == r[i + 1]) continue;
			v[i] = 1; b[nb] -= r[i];
			bool t = gao(i - 1, nb, nr + 1, w);
			v[i] = 0; b[nb] += r[i];
			if (t) return 1;
		}
	return gao(mid - 1, nb + 1, nr, w + b[nb]);
}

int main(){
	freopen("fence8.in", "r", stdin);
        freopen("fence8.out", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", b + i);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) scanf("%d", r + i);

	sort(b, b + n);
	sort(r, r + m);
	t[0] = r[0];
	for (int i = 1; i < m; i++) t[i] = t[i - 1] + r[i];
	for (int i = 0; i < n; i++) s += b[i];

	l = 1; u = m;
	while (l <= u) {
		mid = l + u >> 1;
		if (gao(mid - 1, 0, 0, 0)) l = mid + 1;
		else u = mid - 1;
	}
		
	printf("%d\n", l - 1);
	return 0;
}



