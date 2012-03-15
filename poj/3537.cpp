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
#define DEBA(a, n) REP(i, 0, n - 1) cout << #a << "[" << i << "] : " << a[i] << endl

using namespace std;
const int maxn = 2000 + 10;
int f[maxn];

int gao(int x){
	if (f[x] != -1) return f[x];
	int j, k;
	bool v[maxn] = {0};
	REP(i, 1, x/2+1){
		j = k = 0;
		if (i - 3 >= 1) j = gao(i - 3);
		if (i + 3 <= x) k = gao(x - i - 2);
		v[j ^ k] = 1;
	}
	REP(i, 0, maxn) if (!v[i]) {k = i; break;}
	return f[x] = k;
}

int main(){
	int n;

	MS(f, -1);
	while(~scanf("%d", &n)){
		if (gao(n)) puts("1");
		else puts("2");
	}
	return 0;
}


