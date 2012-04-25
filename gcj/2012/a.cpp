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

char f[128];

int main() {
	f['e'] = 'o';
	f['j'] = 'u';
	f['p'] = 'r';
	f[' '] = ' ';
	f['m'] = 'l';
	f['y'] = 'a';
	f['s'] = 'n';
	f['l'] = 'g';
	f['c'] = 'e';
	f['k'] = 'i';
	f['d'] = 's';
	f['x'] = 'm';
	f['v'] = 'p';
	f['n'] = 'b';
	f['r'] = 't';
	f['i'] = 'd';
	f['b'] = 'h';
	f['y'] = 'a';
	f['a'] = 'y';
	f['h'] = 'x';
	f['w'] = 'f';
	f['f'] = 'c';
	f['o'] = 'k';
	f['g'] = 'v';	
	f['t'] = 'w';
	f['u'] = 'j';
	f['z'] = 'q'; 
	f['q'] = 'z';

	int n;
	char s[200];
	freopen("a.in","r",stdin);
	freopen("a.ans", "w", stdout);
	
	cin >> n;
	getchar();
	for (int ca = 1; ca <= n; ca++){
		gets(s);
		printf("Case #%d: ", ca);
		for (int i = 0; s[i]; i++)
			cout << f[s[i]];
		cout << endl;
	}
	return 0;
}

