/****************
*PID:613b div2
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn=100000+10;
int dp[maxn],d[maxn];

struct pp{
    int st,en;
}s[maxn*2];

int cmp(const pp &x,const pp &y){
    if(x.st==y.st)
        return x.en<y.en;
    return x.st<y.st;
}

int main()
{
    int i,j,n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        memset(d,0,sizeof(d));
        int a,b;
        for(i=0;i<m;i++){
            scanf("%d%d",&a,&b);
            s[i].st=min(a,b);s[i].en=max(a,b);
            d[s[i].st]++;d[s[i].en]++;
        }
        sort(s,s+m,cmp);
       // memset(dp,0,sizeof(dp));
        for(i=1;i<=n;i++) dp[i]=1;
        for(i=0;i<m;i++){
            int a=s[i].st,b=s[i].en;
            dp[b]=max(dp[b],dp[a]+1);
        }
     //   for(i=1;i<=n;i++)
     //       printf("%d ",dp[i]);
     //   puts("");
        LL res=0;
        for(i=1;i<=n;i++){
            res=max(res,(LL)dp[i]*d[i]);
        }
        printf("%I64d\n",res);
    }
    return 0;
}
