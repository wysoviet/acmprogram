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

bool dp[110][350][60][2];
string s;
int n, ans = -(1<<29);

char opp(char ch){
	return 'F'+'T'-ch;
}

void calc(int cur, int pos, int nn, int dir){
	if (cur == s.size()) {
		if (n == nn) {
		 	ans = max(ans, abs(pos - 150));
			return;
		}else return;
	}
	bool &ans = dp[cur][pos][nn][dir];
	if (ans) return;
	ans = true;
	for (int i = 0; i + nn <= n; i++){
		char ch = s[cur];
		if (i&1) ch = opp(ch);
		if (ch == 'T') calc(cur + 1, pos, i + nn, !dir);
		else calc(cur + 1, pos + ((dir == 1)?1:-1), i + nn, dir);
	}
}

int main(){
	cin >> s >> n;
	calc(0, 150, 0, 1);
	cout << ans << endl;
	return 0;
}


