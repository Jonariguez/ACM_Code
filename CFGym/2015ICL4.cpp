/****************
*PID:K
*Auth:Jonariguez
*****************
递推，每增加一个点，然后枚举与之前的n-1个点分别连线。
再加上不连该点的情况。
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long LL;
LL dp[44][44];

LL dfs(int n,int k){
    if(n<0 || k<0) return 0LL;
    if(2*k>n) return 0LL;
    if(n==0 && k==0) return 1LL;
    if(n==2 && k==1) return 1LL;
    if(n==3 && k==1) return 3;
    LL &res=dp[n][k];
    if(res>=0) return res;
    res=dfs(n-1,k);
    int i,j,v;
    for(i=1;i<n;i++){
        for(j=0;j<=k-1;j++){
            res+=dfs(i-1,j)*dfs(n-1-i,k-1-j);
        }
    }
    return res;
}



int main()
{
    int n,k;
    while(scanf("%d%d",&n,&k)!=EOF){
        memset(dp,-1,sizeof(dp));
        printf("%I64d\n",dfs(n,k));
    }
    return 0;
}
