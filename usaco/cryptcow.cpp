/*
ID:wysovie1
LANG:C++
TASK:cryptcow
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
#define REPD(i, b, a) for (int i = b; i >= a; i--)
#define TR(it, a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define ALL(a) a.begin(),a.end()
#define PB(i) push_back(i)
#define MS(a, i) memset(a, i, sizeof(a))
#define DEB(x) cout << #x << " : " << x << endl
#define DEBA(a, n) REP(i, 0, n - 1) cout << #a << "[" << i << "] : " << a[i] << endl

using namespace std;

const char g[] = "Begin the Escape execution at the Break of Dawn";
const int M = 99991;
char s[100];
bool v[M];

int ELFhash(char *key){
	unsigned long h = 0;
	while(*key) {
		h = (h << 4) + *key++;
		unsigned long g = h & 0xf0000000L;
		if (g) h ^= g >> 24;
		h &= ~g;
	}
	return h % M;
}

int cnt(char s[]) {
	int ret = 0;
	for (; *s; s++) ret += (*s == 'C');
	return ret;
}

bool check(char s[]){
	int q = 0, l = strlen(s);
	for (int i = 0; i < l && s[i] != 'C'; i++) if (s[i] != g[i]) return 0;
	for (int i = 1; i <= l && s[l - i] != 'W'; i++) if (s[l - i] != g[47 - i]) return 0;
	char t[100];
	for (; *s; s++) 
		if (*s == 'C' || *s == 'O' || *s == 'W') {
			t[q] = 0;
			//DEB(t);
			if (strstr(g, t) == NULL) return 0;
			q = 0;
		}else t[q++] = *s;
	t[q] = 0;
	//DEB(t);
	if (strstr(g, t) == NULL) return 0;
	return 1;	
}

bool gao(char s[]) {
	int ht = ELFhash(s);
	if (v[ht]) return 0;
	v[ht] = 1;
	if (strcmp(s, g) == 0) return 1;
	if (!check(s)) return 0;
	int l = strlen(s), q;
	char t[100];
	REP(i, 0, l - 1) if (s[i] == 'O')
		REP(j, 0, i - 1) if (s[j] == 'C')
		  	REPD(k, l - 1, i + 1) if (s[k] == 'W'){
				q = 0;
				REP(p, 0, j - 1) t[q++] = s[p];
				REP(p, i + 1, k - 1) t[q++] = s[p];
				REP(p, j + 1, i - 1) t[q++] = s[p];
				REP(p, k + 1, l - 1) t[q++] = s[p];
				t[q] = 0;
				if (gao(t)) return 1;
			}
	return 0;
}


int main(){
	freopen("cryptcow.in", "r", stdin);
	freopen("cryptcow.out", "w", stdout);

	gets(s);
	if (gao(s)) cout << "1 " << cnt(s) << endl;
	else cout << "0 0" << endl;
	return 0;
}


