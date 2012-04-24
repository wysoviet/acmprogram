/*
ID:wysovie1
LANG:C++
TASK:
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
int b, d;
int v[1000][10] = {0}, t[10];
int p[100], np = 0;
int c[10] = {2, 3, 11, 6, 7};

int main() {
	cin >> b >> d;
	for (int i = 2, j = b; i <= b && j > 1; i++)
		if (j % i == 0) {
			p[np++] = i;
			while (j % i == 0) j /= i;
		}
	
	for (int i = 2; i <= d; i++) {
		int k = i;
		for (int j = 0; j < np; j++)
			while (k % p[j] == 0) k /= p[j];
		if (k == 1) v[i][0] = 1;
		if (b % i == 1) v[i][1] = 1;
		if (b % i == i - 1) v[i][2] = 1;
		for (int j = 2; j * j <= i; j++)
			if (i % j == 0 && !v[j][4] && !v[i/j][4]) {
				REP(q, 4) t[q] = v[j][q] | v[i/j][q];
				REP(q, 4) if (v[j][q] != t[q]) {
					v[i][3] = 1;
				}
			}
			
		if (v[i][0] + v[i][1] + v[i][2] + v[i][3] == 0) 
			v[i][4] = 1;
	}
	
	REP(i, 5) if (v[d][i]) {
		printf("%d-type\n", c[i]);
		if (i == 0) {
			int ans = 1;
			for (int j = b; j % d;j *= b, ans++);
			cout << ans << endl;
		}
		return 0;
	}
}


