#include <stdio.h>
#include <ctype.h>
int main(){
	char s[1000];
	int n, i, num, letter, space, other;
	num = letter = space = other = 0;
	scanf("%s", s);
	for (i = 0; i < n; i++) {
	num += isdigit(s[i]);
	letter += isalpha(s[i]);
	space += (s[i] == ' ');
	other += !(isalnum(s[i]) + s[i] == ' ');
	}
	printf("num: %d\nletter: %d\nspace :%d\nother :%d\n", num,
	letter, space, other);
	return 0;
}

