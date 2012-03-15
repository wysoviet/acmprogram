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

const int maxn = int(1e5+100);
int a[maxn], n;

int main(){
	cin >> n;
	REP(i, 0, n - 1) cin >> a[i];
	sort(a, a + n);
	if (a[n - 1] == 1) a[n - 1] = 2;
	else a[n - 1] = 1;
	sort(a, a + n);
	REP(i, 0, n - 2) cout << a[i] << " ";
	cout << a[n - 1] << endl;
	return 0;
}


