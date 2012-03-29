#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<iostream>
#define REP(i, n) for (int i = 0; i < n; i++)
using namespace std;
struct pt {
	double x, y;
	void read() { scanf("%lf%lf", &x, &y);}
}a[6];

int ans = 0x7fffffff; 
bool v[6];

double gaox(double a1, double a2, double b1, double b2){
	return a1*b2 - a2*b1;
}

void gao(int p, int s) {
	if (p == 5) { ans = min(ans, s); return; }
	if (v[p]) { gao(p + 1, s); return; }
	double a1, a2, b1, b2, c1, c2, x, y;
	pt &t1 = a[p];
	v[p] = 1;
	bool flag = 0, tmp[6];
	memcpy(tmp, v, sizeof(v));
	for (int i = p + 1; i < 5; i++)
		if (!v[i]) {
			pt &t2 = a[i];
			c1 = t1.y, c2 = t2.y, a1 = t1.x * t1.x;
			a2 = t2.x * t2.x, b1 = t1.x, b2 = t2.x;
			if (fabs(gaox(a1,a2,b1,b2))<1e-8) continue;
			x = gaox(c1, c2, b1, b2)/gaox(a1, a2, b1, b2);	
			if (x>1e-8) continue;
			flag = 1;
			y = gaox(a1, a2, c1, c2)/gaox(a1, a2, b1, b2);	
			//cout << x << " " << y << endl;
			for (int j = p + 1; j < 5; j++)
				if (abs(x * a[j].x *a[j].x + y * a[j].x-a[j].y)<1e-8)
					v[j] = 1;
			gao(p + 1, s + 1);
			memcpy(v, tmp, sizeof(tmp));
		}

	if (flag == 0) gao(p + 1, s + 1);
	v[p] = 0;
}

int main() {
	REP(i, 5) a[i].read();

	gao(0, 0);
	cout << ans << endl;	
	return 0;
}


