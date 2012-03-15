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

#define lowbit(x) ((x)&(-(x)))
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define REPD(i, b, a) for (int i = b; i >= a; i--)
#define TR(it, a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define ALL(a) a.begin(),a.end()
#define PB(i) push_back(i)
#define MS(a, i) memset(a, i, sizeof(a))
#define DEB(x) cout << #x << " : " << x << endl
#define DEBA(a, n) REP(i, 0, n - 1) cout << #a << "[" << i << "] : " << a[i] << endl

using namespace std;

int f[60][60], v[4000];

int main(){
	f[1][1] = 0;
	for (int i = 2; i <= 50; i++)
		f[1][i] = f[i][1] = i - 1;
	for (int i = 2; i <= 50; i++)
		for (int j = 2; j <= 50; j++) {
			MS(v, 0);
			for (int p = 1; p < i; p++)
				for (int q = 1; q < j; q++)
					v[f[p][j] ^ f[i][q]] = 1;
			for (int p = 0; p < 4000; p++)
				if (!v[p]) {f[i][j] = p; break;}
		}

	int m, n;
	char s[100];
	while (scanf("%d%d", &n, &m), m + n) {
		int ret = 0;
		for (int i = 0; i < n; i++) {
			scanf("%s", s);
			for (int j = 0; j < m; j++)
				if (s[j] == '#') ret ^= f[i + 1][j + 1];
		}
		if (ret) cout << "John" << endl;
		else cout << "Jack" << endl;
	}

	return 0;
}


