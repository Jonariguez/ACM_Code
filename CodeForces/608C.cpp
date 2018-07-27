/****************
*PID:608c div2
*Auth:Jonariguez
*****************
dp[i]第i个灯亮着时前面最多能有多少个亮着的
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=1000000+5;
int index[maxn],dp[maxn];
struct pp{
    int a,b;
}s[100005];

int cmp(const pp &x,const pp &y){
    return x.a<y.a;
}

int main()
{
    int i,j,n,m;
    while(scanf("%d",&n)!=EOF){
        int r=0;
        for(i=1;i<=n;i++){
            scanf("%d%d",&s[i].a,&s[i].b);
            s[i].a++;
            r=max(r,s[i].a);
        }
        sort(s+1,s+1+n,cmp);
        int cnt=0;
        j=0;
        for(i=1;i<=n;i++){
            while(j<s[i].a){
                index[j]=cnt;j++;
            }
            cnt++;
        }
    //    for(i=0;i<=r;i++) printf("%d ",index[i]);
   //     puts("");
        dp[0]=0;
        for(i=1;i<=n;i++){
            dp[i]=dp[index[max(0,s[i].a-s[i].b-1)]]+1;
        }
        int res=n+1;
        for(i=1;i<=n;i++)
            res=min(res,(i-dp[i])+n-i);
        printf("%d\n",res);
    }
    return 0;
}
