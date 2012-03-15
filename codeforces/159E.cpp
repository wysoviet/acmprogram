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

using namespace std;

const int maxn = (int)(1e5 + 10);
map<int , int> d;
vector< pair<long long , int> > a[maxn];
priority_queue< pair<long long, int> >q;
int n, m, id[maxn], cur[maxn], tx, ty;

bool cmp(int x, int y) { return a[x].size() > a[y].size();}

int main() {
	int h, c;

	cin >> n;
	REP(i, n) {
		cin >> c >> h;
		if (!d.count(c)) d[c] = m++;
		a[d[c]].PB(MP(-h, i + 1));
	}
	
	REP(i, m) id[i] = i, sort(ALL(a[i]));
	sort(id, id + m, cmp);

	long long ans = 0;
	REP(ii, m) {
		int i = id[ii];
		long long sum = 0;
		TR(j, a[i]) sum -= j->first;
		cur[i] = a[i].size();
		while (!q.empty()) {
			pair<long long, int> t = q.top();
			int j = t.second;
			long long s = t.first;
			if (cur[i] + 1 < cur[j]) {
				q.pop();
				s += a[j][--cur[j]].first;
				q.push(MP(s, j));
				continue;
			}
			if (sum + s > ans) {
				ans = sum + s, tx = i, ty = j;
			}
			break;
		}
		q.push(MP(sum, i));
	}

	cout << ans << endl;
	cout << a[tx].size() + min(a[tx].size() + 1, a[ty].size()) << endl;
	REP(i, a[tx].size()) cout << a[ty][i].second << " " << a[tx][i].second << " ";
	if (a[ty].size() > a[tx].size()) cout << a[ty][a[tx].size()].second;
	return 0;
}

				
				
		


