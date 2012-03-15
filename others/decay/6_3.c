#include <stdio.h>

int a[10][10];
int n, m, t;
int isgood(int x, int y){
	int i, j;
	for (i = 0; i < n; i++)
		if (a[i][y] < a[x][y]) return 0;
	for (i = 0; i < m; i++)
		if (a[x][i] > a[x][y]) return 0;
	return 1; 
}

int main(){
	int i, j;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			scanf("%d", &a[i][j]);
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			if (isgood(i, j)) printf("%d %d %d\n", i, j, a[i][j]);
	return 0;
}

