#include <stdio.h>
int isprime(x){
	int i;
	if (x < 2) return 0;
	for (i = 2; i * i <= x; i++)
		if (x % i == 0) return 0;
	return 1;
}
int main(){
	int x;
	scanf("%d", &x);
	if (isprime(x)) printf("YES\n");
	else printf("NO\n");
	return 0;
}

