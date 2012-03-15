#include <stdio.h>
void main(){
	int a, b;
	unsigned c, d;
	long e, f;
	a = 100;
	b = -100;
	e = 50000;
	f = 32767;
	c = a;
	d = b;
	printf("%d,%d\n",  a, b);
	printf("%u,%u\n",  a, b);
	printf("%u,%u\n",  c, d);
	c = a = c;         
	d = b = f;         
	printf("%d,%d\n", a, b);
	printf("%u,%u\n", c, d);
}

