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

const int maxn = 10000 + 10;
int a[maxn];

int main(){
	int T, n;

	scanf("%d", &T);
	while (T--){
		scanf("%d", &n);
		for (int i = 0; i < n; i++) 
			scanf("%d", a + i);
		a[n] = 0;
		sort(a, a + n + 1);
		for (int i = 0; i < n; i++)
			a[i] = a[i + 1] - a[i] - 1;
		reverse(a, a + n);
		int  t = 0;
		for (int i = 0; i < n; i += 2)
			t ^= a[i];
		
		if (!t) printf("Bob will win\n");
		else printf("Georgia will win\n");
	}

	return 0;
}


