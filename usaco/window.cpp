/*
ID:wysovie1
LANG:C++
TASK:window
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

struct window{
	char c;
	int x1, y1, x2, y2, s;
	void print() {printf("%d %d %d %d %c\n", x1, y1, x2, y2, c);}
	void init(){
		scanf("(%c,%d,%d,%d,%d)", &c, &x1, &y1, &x2, &y2);
		if (x1 > x2) swap(x1, x2);
		if (y1 > y2) swap(y1, y2);
		s = (x2-x1) * (y2-y1);
	}
};

vector<window> a;
window tmp;
char c;

int gao(int x1, int y1, int x2, int y2, int k) {
	if (k == -1) return (x2-x1)*(y2-y1);
	if (a[k].x1>x2||a[k].x2<x1||a[k].y1>y2||a[k].y2<y1) 
		return gao(x1, y1, x2, y2, k-1); 
	int s = 0;
	if (y1<a[k].y1) {s += gao(x1,y1,x2,a[k].y1,k-1);y1=a[k].y1;}
	if (y2>a[k].y2) {s += gao(x1,a[k].y2,x2,y2,k-1);y2=a[k].y2;}
	if (x1<a[k].x1) s += gao(x1,y1,a[k].x1,y2,k-1);
	if (x2>a[k].x2) s += gao(a[k].x2,y1,x2,y2,k-1);
	return s;
}

int main() {				
	freopen("window.in", "r", stdin);
	freopen("window.out", "w", stdout);

	while (~(c=getchar())){
		if (c <= 15) continue;
		if (c == 'w') {
			tmp.init();
			a.insert(a.begin(), tmp);
		}else { int flag = (c=='t')*3+(c=='b')*2+(c=='d')*1;
			scanf("(%c)", &c);
			TR(i, a) if (i->c==c) {
				int k = i-a.begin();
				if (!flag) {
					int s = gao(i->x1,i->y1,i->x2,i->y2,k-1);
					printf("%.3f\n", 100.0*s/a[k].s);
					break;
				}
				tmp = *i;
				a.erase(i);
				if (flag == 1) break;
				if (flag == 3) a.insert(a.begin(), tmp);
				else if (flag == 2) a.insert(a.end(), tmp);
				break;
			}
		}
	}
	return 0;
}


