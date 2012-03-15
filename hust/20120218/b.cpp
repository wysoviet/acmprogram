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

const int maxn = 1000 + 10;
int opt[maxn], val[maxn], q[maxn];
int n, m;

int main(){
	scanf("%d", &n);
	REP(i, 1, n) scanf("%d", q + i);
	scanf("%d", &m);
	int i, j, k;
	fill(val, val + n + 1, 1000000 + 100);
	while (m--){
		scanf("%d%d%d", &i, &j, &k);
		if (k < val[j]) val[j] = k, opt[j] = i;
	}


	int ans = 0, sum = 0;
	REP(i, 1, n) if (!opt[i]) sum++;
	else ans += val[i];

	if (sum > 1) printf("-1\n");
	else printf("%d\n", ans);

	return 0;
}


