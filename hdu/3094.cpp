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

vector<int> e[100100];
bool v[100100];

int gao(int x){
	int ret = 0;
	v[x] = 1;
	TR(i, e[x]) if (!v[*i]) ret ^= gao(*i) + 1;
	return ret;
}

int main(){
	int T, n, i, j, k;

	cin >> T;
	while (T--) {
		cin >> n;
		MS(v, 0);
		for (int i = 1; i <= n; i++) 
			e[i].clear();
		for (int i = 1; i < n; i++){
			scanf("%d%d", &j, &k);
			e[j].PB(k);
			e[k].PB(j);
		}
		if (gao(1)) cout << "Alice" << endl;
		else cout << "Bob" << endl;
	}

	return 0;
}


