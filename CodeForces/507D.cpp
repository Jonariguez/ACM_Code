/****************
*PID:507d div2
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

const int maxn=1000+10;
LL dp[maxn][105][2],fact[maxn];

int main()
{
    LL i,j,n,k;
    LL m;
    while(scanf("%I64d%I64d%I64d",&n,&k,&m)!=EOF){
        fact[0]=1%m;
        for(i=1;i<maxn;i++)
            fact[i]=(fact[i-1]*10)%k;
        memset(dp,0,sizeof(dp));
        dp[0][0][0]=1;
        for(i=0;i<n;i++){
            for(j=0;j<k;j++){
                for(int v=0;v<10;v++){
                    if(i==n-1 && v==0) continue;
                    LL now=(v*fact[i]+j)%k;
                    if(now==0 && v){
                        dp[i+1][now][1]+=dp[i][j][0];
                        dp[i+1][now][1]%=m;
                    }else {
                        dp[i+1][now][0]+=dp[i][j][0];
                        dp[i+1][now][0]%=m;
                    }
                    dp[i+1][now][1]+=dp[i][j][1];
                    dp[i+1][now][1]%=m;
                }
            }
        }
        LL res=0;
        for(i=0;i<k;i++)
            res+=dp[n][i][1];
        if(res<m) res+=m;
        printf("%I64d\n",res%m);
    }
    return 0;
}
