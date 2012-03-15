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

int a, c;
int ans[31];

int main(){
	cin >> a >> c;

	REP(i, 0, 30) {
		ans[i] = (3 - (a % 3) + (c % 3)) % 3;
		a /= 3;
		c /= 3;
	}
	reverse(ans, ans + 31);
	long long ret = 0;
	REP(i, 0, 30) ret = ret * 3 + ans[i];
	cout << ret << endl;
	return 0;
}


