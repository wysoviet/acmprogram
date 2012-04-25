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

const int maxn = 1000000 + 100;
int n, m, k;
int qin[maxn], qde[maxn], tail, head,id2[maxn],id1[maxn], h1, h2, t1, t2;

int main() {
	while (~scanf("%d%d%d", &n, &m, &k)) {
		int t;
		h1 = h2 = t1 = t2 = 0;
		int ans = 0, start = 0;
		REP(i, n) {
			scanf("%d", &t);
			while (h1<t1 && qin[t1-1]>t) t1--;
			while (h2<t2 && qde[t2-1]<t) t2--;
			while (h1<t1 && h2<t2 && qde[h2]-qin[h1]>k)
				if(id1[h1]<id2[h2]) start = id1[h1]+1, h1++;
				else start = id2[h2] + 1, h2++;
			id1[t1] = i, qin[t1++] = t;
			id2[t2] = i, qde[t2++] = t;
			if (qde[h2]-qin[h1]>=m && qde[h2]-qin[h1]<=k) 
				ans= max(ans, i-start+1);
		}
		printf("%d\n", ans);
	}
			

	return 0;
}


