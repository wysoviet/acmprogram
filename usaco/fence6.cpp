/*
ID:wysovie1
LANG:C++
TASK:fence6
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

#define REP(i, a, b) for (int i = a; i <= b; i++)
#define TR(it, a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define ALL(a) a.begin(),a.end()
#define PB(i) push_back(i)
#define MS(a, i) memset(a, i, sizeof(a))
#define DEB(x) cout << #x << " : " << x << endl
#define DEBA(a, n) REP(i, 0, n - 1) cout << #a << "[" << i << "] : " << a[i] << endl

using namespace std;

const int INF = 1 << 25;
int a[200][200], b[200][200], l[200], le[200][200], rig[200][200];
int n, s, ans;

int main(){
	freopen("fence6.in", "r", stdin);
	freopen("fence6.out", "w", stdout);

	scanf("%d", &n);
	for (int i =1; i <= n; i++) 
		for (int j = 1; j <= n; j++)
			a[i][j] = INF;

	for (int i = 1; i <=n ; i++){
		cin >> s; cin >> l[s];
		cin >> le[s][0] >> rig[s][0];
		for (int j = 1; j <= le[s][0]; j++) cin >> le[s][j];
		for (int j = 1; j <= rig[s][0]; j++) cin >> rig[s][j];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= le[i][0]; j++) a[i][le[i][j]]=l[i]+l[le[i][j]];
		for (int j = 1; j <= rig[i][0]; j++) a[i][rig[i][j]]=l[i] + l[rig[i][j]];
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			b[i][j] = a[i][j];

	ans = INF;
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= le[k][0]; i++) {
			int ii = le[k][i];
			if (ii < k) 
				for (int j = 1; j <= rig[k][0]; j++){
					int jj = rig[k][j];
					if (jj < k) ans = min(ans, a[ii][jj]+ b[k][ii] + b[k][jj]); }
		}
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				 a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
	}
	cout << ans / 2 << endl;
	return 0;
}


