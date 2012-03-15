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

const int maxn = 1000 + 10;
int a[maxn], n;

int main(){
	while (scanf("%d", &n), n){
		int t = 0, ans = 0;
		REP(i, 0, n - 1) {scanf("%d", a + i); t ^= a[i];}
		REP(i, 0, n - 1) if ((a[i] ^ t) < a[i]) ans++;
		printf("%d\n", ans);	
	}
	return 0;
}


