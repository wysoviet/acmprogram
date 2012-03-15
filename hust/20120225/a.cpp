#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 510;

int f[maxn][maxn], a[maxn][maxn], m[maxn][maxn];
int t1, t2;

int main(){
	int T, r, c;

	cin >> T;
	while (T--){
		cin >> r >> c;
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				scanf("%d", &a[i][j]);

		f[0][0] = m[0][0] = 0;
		for (int i = 1; i < r; i++) f[i][0] = f[i-1][0] + a[i][0], m[i][0] = min(f[i][0], m[i-1][0]);
		for (int i = 1; i < c; i++) f[0][i] = f[0][i-1] + a[0][i], m[0][i] = min(f[0][i], m[0][i-1]);
		for (int i = 1; i < r; i++)
			for (int j = 1; j < c; j++){
				if (f[i][j-1] > f[i-1][j]) f[i][j] = f[i][j-1] + a[i][j], m[i][j] = min(f[i][j], m[i][j-1]);
				else f[i][j] = f[i-1][j] + a[i][j], m[i][j] = min(f[i][j], m[i-1][j]);
			}


		cout << max(-m[r-1][c-1], 0) + 1 << endl;
	}

	return 0;
}
