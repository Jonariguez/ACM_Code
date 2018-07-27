/****************
*PID:518d div2
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

double dp[2001][2001];

int main()
{
    LL i,j,n,t;
    double p;
    while(scanf("%I64d%lf%I64d",&n,&p,&t)!=EOF){
        if(n>=t){
            printf("%.7f\n",p*t);continue;
        }
        dp[0][0]=1.0;
        for(i=0;i<t;i++){
            for(j=0;j<=n;j++){
                if(j==n) dp[i+1][j]+=dp[i][j];
                else {
                    dp[i+1][j+1]+=dp[i][j]*p;
                    dp[i+1][j]+=dp[i][j]*(1-p);
                }
            }
        }
        double res=0.0;
        for(i=1;i<=n;i++)
            res+=dp[t][i]*i;
        printf("%.7f\n",res);
    }
    return 0;
}
