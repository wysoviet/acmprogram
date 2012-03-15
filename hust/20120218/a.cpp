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
#define DEBA(a, n) REP(i, 0, n - 1) cout << #a << "[" << i << "] : " << a[i] << endl;

using namespace std;

const int maxn = 1000 + 10;
bool isp[maxn];
int p[maxn], np;

bool isprime(int x){
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0) return 0;
	return 1;
}

int makeprime(){
	for (int i = 2; i < maxn; i++)
		if (isprime(i)) p[np++] = i, isp[i] = 1;
}

bool gao(int x){
	for (int i = 0; i < np - 1 && p[i] + p[i + 1] <= x; i++)
		if (p[i] + p[i + 1] == x) {
			return 1;
		}
	return 0;
}

int main(){
	int n, m;

	makeprime();
	scanf("%d%d", &n, &m);
	int t = 0;
	for (int i = 2; i <= n; i++)
		 if (isp[i] && gao(i - 1)) t++;

	if (t >= m) puts("YES");
	else puts("NO");

	return 0;
}


