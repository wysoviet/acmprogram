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

vector<int> e[1100];
int p[1100], n, t;

int gao(int x){
	int ret = 0;
	TR(i, e[x]) ret ^= gao(*i) + 1;
	return ret;
}

int main(){
	
	while (~scanf("%d", &n)){
		for (int i = 0; i < n; i++)
			e[i].clear();

		for (int i = 0; i < n; i++) {
			scanf("%d", p + i);
			if (~p[i]) e[p[i]].PB(i);
		}
		
		int ans = 0;
		for (int i = 0; i < n; i++)
			if (p[i] == -1) ans ^= gao(i);
		
		if (ans) cout << "YES" << endl;
		else cout << "NO" << endl;
	}	

	return 0;
}


