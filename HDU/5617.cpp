/****************
*PID:hdu5617
*Auth:Jonariguez
*****************
dp[i][x1][x2]:表示从(1,1)走i步后到达(x1,y1)，从(n,n)走i步到(x2,y2)，
两段经过的串相同的方案数。
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=500+5;
const int MOD=5201314;

int dp[2][maxn][maxn];
char str[maxn][maxn];

int main()
{
    int i,j,n,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%s",str[i]+1);
        if(str[1][1]!=str[n][n]){
            puts("0");continue;
        }
        int x1,y1,x2,y2,step,d=0;
        memset(dp,0,sizeof(dp));
        dp[0][1][n]=1;
        for(step=1;step<n;step++){
            memset(dp[d^1],0,sizeof(dp[d^1]));
            for(x1=1;x1<=step+1;x1++){
                y1=step+2-x1;
                if(y1>n) continue;
                for(x2=n;x2>=n-step;x2--){
                    y2=2*n-step-x2;
                   // if(y2<1 || y2>n) continue;
                    if(str[y1][x1]!=str[y2][x2]) continue;
                    int &ans=dp[d^1][x1][x2];
                  //  ans=0;
                    if(y1>1 && y2<n){
                        ans+=dp[d][x1][x2];
                        ans%=MOD;
                    }
                    if(y1>1 && x2<n){
                        ans+=dp[d][x1][x2+1];
                        ans%=MOD;
                    }
                    if(x1>1 && y2<n){
                        ans+=dp[d][x1-1][x2];
                        ans%=MOD;
                    }
                    if(x1>1 && x2<n){
                        ans+=dp[d][x1-1][x2+1];
                        ans%=MOD;
                    }
                }
            }
            d^=1;
        }
        int res=0;
        for(i=1;i<=n;i++){
            res+=dp[d][i][i];
            res%=MOD;
        }
        printf("%d\n",res);
    }
    return 0;
}
