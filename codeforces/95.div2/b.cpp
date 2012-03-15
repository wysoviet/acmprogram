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
#define REP(i, a, b) for (int i = a; i < b; i++)
#define TR(it, a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define PB(i) push_back(i)
#define MS(a, i) memset(a, i, sizeof(a))
#define DEB(x) cout << x << endl

using namespace std;

int main(){
	int n;
	int a[30] = {0};

	scanf("%d", &n);
	REP(i, 0, n) {
		int t;
		scanf("%d", &t);
		a[t+11]++;
	}

	long long ans = 0;
	REP(i, 1, 11) ans += 1LL * a[i+11] * a[-i+11];
	ans += 1LL * a[11] * (a[11] - 1) / 2;
	cout << ans << endl;
	return 0; 
} 
