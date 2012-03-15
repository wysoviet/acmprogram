#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 100 + 10;
int v[maxn], f[maxn], s[maxn], w[maxn];
int e[maxn][maxn];
int n, ans, m, k, cur, ss;

int gao(int x) {
	int t = 0, tmp;
	v[x] = ++cur;
	s[ss++] = x;
	for (int i = 1; i <= m; i++)
		if (e[x][i]) {
			e[x][i]--, e[i][x]--;
			if (!v[i]) tmp = gao(i) + 1;
			else {
				int q = s[--ss];
				while (q != i) w[q] = 1, q = s[--ss];
				ss++;
				return 1;
			}
			if (w[i]) t ^= tmp & 1;
			else t ^= tmp;
		}
	return t;
}

int main(){
	while (~scanf("%d", &n)){
		ans = 0;
		while (n--){
			memset(e, 0, sizeof(e));
			memset(v, 0, sizeof(v));
			memset(f, 0, sizeof(f));
			memset(w, 0, sizeof(w));
			scanf("%d%d", &m, &k);
			int i, j;
			cur = ss = 0;
			while (k--){
				scanf("%d%d", &i, &j);
				e[i][j]++, e[j][i]++;
			}
			ans ^= gao(1);
		}
		if (ans) puts("Sally");
		else puts("Harry");
	}
	return 0;
}
