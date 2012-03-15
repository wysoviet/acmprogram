#include <stdio.h>
int main(){
	int x, i, j;
	char a[100];
	scanf("%d", &x);
	for (i = 0; x; i++, x /= 10)
		a[i] = x % 10 + '0';
	for (j = 0; j < i / 2; j++)
		a[j] ^= a[i - 1 - j] ^= a[j] ^= a[i - 1 - j];
	printf("%s\n", a);
	return 0;
}
