#include <string.h>
#include <stdio.h>
int main(){
	char s[100];
	int n, i;
	scanf("%s", s);
	n = strlen(s);
	printf("%d\n", n);
	for (i = 0; i < n; i++)
	printf("%d\n", s[i]);
	for (i = 0; i < n; i++)
	putchar(s[n - i - 1]);
	puts("");
	return 0;
}

