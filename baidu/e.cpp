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

char s[1000];
int main() {
	scanf("%s", s);
	int n = strlen(s);
	bool fc = 0, fj = 0;
	REP(i, n) if (s[i] >= 'A' && s[i] <= 'Z') fj = 1;
	else if (s[i] == '_') fc = 1;	
	if (fj  && fc) puts("Error!");
	else if (fj && s[0] >= 'A' && s[0] <= 'Z') puts("Error!");
	else if (fc && (s[0] == '_' || s[n-1] == '_')) puts("Error!");
	else {
		char a[1000], m = 0;
		if (fj) REP(i, n) {if (s[i]<'a') {a[m++] = '_'; s[i] +=32;}
			a[m++] = s[i];
		}else REP(i, n) {if (s[i] == '_') {s[i+1] -= 32;continue;}
				else if (s[i] == '_'-32) {puts("Error!");
				return 0;} 
			a[m++] = s[i];}
		a[m++] = 0;
		puts(a);
	}
	
	return 0;
}


