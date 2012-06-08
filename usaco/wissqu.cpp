/*
ID:wysovie1
LANG:C++
TASK:wissqu
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

struct pt{
	int x, y, c;
	pt(int a=0,int b=0, int d=0){
		x=a,y=b,c=d;
	}
	void p() {printf("%c %d %d\n", c+'A', x, y);}
}r[20];
int a[6][6], s[6] = {3, 3, 3, 4, 3};
int v[6][6];
char str[10];
int cnt;

int sum;
void gao(int l, int c) {
	//if (sum++ < 100) cout << l << endl;
	for (int i = 1; i <= 4; i++)
		for (int j = 1; j <= 4; j++) 
			if (!v[i][j] && a[i-1][j-1]!=c && a[i-1][j]!=c &&
			a[i-1][j+1]!=c && a[i][j-1]!=c && a[i][j]!=c &&
			a[i][j+1]!=c && a[i+1][j-1]!=c && a[i+1][j]!=c &&
			a[i+1][j+1]!=c) {
				int t = a[i][j];
				v[i][j] = 1;
				a[i][j] = c;
				s[c]--;
				r[l] = pt(i, j, c);
				if (l==15) {
					if (++cnt==1) REP(k, 16) r[k].p();
				}else REP(k, 5) if (s[k]) gao(l+1, k);
				s[c]++;
				a[i][j] = t;
				v[i][j] = 0;
			}
		
}

int main() {
	//freopen("wissqu.in", "r", stdin);
	//freopen("wissqu.out", "w", stdout);

	MS(a, -1);
	REP(i, 4) {
		cin >> str;
		REP(j, 4) a[i+1][j+1] = str[j]-'A';
	}
	gao(0, 3);
	cout << cnt << endl;
	return 0;
}


