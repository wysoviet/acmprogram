#include <cstdio>

int main(){
	unsigned int x, b, t, c, m;
	int cas = 0, n;

	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%d", &x);
		b = x & -x;
		t = x + b;
		c = t ^ x;
		m = (c >> 2) / b;
		printf("Case #%d:\n%d\n", i, t | m);
	}
	return 0;
}

