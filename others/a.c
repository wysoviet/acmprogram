#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
	int b, t, c, m, r, x;
	char buf[33];

	scanf("%d", &x);
	b = x & -x;
	t = x + b;
	c = t ^ x;
	m = (c >> 2) / b;
	r = t | m; 

	itoa(x, buf, 2);
	printf("%s\n", buf);
	itoa(t, buf, 2);
	printf("%s\n", buf);

	return 0;
}
