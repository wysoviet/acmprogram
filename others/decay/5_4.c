#include <stdio.h>
int main(){
	int ans = 1, i;
	for (i = 9; i >= 1; i--)
	ans = (ans + 1) * 2;
	printf("%d\n", ans);
	return 0;
}

