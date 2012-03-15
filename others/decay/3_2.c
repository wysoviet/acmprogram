#include <stdio.h>
int main(){
	double r, h;
	const double pi = 3.141593;
	scanf("%lf%lf", &r, &h);
	printf("circle perimeter: %.2f\n", 2 * pi * r);
	printf("circle aera: %.2f\n", pi * r * r);
	printf("sphere aera: %.2f\n", 4 * pi * r * r);
	printf("sphere volume: %.2f\n", 4.0 / 3 * pi * r * r * r);
	printf("cylinder volume: %.2f\n", pi * r * r * h);
	return 0;
}

