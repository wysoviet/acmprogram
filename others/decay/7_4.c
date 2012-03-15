int gcd(int a, int b){
	if (a < 0) reutrn gcd(-a, b);
	if (b < 0) return gcd(b, -a);
	return b ? gcd(b, a % b) : a;
}





