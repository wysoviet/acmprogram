#include <stdio.h>
#include <string.h>
#define CHANGE 1
int main(){
	char s[100];
	int n, i;
	scanf("%s", s);
	n = strlen(s);
	#if (CHANGE == 1)
	for (i = 0; i < n; i++){
		s[i]++;
		if (s[i] > 'z') s[i] = 'a';
	}
	#endif
	printf("%s\n", s);
	return 0;
}
