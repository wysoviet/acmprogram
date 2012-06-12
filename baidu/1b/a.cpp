#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;
const int maxn=70,maxm=100000+10;
typedef long long  lld;
lld a[maxm];
int gaus(int n,const int m=64) {
         int i,j,k;
         j=0;
         for (i=m-1;i>=0;i--) {
                   for (k=j;k<n;k++) if ((a[k]>>i)&1) break;
                   if (k<n) {
			    swap(a[k],a[j]);
                            for (k=0;k<n;k++)
				     if (k!=j && ( (a[k]>>i)&1 ))
					       a[k]^=a[j];
                            j++;
                   }
         }
         return j;
}

int n;
int main() {
	   scanf("%d",&n);
	   int i,j,k;
	   for (i=0;i<n;i++)
		    scanf("%lld",a+i);
	   k=gaus(n);
	   for (lld ask = (1ll<<k)-1; ask >= (1ll<<k)-2; ask--) {
		    lld res=0;
		    for (i=0;i<k;i++) if ((ask>>i)&1)
			       res^=a[k-i-1];
		    cout << res;
		    if (ask == (1ll<<k)-1) putchar(' ');
		    else puts("");
	   }
           return 0;
} 


