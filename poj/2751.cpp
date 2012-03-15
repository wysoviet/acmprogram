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
#define ALL(a) a.begin(),a.end()
#define PB(i) push_back(i)
#define MS(a, i) memset(a, i, sizeof(a))
#define DEB(x) cout << #x << " : " << x << endl

using namespace std;

const int maxn = 10010;
struct data{
	int a, b;
	bool operator < (const data& x) const {
		if (a < b && x.a >= x.b) return 1;
		if (a < b && x.a < x.b) return a < x.a;
		if (a >= b && x.a >= x.b) return b > x.b;
		return 0;
	}
}a[maxn];

int main(){
	int n;

	while (scanf("%d", &n) && n){
		for (int i = 0; i < n; i++)
			scanf("%d%d", &a[i].a, &a[i].b);
		
		sort(a, a + n);
		int t1, t2; 
		t1 = t2 = 0;
		for (int i = 0; i < n; i++){
			t1 += a[i].a;
			t2 = max(t1, t2) + a[i].b;
		}

		printf("%d\n", t2);
	}
	return 0;
}


