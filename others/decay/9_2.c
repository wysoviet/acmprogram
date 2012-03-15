#include <stdio.h>
int main(){
	int a[3][3], b[3][3];
	int i, j;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++){
			scanf("%d", &a[i][j]);
			b[j][i] = a[i][j];
		}
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++)
			printf("%d ", a[i][j]);
				puts("");
	}
	return 0;
}

