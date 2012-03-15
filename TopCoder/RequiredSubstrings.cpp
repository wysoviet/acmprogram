#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

const int node = 2000;
const int mod = 1000000009;
const int ch = 26;
int chd[node][ch], sz;
int word[node];
int fail[node];
int Q[node];
int f[60][node][1 << 6];
int sw[1 << 8];
char s[1000010];

void ins(const char *a, int val) {
    int p = 0;
    for (; *a; a++) {
        int c = sw[*a];
        if (!chd[p][c]) {
            memset(chd[sz], 0, sizeof (chd[sz]));
            word[sz] = -1;
            chd[p][c] = sz++;
        }
        p = chd[p][c];
    }
    word[p] = val;
}

void ac() {
    int *s = Q, *e = Q;

    fail[0] = 0;
    for (int i = 0; i < ch; i++)
        if (chd[0][i]) {
            fail[chd[0][i]] = 0;
            *e++ = chd[0][i];
        }

    while (s != e) {
        int p = *s++;
        for (int i = 0; i < ch; i++) {
            if (chd[p][i]) {
                int v = chd[p][i];
                *e++ = v;
                fail[v] = chd[fail[p]][i];
            } else chd[p][i] = chd[fail[p]][i];
        }
    }
}

class RequiredSubstrings {
public:

    int solve(vector <string> words, int C, int L) {
        int n = words.size();
        for (int i = 0; i < ch; i++)
            sw['a' + i] = i;
        word[0] = -1;
        memset(chd[0], 0, sizeof (chd[0]));
        memset(f, 0, sizeof (f));
        sz = 1;
        for (int i = 0; i < n; i++)
            ins(words[i].c_str(), i);
        ac();
        f[0][0][0] = 1;
        for (int i = 0; i < L; i++)
            for (int j = 0; j < sz; j++) {
                for (int k = 0; k < 1 << n; k++)
                    if (f[i][j][k])
                        for (int p = 0; p < ch; p++) {
                            int q = chd[j][p];
                            if (word[chd[j][p]] == -1)
                                f[i + 1][q][k] = (f[i + 1][q][k] + f[i][j][k]) % mod;
                            else f[i + 1][q][k | 1 << word[q]] = (f[i][j][k] +
                                    f[i + 1][q][k | 1 << word[q]]) % mod;
                        }
            }
        int ans = 0;
        vector<int> b;
        for (int i = 0; i < 1 << n; i++) {
            int k = 0;
            for (int j = 0; j < n; j++)
                if (i >> j & 1) k++;
            if (k == C) b.push_back(i);
        }


        for (int i = 0; i < sz; i++)
            for (int j = 0; j < b.size(); j++)
                ans = (ans + f[L][i][b[j]]) % mod;
        return ans;
    }
};
