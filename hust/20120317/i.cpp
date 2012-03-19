#include <iostream>
#include <string>
#include <queue>
#include <stdio.h>
#include <string.h>
#include <algorithm>

#define REP(i,n) for (int i = 0;i < n;++i)

using namespace std;

const int MOD = 1000000007;

int N, M, K;
char a[311], b[311], c[311];
int f[311][111][111], next[311];
int g[311][111][111], gg[311][111][111];
int go[311][111][111];
char ch[311][111][111];

inline void proc (int &x)
{
    if (x >= MOD) x -= MOD;
    if (x < 0) x += MOD;
}

int main()
{
    int T, nowCase = 0;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%s%s%s", b, c, a);
        
        N = strlen(a);
        M = strlen(b);
        K = strlen(c);
        
        while (N > 0 && a[N-1] != b[M-1] && a[N-1] != c[K-1]) --N;
        
        reverse(b, b+M);
        reverse(c, c+K);
        
        int dx = 1;
        
      //  cout << a << " " << b << " " << c << endl;
        
        for (int i = 0;i < N; ++i)
        {
            next[i] = N;
            for (int j = i+1; j < N;++j)
                if (a[i] == a[j])
                {
                    next[i] = j;
                    break;
                }
        }
        
        for (int i = 0;i <= N;++i)
            for (int j = min(N-i,M)+1; ~j; --j)
                for (int k = min(N-i,K)+1; ~k; --k)
                {
                    f[i][j][k] = 0x7f7f7f7f;
                    g[i][j][k] = gg[i][j][k] = 0;
                    go[i][j][k] = -1;
                    ch[i][j][k] = 123;
                }
                
        f[N][0][0] = 0;
        g[N][0][0] = 1;
        go[N][0][0] = -1;
        for (int i = N-1; i >= 0; --i)
            for (int j = 0, lj=min(N-i,M); j <= lj; ++j)
                for (int k = 0, lk = min(N-i,K); k <= lk; ++k)
                {
                //    cout << i << " " << j << " " << k << endl;
                    int &now = f[i][j][k],
                        &plan = g[i][j][k],
                        &pp = gg[i][j][k],
                        &pos = go[i][j][k];
                    char &cc = ch[i][j][k];
                                        
                    now = f[i+1][j][k];
                    plan = g[i+1][j][k];
                    pp = 0;
                    pos = 0;
                    cc = ch[i+1][j][k];
                    
                    if (j <= M && k <= K && j && k && a[i] == b[j-1] && a[i] == c[k-1])
                    {
                        if (f[i+1][j-1][k-1]+1 < now)
                        {
                            now = f[i+1][j-1][k-1] + 1;
                            cc = a[i];
                            plan = pp = 0;
                            pos = 3;
                        }
                        if (f[i+1][j-1][k-1]+1 == now)
                        {
                            pp += g[i+1][j-1][k-1];
                            plan += g[i+1][j-1][k-1];
                            if (next[i] < N)
                            {
                                plan -= gg[next[i]][j][k];
                                pp -= gg[next[i]][j][k];
                            }
                            if (a[i] < cc)
                            {
                                cc = a[i];
                                pos = 3;
                            }
                        }
                        proc(plan);
                        proc(pp);
                    }
                    else
                    if (j <= M && j && a[i] == b[j-1])
                    {
                        if (f[i+1][j-1][k]+1 < now)
                        {
                            now = f[i+1][j-1][k] + 1;
                            cc = a[i];
                            plan = pp = 0;
                            pos = 1;
                        }
                        if (f[i+1][j-1][k]+1 == now)
                        {
                            pp += g[i+1][j-1][k];
                            plan += g[i+1][j-1][k];
                            if (next[i] < N)
                            {
                                plan -= gg[next[i]][j][k];
                                pp -= gg[next[i]][j][k];
                            }
                            if (a[i] < cc)
                            {
                                cc = a[i];
                                pos = 1;
                            }
                        }
                        proc(plan);
                        proc(pp);
                    }
                    else
                    if (k <= K && k && a[i] == c[k-1])
                    {
                        if (f[i+1][j][k-1]+1 < now)
                        {
                            now = f[i+1][j][k-1] + 1;
                            cc = a[i];
                            plan = pp = 0;
                            pos = 2;
                        }
                        if (f[i+1][j][k-1]+1 == now)
                        {
                            plan += g[i+1][j][k-1];
                            pp += g[i+1][j][k-1];
                            if (next[i] < N)
                            {
                                plan -= gg[next[i]][j][k];
                                pp -= gg[next[i]][j][k];
                            }
                            if (a[i] < cc)
                            {
                                cc = a[i];
                                pos = 2;
                            }
                        }
                        proc(plan);
                        proc(pp);
                    }
                }
        int plan = 0, answer = f[0][M][K];
      //  cout << "answer = " << answer << endl;
        printf("Case %d: %d\n",++nowCase, g[0][M][K]);
        if (answer > N) printf("NOT FOUND\n");
        else
        {
            int x = 0, y = M, z = K;
            for (int i = 0; i < N;++i)
            {
                if (go[i][y][z] != 0)
                {
                    printf("%c", a[i]);
                    if (go[i][y][z] == 1)
                    {
                        --y;
                    }
                    else if (go[i][y][z] == 2)
                    {
                        --z;
                    } else --y, --z;
                }
            }
            printf("\n");
        }
    }
    return 0;
}
