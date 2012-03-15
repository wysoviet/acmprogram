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

char s[2000];
int a[2000], b[2000], c[5000000]; 
int fa, fb, na, nb, nc;

void read(int a[], int &f, int &n) {
	cin >> s;
	n = strlen(s);
	char *p = s;
	if (s[0] == '-') f = -1, p++, n--;
	else f = 1;
	for (int i = n - 1; ~i; i--, p++)
		a[i] = *p - '0';
}
	
void mul(int a[], int b[], int c[]){
	for (int i = 0; i < na; i++)
		for (int j = 0; j < nb; j++){
			c[i + j] += a[i] * b[j];
			c[i + j + 1] += c[i + j] / 10;
			c[i + j] %= 10;
		}

	nc = na + nb + 1;
	while (c[nc] == 0) nc--;
}

int main(){
	read(a, fa, na);
	read(b, fb, nb);
	mul(a, b, c);
	if (fa * fb < 0) cout << "-";
	for (int i = nc; ~i; i--)
		cout << c[i];
	cout << endl;
	return 0;
}


