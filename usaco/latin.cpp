/*
ID:wysovie1
LANG:C++
TASK:latin
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

const int maxn = 10;
int mc[maxn], mr[maxn];
int a[maxn];
long long n, cnt;

int gao(int x, int y) {
	if (x == n - 1) return 1; 
	if (y == n)  return gao(x + 1, 1); 
	int tr = mr[x], tc = mc[y];
	int m = tr | tc, t = 0; 
	int s[2] = {-1, -1}, sum = 0;
	REP(i, n) if (!(m>>i&1)) {
		if (i > y) t = 1;
		if (x == 1 && s[t] != -1) sum += s[t];
		else {
			mr[x] |= 1 << i;
			mc[y] |= 1 << i;
			s[t] = gao(x, y + 1);
			sum += s[t];
			mr[x] = tr;
			mc[y] = tc;
		}
	}
	return sum;
}

int main() {
	//freopen("latin.in", "r", stdin);
	//freopen("latin.out", "w", stdout);

	cin >> n;		
	REP(i, n) { 
		mc[i] |= 1 << i;
		mr[i] |= 1 << i;
	}
	cnt = gao(1, 1);
	REP(i, n-1) cnt *= i+1;
	cout << cnt << endl;
	return 0;
}


