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

char s[100];
int n;

bool gao(int x){
	char t[100];
	for (int i = 0; i < x; i++)
		t[i] = s[i];
	t[x] = 0;
	
	for (int i = 0; i < n; i += x)
		for (int j = 0; j < x; j++)
			if (s[i + j] != t[j]) return 0;
	return 1;
}

int main(){
	cin >> s;
	n = strlen(s);
	for (int i = 1; i <= n; i++)
		if (n % i == 0 && gao(i)) { cout << i; return 0;}
}


