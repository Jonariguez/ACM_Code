/****************
*PID:446a div1
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
int dp[maxn][2],a[maxn],left[maxn],right[maxn];

int main()
{
    int i,j,n,m;
    while(scanf("%d",&n)!=EOF){
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        if(n<=2){
            printf("%d\n",n);continue;
        }
        left[0]=0;
        left[1]=0;
        int last=0;
        for(i=2;i<=n;i++){
            left[i]=last+1;
            if(a[i]>a[i-1]){
             //  .. left[i]=last+1;
                last++;
            }
            else
                last=0;
        }
      //  for(i=1;i<=n;i++) printf("%d ",left[i]);
     //   puts("");
        right[n]=0;last=0;
        for(i=n-1;i>=1;i--){
            right[i]=last+1;
            if(a[i]<a[i+1])
                last++;
            else last=0;
        }
     //   for(i=1;i<=n;i++) printf("%d ",right[i]);
     //   puts("");
        int res=2;
        a[0]=-2;a[n+1]=2e9;
        for(i=1;i<=n;i++){
            if(a[i+1]-a[i-1]>=2)
                res=max(res,left[i]+right[i]+1);
            else //if(a[i]<a[i+1])
                res=max(res,max(left[i],right[i])+1);
           // else if(a[i]>=a[i+1])
           //     res=max(res,right[i]+1);
        }
        printf("%d\n",res);
    }
    return 0;
}
