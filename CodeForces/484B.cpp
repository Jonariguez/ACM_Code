/****************
*PID:484b div1
*Auth:Jonariguez
*****************
想要ai%aj最大，则ai越靠近aj的倍数且ai要小于aj的倍数，此时还最大。
那么对应每个aj，枚举其倍数x，然后找小于x的最大的ai。
领悟vis的妙处，vis[x]可以找到小于x的最大的ai
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=200000+10;
int vis[2000005],a[maxn];

int main()
{
    int i,j,n,res;
    while(scanf("%d",&n)!=EOF){
        memset(vis,0,sizeof(vis));
        int r=0;
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
            vis[a[i]]=a[i];
            r=max(r,a[i]);
        }
        for(i=1;i<=2*r;i++)
            if(vis[i]==0) vis[i]=vis[i-1];
     //   for(i=1;i<=2*r;i++) printf("%d ",vis[i]);
        res=0;
        sort(a,a+n);
        n=unique(a,a+n)-a;
     //   for(i=0;i<n;i++)
     //       printf("%d ",a[i]);
        for(i=0;i<n;i++){
            int x=a[i]*2;
            while(x<=2*r){
                int t=vis[x];
                if(t==x) t=vis[x-1];
                res=max(res,t%a[i]);
              //  printf("t=%d,a[i]=%d\n",t,a[i]);
                x+=a[i];
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
