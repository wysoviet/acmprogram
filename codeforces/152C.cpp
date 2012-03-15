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

#define REP(i, a, b) for (int i = a; i <= b; i++)
#define TR(it, a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define ALL(a) a.begin(),a.end()
#define PB(i) push_back(i)
#define MS(a, i) memset(a, i, sizeof(a))
#define DEB(x) cout << #x << " : " << x << endl
#define DEBA(a, n) REP(i, 0, n - 1) cout << #a << "[" << i << "] : " << a[i] << endl

using namespace std;

int main(){
	int n, m;
	string s[110];
	set<char> st;
	long long ans = 1;

	cin >> n >> m;
	REP(i, 0, n - 1) cin >> s[i];
	REP(i, 0, m - 1) { 
		st.clear();
		REP(j, 0, n - 1) st.insert(s[j][i]);
		ans = ans * st.size() % 1000000007;
	}

	cout << ans << endl;

	return 0;
}


