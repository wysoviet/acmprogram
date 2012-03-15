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
#define rep(i, a, b) for (int i = a; i < b; i++)
#define tr(it, a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define pb(i) push_back(i)

using namespace std;

const int maxn = 1000 + 100;
int a[maxn], b[maxn], c[maxn];

int gao(int a[]){
	char s[maxn];

	scanf("%s", s);
	int l = strlen(s);

	rep(i, 0, l) a[l - i - 1] = s[i] - '0';

	return l;
}

int main(){
	int la, lb, T;
	
	scanf("%d", &T);
	rep(ca, 1, T + 1) {
		memset(c, 0, sizeof(c));
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		la = gao(a);
		lb = gao(b);
		int l = max(la, lb);
		rep(i, 0, l) {
			c[i] += a[i] + b[i];
			c[i + 1] += c[i] / 10;
			c[i] %= 10;
		}
		if (c[l]) l++;
		reverse(c, c + l);
		reverse(a, a + la);
		reverse(b, b + lb);
		printf("Case %d:\n", ca);
		rep(i, 0, la) printf("%d", a[i]);
		printf(" + ");
		rep(i, 0, lb) printf("%d", b[i]);
		printf(" = ");
		rep(i, 0, l) printf("%d", c[i]);
		puts("");
		if (ca < T) puts("");
	}
	return 0;
}


