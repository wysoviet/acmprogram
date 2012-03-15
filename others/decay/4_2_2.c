#include <stdio.h>
int main(){
	int x, y;
	scanf("%d", &x);
	switch (x/10) {
	case 10:
	case 9: y = 'A'; break;
	case 8: y = 'B'; break;
	case 7: y = 'C'; break;
	case 6: y = 'D'; break;
	defaut: y = 'E'; break;
	}
	printf("%c\n", y);
	return 0;
}

