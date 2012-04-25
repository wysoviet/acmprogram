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

int A, B;
long long ans = 0;
set<int> hash;

void gao (int x) {
	int j = 10, t, k = 1;
	for (int i = x; i; i /= 10) k = k * 10;
	hash.clear();
	while (x / j > 0) {
		k /= 10;
		t = x / j + x % j * k;
		if (t > x && t <= B) {//ans++;
		//cout << x << " " << t <<  endl;
		hash.insert(t);
		}
		j *= 10;
	}
	ans += hash.size();
}
	
int main() {
	int T;

	freopen("c.in", "r", stdin);
	freopen("c.ans", "w", stdout);

	cin >> T;
	for (int ca = 1; ca <= T; ca++) {
		ans = 0;
		cin >> A >> B;
		for (int i = A; i <= B; i++) 
			gao(i);
		printf("Case #%d: ", ca);
		cout << ans << endl;
	}
	return 0;
}


