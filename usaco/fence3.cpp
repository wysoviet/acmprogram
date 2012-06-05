/*
ID:wysovie1
LANG:C++
TASK:fence3
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

const int maxn = 200;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int st[maxn];
int n;
struct pt {
	int x, y;
	void read() { 
		scanf("%d%d", &x, &y); 
		x*=10, y*=10;
	}
	pt(int a=0, int b=0) {x=a, y=b;}
	pt(pt a, int d, int t) {x=a.x+dx[d]*t;y=a.y+dy[d]*t;}
}l[maxn], r[maxn];

double dis(pt &a, pt &b) {
	return sqrt(1.0*(a.x-b.x)*(a.x-b.x)+1.0*(a.y-b.y)*(a.y-b.y));
}

double gao(pt c) {
	double ret = 0;
	REP(i, n) {
		if (st[i]) {
			if (c.y >= r[i].y) ret += dis(r[i], c); 
			else if (c.y <= l[i].y) ret += dis(l[i], c);
			else ret += abs(c.x-r[i].x);
		}else {
			if (c.x >= r[i].x) ret += dis(r[i], c);
			else if (c.x <= l[i].x) ret += dis(l[i], c);
			else ret += abs(c.y - r[i].y);
		}
	}
	return ret;
}

int main() {
	freopen("fence3.in", "r", stdin);
	freopen("fence3.out", "w", stdout);

	cin >> n;
	REP(i, n) {l[i].read();r[i].read();}
	REP(i, n) {
		st[i] = (l[i].x == r[i].x); 
		if (st[i] && l[i].y > r[i].y) swap(l[i], r[i]);
		if (!st[i] && l[i].x > r[i].x) swap(l[i], r[i]);
	}	
	int t = 40;
	pt c;
	double ans = gao(c);

	while (t--) {
		//cout << c.x << " " << c.y << endl;
		REP(i, 200) REP(j, 4) {
			pt tmp(c, j, t);	
			double ret = gao(tmp);
			if (ret < ans) {
				ans = ret;
				c = tmp;
			}
		}
	}

	printf("%.1f %.1f %.1f\n", c.x/10.0, c.y/10.0, ans/10.0);
	return 0;
}


