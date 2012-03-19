#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>

using namespace std;

int go(int x)
{
    int y = x/4 - x/100 + x/400;
    return y;
}

int main()
{
    int T, nowCase = 0;
    string s,a,t,b;
    cin >> T;
    while (T--)
    {
        int d1, d2;
        cin >> s >> a >> d1;
        cin >> t >> b >> d2;
        s = string(s, 0, 3);
        t = string(t, 0, 3);
        if (s != "Jan" && s != "Feb")
            ++d1;
        if (t == "Jan")
            --d2;
        else if (t == "Feb")
        {
            if (b != "29,")
                --d2;
        }
        printf("Case %d: %d\n",++nowCase,go(d2)-go(d1-1));
    }
    return 0;
}
