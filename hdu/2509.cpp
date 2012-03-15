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

int sg[110], v[110];

int main(){
	/*sg[0] = 0;
	for (int i = 1; i <= 100; i++) {
		MS(v, 0);
		for (int j = 1; j <= i; j++)
			for (int k = 0; k <= i - j; k++)
				v[sg[k] ^ sg[i - j - k]] = 1;
		for (int j = 0; j <= 100; j++)
			if (!v[j]) {sg[i] = j; break;}
	}

	DEBA(sg, 100);
	*/

	int n, s, a, t;

	while (~scanf("%d", &n)) {
		s = a = 0;
		while (n--){
			cin >> t;
			a += t > 1;
			s ^= t;
		}
		if (s && a || !s && !a) cout << "Yes" << endl;
		else cout << "No" << endl;
	}

	return 0;
}


