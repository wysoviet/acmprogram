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
#define DEB(x) cout << #x << " : " << x << endl
#define DEBA(a, n) REP(i, n) cout << #a << "[" << i << "] : " << a[i] << endl

using namespace std;

long long f[100], n = 2;

int main() {
	f[0] = 1; f[1] = 2;
	for (n = 2; f[n - 1] <= 1LL<<31; n++)
		f[n] = f[n - 1] + f[n - 2];

	int t; 
	while (scanf("%d", &t), t){
		bool flag = 1;
		REP(i, n) if (t == f[i]) flag = 0;
		if (flag) cout << "First win" << endl;
		else cout << "Second win" << endl;
	}

	return 0;
}


