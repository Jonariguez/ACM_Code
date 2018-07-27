/****************
*PID:hdu1025
*Auth:Jonariguez
*****************
LIS
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=500000+10;
int dp[maxn];

struct pp{
    int a,b;
}s[maxn];

int cmp(const pp &x,const pp &y){
    return x.a<y.a;
}

int main()
{
    int i,j,n,kcase=1;
    while(scanf("%d",&n)!=EOF){
        for(i=0;i<n;i++)
            scanf("%d%d",&s[i].a,&s[i].b);
        sort(s,s+n,cmp);
        fill(dp,dp+n+1,maxn);
        for(i=0;i<n;i++)
            *lower_bound(dp,dp+n,s[i].b)=s[i].b;
        printf("Case %d:\n",kcase++);
        int res=lower_bound(dp,dp+n,maxn)-dp;
        if(res>1)
            printf("My king, at most %d roads can be built.\n\n",res);
        else
            printf("My king, at most %d road can be built.\n\n",res);
    }
    return 0;
}
