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
#define DEB(x) cout << #x << " : " << x << endl

using namespace std;

struct point{
	int x, y;
}a[8];

int c[8];

int dis(int i, int j){
	point d = a[c[i]], b = a[c[j]];
	return (d.x - b.x) * (d.x - b.x) + (d.y - b.y) * (d.y - b.y);
}

int main(){
	REP(i, 0, 7) cin >> a[i].x >> a[i].y;
	REP(i, 0, 7) c[i] = i;
	do {
		bool f = true;
		REP(i, 0, 3) if (dis(i, (i + 1) % 4) != dis((i + 1) % 4, (i + 2) % 4)) f = false;
		if (!f) continue;
		if (dis(4, 5) == dis(6, 7) && dis(5, 6) == dis(4, 7) && dis(5, 7) == dis(6, 4) && dis(0, 2) == dis(1, 3)){
			cout << "YES" << endl;
			REP(i, 0, 7) printf("%d%c", c[i] + 1, i % 4 == 3 ? '\n':' ');
			return 0;
		}
	}while (next_permutation(c, c + 8));
	cout << "NO" << endl;
	return 0;
}


