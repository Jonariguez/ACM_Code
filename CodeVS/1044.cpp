/****************
*PID:cdvs1044
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=10003;
int dp[maxn],a[maxn],pos[maxn],n;

void delet(int p){
    int i;
    for(i=p;i<n;i++) a[i]=a[i+1];
}

int main()
{
    int i,j;
    n=0;
    while(scanf("%d",&i)==1) a[++n]=i;
  //  for(i=1;i<=n;i++)
  //      scanf("%d",&a[i]);
    int res=0;
    for(i=1;i<=n;i++){
        dp[i]=1;
        for(j=1;j<i;j++)
            if(a[j]>=a[i]) dp[i]=max(dp[i],dp[j]+1);
    }
    for(i=1;i<=n;i++)
        res=max(res,dp[i]);
    printf("%d\n",res);
    int cnt=0;
    while(n>1){
        memset(pos,0,sizeof(pos));
        res=0;
        int b=1;
        for(i=1;i<=n;i++){
            dp[i]=1;
            for(j=1;j<i;j++)
                if(a[j]>=a[i] && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    pos[i]=j;
                }
            if(res<=dp[i]){
                res=dp[i];b=i;
            }
        }
        for(i=1;i<=n;i++)
            if(res<=dp[i]){
                res=dp[i];b=i;
            }
        cnt++;
        while(b){
            delet(b);b=pos[b];
            n--;
        }
    }
    if(n==1) cnt++;
    printf("%d\n",cnt);
    return 0;
}

