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

char s[1100], os[1100];
int a[1100], ns[1100], to, tn, ta;
int n, ret;
int r[128];

int gao(int x, int y, char c){
	switch (c) {
		case '+': return x + y;
		case '-': return x - y;
		case '*': return x * y;
	}
}

int main() {
	r['+'] = r['-'] = 1;
	r['*'] = 2;r[')'] = 3;r['('] = 0;
	while (scanf("%d", &n), n) {
		REP(i, n) scanf("%d", a + i);
		sort(a, a + n);
		scanf("%d", &ret);
		scanf("%s", s);
		int m = strlen(s);
		s[m] = ')'; s[m + 1] = 0;
		bool flag = 0;
		do {
			to = tn = ta = 0;
			os[to++] = '(';
			for (char *p = s; *p; p++) {
				//DEBA(os, to); cout << endl;
				//DEBA(ns, tn); cout << endl;
				if (*p >= 'a' && *p <= 'z') ns[tn++] = a[ta++];
				else if (*p == ')') {
					while (os[--to] != '(') {
						int t1 = ns[--tn], t2 = ns[--tn];
						char tc = os[to];
						ns[tn++] = gao(t2, t1, tc);
					}
				}else if (r[*p] >= r[to-1]) os[to++] = *p;
				      else { int t1 = ns[--tn], t2 = ns[--tn];
						char tc = os[--to];
						ns[tn++] = gao(t2, t1, tc);
						os[to++] = *p;
					}
			}
			//DEB(ns[0]);
			if (ns[0] == ret) flag = 1;
		}while (next_permutation(a, a + n) && !flag);
		if (flag) puts("YES");
		else puts("NO");
	}
	return 0;
}


