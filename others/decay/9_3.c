#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
	int n, D = 1;
	scanf("%d", &n);
	while (D <= 2 * n)
	D = (int)(ceil(1.5*D));
	printf("%d\n", 3 * n + 1 - D);
	return 0;
}
