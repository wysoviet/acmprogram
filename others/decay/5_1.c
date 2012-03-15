#include <stdio.h>
int gcd(int a, int b){
	if (a < 0) return gcd(-a, b);
	if (b < 0) return gcd(a, -b);
	return b ? gcd(b, a % b) : a;
}

int main(){
	int a, b;
	scanf("%d%d", &a, &b);
	printf("%d\n", gcd(a, b));
	return 0;
}

