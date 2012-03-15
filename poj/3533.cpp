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
#define DEBA(a, n) REP(i, 0, n - 1) cout << #a << "[" << i << "] : " << a[i] << endl

using namespace std;


int nim_product(int x, int y) {
   if(x == 0 || y == 0) return 0;
   if(x == 1 || y == 1) return x + y - 1;
   int m = 0;
   for(int i = 0; (1 << i) <= x; i ++)
       for(int j = 0; (1 << j) <= y; j ++) {
           if(x & (1 << i) && y & (1 << j)) {
                int s = max(i, j), t = min(i, j), k = 0;
                while((1 << k) <= s && (1 << k) <= t && !(s & (1 << k) && t & (1 << k))) k ++;
                if(s & (1 << k) && t & (1 << k)) {
                    m ^= nim_product((1 << (1 << k)) / 2 * 3, nim_product(1 << (s - (1 << k)), 1 << (t - (1 << k))));
                }
                else {
                    m ^= (1 << s) * (1 << t);
                }
           }
       }
   return m;
}

int main(){
	int a, b, c, n;

	while (~scanf("%d", &n)){
		int t = 0;
		while (n--){
			scanf("%d%d%d", &a, &b, &c);
			t ^= nim_product(nim_product(a, b), c);
		}
		if (t) puts("No");
		else puts("Yes");
	}
	return 0;
}


