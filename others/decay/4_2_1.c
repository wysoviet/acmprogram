#include <stdio.h>
int main(){
	int x, y;
	scanf("%d", &x);
	if (x >= 90) y = 'A';
	else if (x >= 80) y = 'B';
	else if (x >= 70) y = 'C';
	else if (x >= 60) y = 'D';
	else y = 'E';
	printf("%c\n", y);
	return 0;
}

