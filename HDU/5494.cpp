/****************
*PID:hdu5494
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=500+10;
int a[maxn],b[maxn],n,m;

int main()
{
    int i,j,sum1,sum2,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(i=1;i<=n;i++)
            scanf("%d",&b[i]);
        sort(a+1,a+1+n);
        sort(b+1,b+1+n);
        sum1=sum2=0;
        for(i=1;i<=m;i++)
            sum1+=a[i];
        for(i=n;i>=n-m+1;i--)
            sum2+=b[i];
        if(sum1>sum2)
            printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
