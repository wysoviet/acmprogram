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

int main(){
	char s[200];

	gets(s);
	int l = strlen(s), ans = 0;

	REP(i, 0, l - 1){
		int tmp = 0;
		REP(j, 0, 7)
		tmp = tmp * 2 + (s[i] & 1), s[i] >>= 1;
		ans = (ans - tmp + 256) % 256;
	 	cout << ans << endl;	
		ans = tmp;
	}
	return 0;
}


