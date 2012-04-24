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

const int maxn = 300;

int a[maxn], b[maxn];
vector < pair<int,int> > ans;

int main(){
	int n, m;

	cin >> n >> m;
	int tot = 0;
	REP(i, m) {
		int t, k;
		cin >> t;
		REP(j, t) {
			cin >> k;
			a[++tot] = k;
			b[k] = tot;
		}
	}
	
	//cout << "shit" << endl;
	int k = -1;
	for (int i = 1; i <= n; i++)
		if (b[i] == 0) {k = i; break;}
	
	for (int i = 1; i <= tot; i++)
		if (a[i] == i) continue;
		else { if (i != k) ans.PB(MP(i, k));
			ans.PB(MP(a[i], i));
			b[k] = b[i];
			a[b[k]] = k;
			k = a[i];
			a[i] = b[i] = i;
		}


	cout << ans.size() << endl;
	TR(i, ans) cout << i->FI << " " << i->SE << endl;
	
	return 0;
}
