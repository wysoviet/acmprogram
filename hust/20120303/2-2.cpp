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

#define lowbit(x) ((x)&(-(x)))
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define REPD(i, b, a) for (int i = b; i >= a; i--)
#define TR(it, a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define ALL(a) a.begin(),a.end()
#define PB(i) push_back(i)
#define MS(a, i) memset(a, i, sizeof(a))
#define DEB(x) cout << #x << " : " << x << endl
#define DEBA(a, n) REP(i, 0, n - 1) cout << #a << "[" << i << "] : " << a[i] << endl

using namespace std;

const int maxn = 1000010;
bool isnpri[maxn] = {0};
int pri[80000], npri = 0, phi[maxn] = {0};

int main(){
	phi[1] = 1;
	for (int i = 2; i < maxn; i++) {
		if (!isnpri[i]) {
			pri[npri++] = i;
			phi[i] = i - 1;
		}
		for (int j = 0; pri[j] * i < maxn; j++) {
			isnpri[pri[j] * i] = 1;
			if (i % pri[j] == 0) {
				phi[pri[j] * i] = phi[i] * pri[j];
				break;
			} else phi[pri[j] * i] = phi[i] * (pri[j] - 1);
		}
	}

	
	int a, b;
	cin >> a >> b;
	int ans = 0;
	for (int i = a; i <= b; i++) ans += phi[i];
	cout << ans << endl;
	return 0;
}


