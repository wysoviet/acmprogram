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

const int maxk = 100 + 10;
const int maxn = 10000 + 10;
bool v[maxn][maxk];
int f[maxn], s[maxk];
int n, k, l, t, tmp, m;

int main(){
	while (scanf("%d", &k), k){
		REP(i, 0, k - 1) scanf("%d",s + i);
		memset(v, 0, sizeof(v));
		REP(i, 0, maxn - 1){
			REP(j, 0, k + 1) if (!v[i][j]) {f[i] = j; break;};
			REP(j, 0, k - 1) if (i + s[j] < maxn) v[i + s[j]][f[i]] = 1;
		}
		
		scanf("%d", &m);
		while(m--){
			t = 0;
			scanf("%d", &n);
			REP(i, 0, n - 1) {scanf("%d", &tmp); t ^= f[tmp];}
			if (t) printf("W");
			else printf("L");
		}

		puts("");
	}
	return 0;
}


