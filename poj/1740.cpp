#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int n, i, j, flag;
	while (scanf("%d", &n), n) {
		int a[100];
		flag = 0;
		for (int i = 0; i < n; i++) scanf("%d", a + i);
		if (n & 1) flag = 1;
		else {
			for (int i = 0; i < n && !flag; i++) {
				for (int j = i + 1; j < n; j++)
					if (a[i] == a[j]) {
						a[i] = a[j] = 0;
						break;
					}
				if (a[i]) flag = 1;
			}
		}
		cout << flag << endl;
	}
	return 0;
}

