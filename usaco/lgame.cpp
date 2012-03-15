/*
ID:wysovie1
LANG:C++
TASK:lgame
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

using namespace std;

struct trie{
	int s, v;
	int next[26];
	trie() { s = 0; v = -1; MS(next, -1);}
};

trie a[72000];
char s[10];
int f[26] = {2, 5, 4, 4, 1, 6, 5, 5, 1, 7, 6, 3, 5, 2, 3, 5,
	7, 2, 1, 2, 4, 6, 6, 7, 5, 7};
trie tmp;
set< pair<string, string> > ans;
int m, n, cnt = 1;

void insert(char *s, int p) {
	for (; *s; s++) {
		int t = *s - 'a';
		if (a[p].next[t] == -1){
			trie tmp;
			tmp.s = a[p].s + f[t];
			a[p].next[t] = cnt;
			a[cnt++] = tmp;	
		}
		p = a[p].next[t];
	}
	a[p].v = 1;
}

int gao(char *s, int p) {
	for (; *s; s++) {
		int t = *s - 'a';
		if (a[p].next[t] == -1) return -1; 
		p = a[p].next[t];
	}
	return a[p].v * a[p].s;
}
	
int main() {	
	freopen("lgame.dict","r",stdin);
	while (scanf("%s", s) && s[0] != '.')
		insert(s, 0);

	freopen("lgame.in", "r", stdin);
	freopen("lgame.out", "w", stdout);
	scanf("%s", s);

	n = strlen(s);
	sort(s, s + n);
	do{
		int t1, t2;
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j <= n; j++)
				for (int k = j; k <= n; k++) { 
				char t3[10], t4[10];
				memcpy(t4, s, 10);
				memcpy(t3, s, 10);
				t3[j] = t4[k] = 0;
				t1 = gao(t3, 0);
				t2 = gao(t4 + j, 0);
				if (t1 + t2 > m) {
					m = t1 + t2;
					ans.clear();
					ans.insert(MP(t3, t4 + j));
				}else if (t1 + t2 == m)
					ans.insert(MP(t3, t4 + j));
			}

	}while(next_permutation(s, s + n));

	cout << m << endl;
	TR(i, ans) { 
		if (i->first > i->second && i->second != "") continue;
		cout << i->first;
		if (i->second != "") cout << " " << i->second;
		cout << endl;
	}
	return 0;
}


