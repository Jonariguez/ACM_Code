/****************
*PID:hdu5600
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=1000000+5;
int a[maxn];

int main()
{
    int i,n,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        if(n==1){
            if(a[1])
                puts("YES");
            else puts("NO");
            continue;
        }
        a[1]=1-a[1];
        int yes=a[1];
        for(i=1;i<n-1;i++)
            if(yes)
                yes=a[i+1];
            else yes=(a[i+1]^1);
        if(yes!=a[n])
            puts("YES");
        else puts("NO");
    }
    return 0;
}
