#include <stdio.h>
int a[100];
int main(){
	int i, t, j;
	for (i = 0; i < 10; i++)
		scanf("%d", a + i);
	for (i = 0; i < 10; i++) {
		t = i;
		for (j = i + 1; j < 10; j++)
		if (a[j] < a[t]) t = j;
		a[i] ^= a[t] ^= a[i] ^= a[t];
	}
	for (i = 0; i < 10; i++)
		printf("%d\n", a[i]);
	return 0;
}

