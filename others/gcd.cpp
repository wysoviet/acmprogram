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

int x, y;

int ex_gcd(int a, int b, int &x, int &y){
	if (!b) { x = 1; y = 0; return a; }
	int t = ex_gcd(b, a % b, y, x);
	y -= a/b*x;
	return t;
}

int main(){
	int a, b;

	cin >> a >> b;
	int d = ex_gcd(a, b, x, y);
	cout << x << "*" << a << "+" << y << "*" << b << "=" << d << endl;
	return 0;
}


