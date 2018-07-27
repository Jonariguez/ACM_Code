/****************
*PID:poj1717
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=1000+10;
map<int,int> dp[2];

int main()
{
    int i,j,n;
    scanf("%d",&n);
    int a,b,d=0,sum=0;
    for(i=-12000;i<=12000;i++)
        dp[0][i]=dp[1][i]=10000;
    dp[0][0]=0;
    for(i=1;i<=n;i++){
        scanf("%d%d",&a,&b);
        sum+=a+b;
        for(j=sum;j>=0;j--){
            if(dp[d][j]!=10000){
                dp[d^1][j+a-b]=min(dp[d^1][j+a-b],dp[d][j]);
                dp[d^1][j+b-a]=min(dp[d^1][j+b-a],dp[d][j]+1);
                dp[d][j]=10000;
            }
        }
        d^=1;
    }
    for(i=0;i<=12000;i++)
        if(dp[d][i]<10000) break;
    for(j=0;j>=-12000;j--)
        if(dp[d][j]<10000) break;
    if((-j)<i) printf("%d\n",dp[d][j]);
    else printf("%d\n",dp[d][i]);
    return 0;
}

