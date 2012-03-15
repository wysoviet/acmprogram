#include <string.h>
#include <stdio.h>
int main(){
	char s[3][100];
	char *p[3], *t;
	int i, j;
	for (i = 0; i < 3; i++)
		scanf("%s", s[i]);
	for (i = 0; i < 3; i++)
		p[i] = s[i];
	for (i = 0; i < 3; i++)
		for (j = 0; j < 2 - i; j++)
			if (strcmp(p[j], p[j + 1]) > 0)
			     t = p[j], p[j] = p[j + 1], p[j + 1] = t;
	for (i = 0; i < 3; i++)
		printf("%s\n", p[i]);
	return 0;
}

