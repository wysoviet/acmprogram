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

struct point {
	int x, y;
};

point a[8];
int ch[4], t[4], nch[4], flag;

int cross(point a, point b, point c){
	return (a.x-b.x)*(c.x-b.x) + (a.y-b.y)*(c.y-b.y);
}

int dis(point a, point b){
	return (b.x-a.x)*(b.x-a.x) + (b.y-a.y)*(b.y-a.y);
}

void pout(int c[]) {
	REP(i, 0, 2) cout << c[i] + 1 << " ";
	cout << c[3] + 1 << endl;
}

bool isr(int c[]) {
	do {
		bool f = true;
		REP(i, 0, 3) if (cross(a[c[i]], a[c[(i+1)%4]], a[c[(i+2)%4]])) f = false;  
		if (f) return true;
	}while (next_permutation(c, c + 4));
	return false;
}

bool isq(int c[]) {
	do {
		bool f = true;
		REP(i, 0, 3) if (cross(a[c[i]], a[c[(i+1)%4]], a[c[(i+2)%4]])) f = false;  
		REP(i, 0, 3) if (dis(a[c[i]], a[c[(i+1)%4]]) != dis(a[c[(i+1)%4]], a[c[(i+2)%4]]))  f = false;
		if (f) return true;
	}while (next_permutation(c, c + 4));
	return false;
}

int cnt;
void gao(int k, int n, int nn) {
	if (flag) return;
	if (n == 4 && nn == 4) {
			if (isq(ch) && isr(nch)) {
				flag = true;
				cout << "YES" << endl;
				pout(ch);
				pout(nch);
			}
			return;
		}
	if (n < 4) {ch[n] = k; gao(k + 1, n + 1, nn);}
	if (nn < 4) {nch[nn] = k; gao(k + 1, n, nn + 1);}
}

int main(){
	REP(i, 0, 7) cin >> a[i].x >> a[i].y;
	gao(0, 0, 0);
	if (!flag) cout << "NO" << endl;
	return 0;
}


