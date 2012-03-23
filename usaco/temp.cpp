#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 20010;
int wa[maxn], wb[maxn], wv[maxn], ws[maxn];
int height[maxn], sa[maxn], a[maxn];

int cmp(int *r, int a, int b, int l) {
    return r[a] == r[b] && r[a + l] == r[b + l];
}

void da(int *r, int n, int m){
    int i, j, k, p, *x = wa, *y = wb;
    memset(ws, 0, sizeof(int)*m);
    for (i = 0; i < n; i++) ws[x[i] = r[i]]++;
    for (i = 1; i < m; i++) ws[i] += ws[i-1];
    for (i = n-1; i >= 0; i--) sa[--ws[x[i]]] = i;
    for (j = 1, p = 1; p < n; j*=2, m=p){
        for (p = 0, i = n - j; i < n; i++) y[p++] = i;
        for (i = 0; i < n; i++) if (sa[i] >= j) y[p++] = sa[i] - j;
        memset(ws, 0, sizeof(int)*m);
        for (i = 0; i < n; i++) ws[x[y[i]]]++;
        for (i = 1; i < m; i++) ws[i] += ws[i-1];
        for (i = n - 1; i >= 0; i--) sa[--ws[x[y[i]]]] = y[i];
        for (swap(x,y), p=1, i=1, x[sa[0]]=0; i<n; i++)
            x[sa[i]] = cmp(y, sa[i-1], sa[i], j)?p-1:p++;
    }
    for (i = 0, k = 0; i < n - 1; height[x[i++]] = k)
        for (k?k--:0, j=sa[x[i]-1]; r[i+k]==r[j+k]; k++);
}

bool work(int l, int n){
    int ma = 0, mi = 0;
    for (int i = 1 ; i < n && ma-mi<l; i++)
        if (height[i] >= l) {
            ma = max(ma, sa[i]);
            mi = min(mi, sa[i]);
        }else ma = mi = sa[i];
    return ma-mi>=l;
}

int main(){
    int n;

    while (scanf("%d", &n)){
        if (!n) break;
        for (int i = 0; i < n; i++)
            scanf("%d" , a + i);
        for (int i = 0; i < n - 1; i++)
            a[i] = a[i+1] - a[i] + 88;
        a[n - 1] = 0;
        da(a, n, maxn);

        int l = 1, r = n - 1, mid;
        while (l < r){
            mid = (l+r)/2 + 1;
            if (work(mid, n)) l = mid;
            else r = mid - 1;
        }
        if (l<4) printf("0\n");
        else printf("%d\n", l + 1);
    }

    return 0;
}
