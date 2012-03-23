#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
using namespace std;
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
 
const int maxn = 22222;
struct Seg{
	int l , r , h , s;
	Seg() {}
	Seg(int a,int b,int c,int d):l(a) , r(b) , h(c) , s(d) {}
	bool operator < (const Seg &cmp) const {
		return h < cmp.h;
	}
}ss[maxn];
bool lbd[maxn<<2] , rbd[maxn<<2];
int numseg[maxn<<2];
int cnt[maxn<<2];
int len[maxn<<2];
void PushUP(int rt,int l,int r) {
	if (cnt[rt]) {
		lbd[rt] = rbd[rt] = 1;
		len[rt] = r - l + 1;
		numseg[rt] = 2;
	} else if (l == r) {
		len[rt] = numseg[rt] = lbd[rt] = rbd[rt] = 0;
	} else {
		lbd[rt] = lbd[rt<<1];
		rbd[rt] = rbd[rt<<1|1];
		len[rt] = len[rt<<1] + len[rt<<1|1];
		numseg[rt] = numseg[rt<<1] + numseg[rt<<1|1];
		if (lbd[rt<<1|1] && rbd[rt<<1]) numseg[rt] -= 2;//ä¸¤æ¡çº¿éå
	}
}
void update(int L,int R,int c,int l,int r,int rt) {
	if (L <= l && r <= R) {
		cnt[rt] += c;
		PushUP(rt , l , r);
		return ;
	}
	int m = (l + r) >> 1;
	if (L <= m) update(L , R , c , lson);
	if (m < R) update(L , R , c , rson);
	PushUP(rt , l , r);
}
int main() {
	int n;
	while (~scanf("%d",&n)) {
		int m = 0;
		int lbd = 10000, rbd = -10000;
		for (int i = 0 ; i < n ; i ++) {
			int a , b , c , d;
			scanf("%d%d%d%d",&a,&b,&c,&d);
			lbd = min(lbd , a);
			rbd = max(rbd , c);
			ss[m++] = Seg(a , c , b , 1);
			ss[m++] = Seg(a , c , d , -1);
		}
		sort(ss , ss + m);
		int ret = 0 , last = 0, lasth = 0, lastn = 0;
		for (int i = 0 ; i < m ; i ++) {
			if (ss[i].l < ss[i].r) update(ss[i].l , ss[i].r - 1 , ss[i].s , lbd , rbd - 1 , 1);
			ret += lastn * (ss[i].h - lasth);
			ret += abs(len[1] - last);
			last = len[1];
			lasth = ss[i].h;
			lastn = numseg[1];
			printf("%d\n", ret);
		}
		printf("%d\n",ret);
	}
	return 0;
}

