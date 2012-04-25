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

const int maxn = 2000 + 10;
const int inf = 1e7;
int f[maxn][maxn];
int bp[maxn], sp[maxn], bs[maxn], ss[maxn];
int id[maxn], q[maxn];
int p, w, t;

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &t, &p, &w);
		for (int i = 1; i <= t; i++)
			scanf("%d%d%d%d", bp+i, sp+i, bs+i, ss+i);
		for (int i = 1; i <= t; i++)
			for (int j = 0; j <= p; j++)
				f[i][j] = -inf;
		for (int i = 1; i <= w + 1; i++) 
			for (int j = 0; j <= bs[i]; j++)
				f[i][j] = -j*bp[i];
		
		for (int i = 2; i <= t; i++) {
			for (int j = 0; j <= p; j++) 
				f[i][j] = max(f[i][j], f[i-1][j]);
			if (i <= w + 1) continue;
			int head = 0, tail = 0, k = bs[i], r=bp[i];
			for (int j = 0; j <= p; j++) {
				int cur = f[i-w-1][j]+j*r;
				while (head<tail && j-id[head]>k) head++;
				while (head<tail && q[tail-1]<=cur) tail--;
				id[tail] = j, q[tail++] = cur;
				f[i][j] = max(f[i][j], q[head] - j*r);
			}
			head = tail = 0, k = ss[i], r = sp[i];
			for (int j = p; j >= 0; j--) {
				int cur = f[i-w-1][j]+j*r;
				while (head<tail && id[head]-j>k) head++;
				while (head<tail && q[tail-1]<=cur) tail--;
				id[tail] = j, q[tail++] = cur;
				f[i][j] = max(f[i][j], q[head] - j*r);
			}
		}

		//for (int i = 1; i <= t; i++) {
		//	for (int j = 0; j <= p; j++)
		//	cout << f[i][j] << " ";
		//cout << endl;
		//}
		int ans = -inf;
		for (int i = 0; i <= p; i++) ans = max(ans, f[t][i]);
		printf("%d\n", ans);
	}

	return 0;
}


