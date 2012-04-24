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

pair<int, string> a[2000], b[2000];
bool v[2000];
int c[2000];

int main() {
	int n;
	string tmp;
	cin >> n;
	REP(i, n) cin >> a[i].SE >> a[i].FI;
	for (int i = 0; i < n; i++) {
		int cur = i;
		for (int j = i; j < n; j++)
			if (a[i].SE == a[j].SE && a[j].FI > a[cur].FI)
				cur = j;
		for (int j = i; j < n; j++)
			if (a[i].SE == a[j].SE && j != cur)
				v[j] = 1;
	}
	
	int m = 0;
	for (int i = 0; i < n; i++)
		if (v[i] == 0) b[m] = a[i], c[m++] = a[i].FI;

	sort(b, b + m);
	sort(c, c + m);
	cout << m << endl;
	for (int i = 0; i < m; i++) {
		cout << b[i].SE << " ";
		int p = upper_bound(c, c + m, b[i].FI) - c;
		p = m - p;
		if (p * 100 > m * 50) cout << "noob" << endl;
		else if (p * 100 > m * 20) cout << "random" << endl;
		else if (p * 100 > m * 10) cout << "average" << endl;
		else if (p * 100 > m * 1) cout << "hardcore" << endl;
		else cout << "pro" << endl;
	}
	
	return 0;
}


