#include <stdio.h>
int a[100];
int main(){
	int i, j, t, k, mid;
	for (i = 0; i < 15; i++)
		scanf("%d", a + i);
	for (i = 0; i < 15; i++){
		t = i;
		for (j = i + 1; j < 15; j++)
		if (a[j] < a[t] ) t = j;
		a[i] ^= a[t] ^= a[i] ^= a[t];
	}
	scanf("%d", &k);
	i = 0; j = 15;
	while (i < j){
		mid = i + j >> 1;
		if (a[mid] <= k) i = mid + 1;
		else if (a[mid] > k) j = mid;
	}
	if (i > j || i == 0) printf("无此数\n");
	else printf("%d\n", i - 1);
	return 0;
}


