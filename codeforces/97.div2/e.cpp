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

using namespace std;

const int maxn = int(1e5+10);
char s[maxn];
int a, b, c, n;
bool v[4];
char ans[4][3] = {"00", "01", "10", "11"};

int main(){
	cin >> s;
	n = strlen(s);
	a = count(s, s + n, '1');
	b = count(s, s + n, '0');
	c = count(s, s + n, '?');
	if (a < b + c + (n & 1)) v[0] = 1;
	if (a + c > b + (n & 1)) v[3] = 1;
	int d = a - b - (n & 1);
	int t = c - abs(d);
	//DEB(s); DEB(n); DEB(a); DEB(b); DEB(c); DEB(d); DEB(t);
	if (t >= 0 && (t % 2 == 0)) {
		char &x = s[n - 1];
		if (x == '0') v[2] = 1;
		if (x == '1') v[1] = 1;
		if (x == '?') { 	
			if (!t && d > 0 || t) v[2] = 1;
			if (!t && d < 0 || t) v[1] = 1;
		}
	}
	REP(i, 0, 3) if (v[i]) cout << ans[i] << endl;
	return 0;
}


