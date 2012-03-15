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

const int maxn = int(1e5+10);
int n, m, k;
vector<int> a, b, c;
string s;

int gao(int x, vector<int> a){
	int s = 1, e = x;
	TR(it, a) {
		s += *it, e += *it;
		if (s < 1 || s > x)  s -= *it;
		if (e < 1 || e > x)  e -= *it;
	}
	return e - s + 1;
}

int main(){
	cin >> n >> m >> k >> s;
 	TR(it, s) switch (*it) {
		case 'l' : a.PB(1); break;
		case 'r' : a.PB(-1); break;
		case 'u' : b.PB(1); break;
		case 'd' : b.PB(-1); break;
		case 'f' : c.PB(1); break;
		case 'b' : c.PB(-1); break; 
	}

	long long ans;
	ans = 1LL * gao(n, a) * gao(m, b) * gao(k, c);
	cout << ans << endl;
	return 0;
}


