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

using namespace std;

const int maxs = (2 << 13) + 10;
const int maxn = 10 * 2 + 5;
bool f[maxn][maxs];
bool v[maxn][maxs];
int a[maxn];
int n, m;

bool gao(int x, int s){
	if (v[x][s]) return f[x][s];
	v[x][s] = 1;
	int t = 1;
	for (int i = 1; i <= a[x] && i <= s; i++)
		t = t && gao((x + 1) % n, s - i);
	return f[x][s] = s?!t:t;
}

int main(){
	while (scanf("%d", &n), n){
		memset(v, 0, sizeof(v));
		memset(f, 0, sizeof(f));
		n *= 2;
		scanf("%d", &m);
		for (int i = 0; i < n; i++)
			scanf("%d", a + i);
		if (gao(0, m)) puts("1");
		else puts("0");
	}
	return 0;
}


