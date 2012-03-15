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
#define ALL(a) a.begin(),a.end()
#define MP(a, b) make_pair(a, b)
#define PB(i) push_back(i)
#define MS(a, i) memset(a, i, sizeof(a))
#define DEB(x) cout << #x << " : " << x << endl
#define DEBA(a, n) REP(i, n) cout << #a << "[" << i << "] : " << a[i] << endl

using namespace std;

map<int, int> d;
vector< pair<int, int> > a[100100];
priority_queue < pair<long long, int> > q;
int m, id[100100], cur[100100], rx, ry;
long long ans;

bool cmp(int x, int y) { return a[x].size() > a[y].size();}

int main() {
	int n, c, h;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> c >> h;
		if (!d.count(c)) d[c] = ++m;
		a[d[c]].PB(MP(-h, i));
	}
	
	for (int i = 1; i <= m; i++) 
		id[i] = i, sort(ALL(a[i]));
	sort(id + 1, id + m + 1, cmp);

	for (int ii = 1; ii <= m; ii++) {
		int i = id[ii];
		long long sum = 0;
		for (int j = 0; j < a[i].size(); j++) 
			sum -= a[i][j].first;
		cur[i] = a[i].size();

		while (!q.empty()) {
			pair <long long, int> u = q.top();
			int j = u.second;
			long long s = u.first;
			if (cur[j] > cur[i] + 1) {
				q.pop();
				s += a[j][--cur[j]].first;
				q.push(MP(s, j));
			}
			if (s + sum > ans)
				ans = s + sum, rx = i, ry = j;
			break;
		}
		q.push(MP(sum, i));
	}

	cout << ans << endl << a[rx].size() + min(a[ry].size(), a[rx].size() + 1) << endl;
	for (int i = 0; i < a[rx].size(); i++)
		cout << a[ry][i].second << " " << a[rx][i].second << ' ';	
	if (a[ry].size() > a[rx].size()) cout << a[ry][a[rx].size()].second;
	return 0;
}






