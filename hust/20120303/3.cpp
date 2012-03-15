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

string a[53];
int n = 0;
const string c[4] = {"C", "D", "H", "S"};
const string d[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10","J", "Q", "K"};
const string s[4] = {"E", "S", "W", "N"};

int main(){
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 13; j++) 
			a[n].append(c[i]), a[n++].append(d[j]);

	srand(unsigned(time(NULL)));
	random_shuffle(a, a + n);
	for (int i = 0; i < 4; i++) {
		cout << s[i] << ": "; 
		for (int j = 0; j < 12; j++) cout << a[i*13+j] << " ";
		cout << a[i * 13 + 12] << endl;
	}

	return 0;
}


