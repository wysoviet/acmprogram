#include <stdio.h>
double f(double x){
	return 6 * x * x - 8 * x + 3;
}
int main(){
	double ans = 1.5;
	int i = 0;
	for (i = 0; i < 100; i++)
	ans = f(ans);
	printf("%f\n", ans);
	return 0;
}

