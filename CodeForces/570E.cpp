/****************
*PID:570e div2
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

const int maxn=500+5;
const int MOD=1e9+7;
LL dp[2][maxn][maxn];
char str[maxn][maxn];

int main()
{
    int i,j,n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        for(i=1;i<=n;i++){
            scanf("%s",str[i]+1);
        }
        int d=0;
        if(str[1][1]!=str[n][m]){
            puts("0");continue;
        }
        if(n+m<=3){
            printf("%d\n",str[1][1]==str[n][m]);continue;
        }
        memset(dp[0],9,sizeof(dp[0]));
        dp[0][1][m]=1;
        int step,x1,x2,y1,y2;
        for(step=1;step<=(n-1+m-1)/2;step++){
            memset(dp[d^1],0,sizeof(dp[d^1]));
            for(x1=1;x1<=m;x1++){
                y1=step+2-x1;
                if(y1<1 || y1>n) continue;
                for(x2=m;x2>=1;x2--){
                    y2=n+m-x2-step;
                    if(y2<1 || y2>n) continue;
                    if(str[y1][x1]!=str[y2][x2]) continue;
                    LL &ans=dp[d^1][x1][x2];
                    if(x1>1 && x2<m){
                        ans+=dp[d][x1-1][x2+1];
                        ans%=MOD;
                    }
                    if(x1>1 && y2<n){
                        ans+=dp[d][x1-1][x2];
                        ans%=MOD;
                    }
                    if(y1>1 && x2<m){
                        ans+=dp[d][x1][x2+1];
                        ans%=MOD;
                    }
                    if(y1>1 && y2<n){
                        ans+=dp[d][x1][x2];
                        ans%=MOD;
                    }
                }
            }
            d^=1;
        }
        LL res=0;
        if((n+m)&1){
            for(i=1;i<=m;i++){
                res+=dp[d][i][i];
                res+=dp[d][i][i+1];
                res%=MOD;
            }
        }else {
            for(i=1;i<=m;i++){
                res+=dp[d][i][i];
                res%=MOD;
            }
        }
        if(res<0) res+=MOD;
        printf("%I64d\n",res%MOD);
    }
    return 0;
}
