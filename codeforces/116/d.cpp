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

const int maxn = 6e3;
char s[maxn];
int c[30];

bool gao(char *s) {
	int t[30], i;
	for (i = 1; i <= 26; i++)
		t[i] = c[i];
	for (i = 26; *s; s++) {
		for (; i && !t[i]; i--);
		if (i != *s) return i < *s;
		t[i]--;
	}
	for (; i && !t[i]; i--) ;
	return !i;
}

int main() {
	cin >> s;
	int n = strlen(s);
	REP(i, n) c[s[i]-'a'+1]++;
	cin >> s;
	int m = strlen(s);
	REP(i, m) s[i] -= 'a' - 1;

	if (gao(s)) puts("-1");
	else {	
		char *p = s;
		for (; *p; p++) {
			int j;
			for (j = *p; !c[j]; j++); c[j]--;
			if (j > *p) { putchar(j+'a'-1); break;}
			if (gao(p + 1)){
				c[j]++;
				for (j++; !c[j]; j++);
				c[j]--;
			}
			putchar(j+'a'-1);
			if (j > *p) break;
		}
		for (int i = 1; i <= 26; i++)
			while(c[i]--) putchar(i+'a'-1);
	}
	return 0;
}

