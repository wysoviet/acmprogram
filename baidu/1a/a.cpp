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

const int maxn = 1010;
vector< pair<int, int> > e[maxn];
vector<int> h;
int n, m, s;

int cnt = 0;
bool gao(int c, int s) {
	vector< pair<int, int> >::iterator it;
	cnt++;
	while (1) {
		//cout << c << " " << s << endl;
		it = upper_bound(ALL(e[s]), MP(c, 101));
		if (it == e[s].end()) break;
		s = it->SE;
		c = it->FI;
	}
	//cout << endl;
	return s == 1;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		scanf("%d%d%d", &n, &m, &s);
		int j, k, t;
		h.clear();
		REP(i, n) e[i].clear();
		REP(i, m) {
			scanf("%d%d%d", &j, &k, &t);
			e[j].PB(MP(-t, k));
			e[k].PB(MP(-t, j));
			h.PB(-t);
		}
		REP(i, n) sort(e[i].begin(), e[i].end());
		sort(h.begin(), h.end());
		int c = -1000001; 
		bool flag = 0;
		while (1) {
			flag = gao(c, s);
			if (flag) break;
			vector< pair<int, int> >::iterator it;
			it = upper_bound(ALL(e[s]), MP(c, 101));   
			if (it == e[s].end()) break;
			t = it->FI;
			while (c < t) {
				vector<int>::iterator hit;
				hit = upper_bound(ALL(h), c);
				c = *hit;
				if (s > 1) flag = gao(c-1, s - 1);
				if (!flag && s < n) 
					flag = gao(c-1, s + 1);
				if (flag) break;
			}
			if (flag) break;
			c = t;
			s = it->SE;
		}
		if (flag) puts("Yes");
		else puts("No");
	}
	return 0;
}


