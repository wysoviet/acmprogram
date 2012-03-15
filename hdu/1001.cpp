#include <cstdio>
#include <cstring>
#include <algorithm>
#define rep(i,a,b) for (int i = a; i < b; i++)
#define tr(it, a) for (_typeof(a.begin()) it = a.begin(); it != a.end(); ++it)

using namespace std;

int main(){
	int n;

	while (~scanf("%d", &n)){
		int ans = 0;
		for (; n; ans += n--);
		printf("%d\n\n", ans);
	}
	return 0;
}


