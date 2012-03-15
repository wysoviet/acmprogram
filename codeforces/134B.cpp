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
#define PB(i) push_back(i)
#define MS(a, i) memset(a, i, sizeof(a))
#define DEB(x) cout << x << endl

using namespace std;

const int maxn = int(1e6+10);

int gao(int a, int b){
	if (a == 1) return b - a;
	if (b % a == 0) return maxn;
	return b / a + gao(b % a, a);
}

int main(){
	int n, ans = maxn;

	cin >> n;
	REP(i, 1, n) ans = min(ans, gao(i, n));
	cout << ans << endl;
	return 0;
}


