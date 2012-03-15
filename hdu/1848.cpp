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

int f[1000], a[2001];
int v[2000];

int main(){
	f[0] = 1; f[1] = 2;
	for (int i = 1; f[i] <= 1000; i++)
		f[i + 1] = f[i] + f[i - 1];

	a[0] = 0;
	for (int i = 1; i <= 1000; i++) {
		MS(v, 0);
		for (int j = 0; f[j] <= i; j++)
			v[a[i - f[j]]] = 1;
		for (int j = 0; j <= 1000; j++) 
			if (!v[j]) { a[i] = j; break;}
	}

	int m, n, p;

	while (scanf("%d%d%d", &m, &n, &p), m + n + p) {
		int t = a[m] ^ a[n] ^ a[p];
		if (t) cout << "Fibo" << endl;
		else cout << "Nacci" << endl;
	}
	return 0;
}


