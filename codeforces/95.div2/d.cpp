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
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define TR(it, a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define PB(i) push_back(i)
#define MS(a, i) memset(a, i, sizeof(a))
#define DEB(x) cout << x << endl;

using namespace std;

const int maxn = 4000;
int d[maxn], ans[maxn], v[maxn];
vector<int> e[maxn];

void dfs(int x, int k){
	TR(it, e[x]) {
		int y = *it;
		if (ans[y] == -1) {
			ans[y] = k + 1;
			dfs(y, k + 1);
		}
	}
}

int main(){
	int n;

	scanf("%d", &n);
	REP(i, 1, n){
		int j, k;
		scanf("%d%d", &j, &k);
		e[j].PB(k),e[k].PB(j);
		d[j]++,d[k]++;
	}
	
	queue<int> q;
	REP(i, 1, n) if (d[i] == 1) q.push(i);

	while(!q.empty()){
		int x = q.front();
		q.pop();
		d[x] = 0;
		TR(i, e[x]) {
			int y = *i;
			d[y]--;
			if (d[y] == 1) q.push(y);
		}
	}

	MS(ans, -1);
	REP(i, 1, n) if (d[i] > 0) ans[i] = 0;
	REP(i, 1, n) if (d[i] > 0) dfs(i, 0); 
	REP(i, 1, n - 1) cout << ans[i] << " ";
	cout << ans[n] << endl;
	return 0;
}


