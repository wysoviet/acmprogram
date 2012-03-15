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

int main(){
	unsigned int x, a[32], ans;

	while (cin >> x){
		REP(i, 0, 31) 
		a[i] = x & 1, x >>= 1;
		reverse(a, a + 32);
		next_permutation(a, a + 32);
		ans = 0;
		REP(i, 0, 31) ans = ans * 2 + a[i];
		cout << ans << endl;
	}
	return 0;
}


