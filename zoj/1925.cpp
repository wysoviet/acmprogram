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
#define ALL(a) a.begin(),a.end()
#define PB(i) push_back(i)
#define MS(a, i) memset(a, i, sizeof(a))
#define DEB(x) cout << #x << " : " << x << endl
#define DEBA(a, n) REP(i, 0, n - 1) cout << #a << "[" << i << "] : " << a[i] << endl

using namespace std;

int main(){
	char s[10];
	int n, l = 1, u = 10;

	while (scanf("%d", &n), n){
		scanf("%s%s", s, s);
		if (s[0] == 'h') u = min(n - 1, u);
		else if (s[0] == 'l') l = max(n + 1, l);
		     else {  
			     if (l > u || n < l || n > u) puts("Stan is dishonest");
			     else puts("Stan may be honest");
			     l = 1; u = 10;
		}
	}
	return 0;
}


