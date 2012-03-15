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

const int maxn = 100000 + 10;
bool f[maxn] = {0};
int a[maxn] = {0}, na = 0;

class CompositeSmash {
public:

    string thePossible(int N, int target) {
        memset(f, 0, sizeof(f));
        memset(a, 0, sizeof(a));
        na = 0;
        int n = N, m = 0, mp = 0;
        f[N] = 1;
        for (int i = 2; n != 1; i++)
            if (n % i == 0) {
                ++na, f[i] = 1;
                for (; n % i == 0; n /= i)
                    a[na]++;
                if (m < a[na]) {
                    m = a[na];
                    mp = i;
                }
            }
        int s = accumulate(a, a + na + 1, 0);
        if ((m - s + m) > 1) f[mp * mp] = 1;
        if (f[target]) return "Yes";
        else return "No";
    }
};
