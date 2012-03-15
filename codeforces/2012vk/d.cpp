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
#define DEB(x) cout << #x << " : " << x << endl
#define DEBA(a, n) REP(i, n) cout << #a << "[" << i << "] : " << a[i] << endl

using namespace std;

int n;
char s[2010];
long long l[2010], r[2010];

int main() {
	scanf("%s", s);
	n = strlen(s);
	for (int i = 0; i < n; i++) {
		for (int j = 0; i-j >= 0 && i+j < n; j++)
			if (s[i-j] != s[i+j]) break;
			else l[i-j]++, r[i+j]++;
		for (int j = 1; i-j+1 >= 0 && i+j < n; j++)
			if (s[i-j+1] != s[i+j]) break;
			else l[i-j+1]++, r[i+j]++;
	}
	
	long long ans = 0;
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			ans += r[i] * l[j];
	cout << ans << endl;
	return 0;
}


