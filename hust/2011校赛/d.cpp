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
#define DEB(x) cout << #x << " : " << x << endl
#define sqr(x) ((x)*(x))

using namespace std;

int n, c, ans, l;
char s[110];
bool v[1100000];

void gao(int x, int y, int ll, int k) {
	int t = ((((x+100)*202+y+100)*102+ll)*102+k) % 1000003;
	if (k > n || v[t]) return;
	v[t] = 1;
	if (ll == l) { 
		if ((k & 1) == (n & 1))  ans = max(ans,sqr(x)+sqr(y));
		return;
	}		
	REP(i, 0, 1) {
		int ch = s[ll];
		if (i & 1) ch = 'F' + 'T' - ch;
		if (ch == 'F') gao(x, y + 1, ll + 1, k + i);
		else gao(y, -x, ll + 1, k + i);
	}
}

int main(){
	while (~scanf("%s%d", s, &n)){
		MS(v, 0);
		ans = 0, l = strlen(s);
		gao(0, 0, 0, 0);		
		printf("%d\n", ans);
	}

	return 0;
}


