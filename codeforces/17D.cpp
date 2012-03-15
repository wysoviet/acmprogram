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
	string b, n;
	long long c, s = 0, e = 1, t;
	cin >> b >> n >> c;
	for (int i = 0; i < b.size(); i++) s = (s * 10LL + b[i] - '0') % c;
	for (int i = n.size() - 1; n[i]--=='0'; n[i] = '9', i--);
	for (int i = 0; i < n.size(); i++) {
		t = e;
		for (int j = 1; j < 10; j++) e = e * t % c;
		for (int j = 0; j < n[i] - '0'; j++) e = e * s % c;
	}
	e = e * (s - 1 + c) % c;
	if (e) cout << e << endl;
	else cout << c << endl;

	return 0;
}


