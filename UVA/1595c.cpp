#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int x[N], y[N], n, mx;

bool have(int i)
{
    for(int j = 0; j < n; ++j)
        if(y[i] == y[j] && x[i] + x[j] == 2 * mx) return true;
    return false;
}

int main()
{
    int cas, lx, rx, a, i;
    scanf("%d", &cas);
    while(cas--)
    {
        lx = rx = 0;
        scanf("%d", &n);
        for(i = 0; i < n; ++i)
        {
            scanf("%d%d", &a, &y[i]);
            x[i] = a * 2;
            if(x[i] < x[lx]) lx = i;
            if(x[i] > x[rx]) rx = i;
        }
        mx = (x[lx] + x[rx]) / 2;
        for(i = 0; i < n; ++i)
            if(!have(i)) break;

        if(i >= n) puts("YES");
        else puts("NO");
    }
    return 0;
}
