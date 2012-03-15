#include <string.h>
#include <stdio.h>
int main(){
	char s[100];
	int n, i;
	scanf("%s", s);
	n = strlen(s);
	for (i = 0; i < n; i++){
	s[i] += 4;
	if (s[i] > 'z'|| s[i] > 'Z' && s[i] < 'a') s[i] -= 26;
	}
	printf("%s\n", s);
	return 0;
}

