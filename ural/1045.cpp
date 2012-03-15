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
#define TR(it, a) for (vector<int>::iterator it = a.begin(); it != a.end(); ++it)
#define ALL(a) a.begin(),a.end()
#define PB(i) push_back(i)
#define MS(a, i) memset(a, i, sizeof(a))
#define DEB(x) cout << #x << " : " << x << endl

using namespace std;

const int maxn = 1000 + 10;
int v[maxn];
vector<int> e[maxn];

int gao(int x){
	int &t = v[x];
	t = 1;
	TR(i, e[x]) if (v[*i] == -1) 
		t = gao(*i) && t;
	return t = !t;
}

int main(){
	memset(v, -1, sizeof(v));	
	int n, k;
	scanf("%d%d", &n, &k);
	for (int p = 0, i, j; p < n - 1; p++){
		scanf("%d%d", &i, &j);
		e[i].PB(j);
		e[j].PB(i);
	}
	gao(k);
	//REP(i, 1, n) DEB(v[i]);

	if (v[k] == 0) puts("First player loses");
	else { 
		int ans = n; 
		TR(i, e[k]) if (v[*i] == 0) ans = min(ans, *i);
		printf("First player wins flying to airport %d\n", ans);
	}
	return 0;
}


