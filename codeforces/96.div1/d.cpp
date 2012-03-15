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
#define DEB(x) cout << x << endl

using namespace std;

const int maxn = int(1e6 + 10);
char s[maxn];
int a[maxn], sum;

int main(){
	cin >> s + 1;
	int n = strlen(s + 1);
	reverse(s + 1, s + 1 + n);
	REP(i, 1, n + 1) {
		int j = i;
		while (s[i] == '1') i++;
		if (i == j + 1) a[j] = 1, sum++;
		else if (i > j + 1) {
			a[j] = -1, s[i] = '1';
			i--, sum++;
		}
	}

	cout << sum << endl;
	REP(i, 1, n + 1) if (a[i]) 
		if (a[i] > 0) printf("+2^%d\n", i - 1);
		else printf("-2^%d\n", i - 1);
	return 0;
}


