/****************
*PID:hdu5122
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=1000000+10;
int a[maxn],sum[maxn];

int main()
{
    int i,j,res,n,T,kcase=1;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        sum[n+1]=n+1;
        for(i=n;i>0;i--)
            sum[i]=min(sum[i+1],a[i]);
        res=0;
        for(i=1;i<n;i++)
            if(a[i]>sum[i])
                res++;
        printf("Case #%d: %d\n",kcase++,res);
    }
    return 0;
}
