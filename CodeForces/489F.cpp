/****************
*PID:489f div2
*Auth:Jonariguez
*****************
dp[k][i][j]:第k行，有i列可以再放1个1，有j列可以再放2个1的方案数
答案为dp[n][0][0]，k取0,1翻转使用节省空间。
注意在转移的时候，two-1或者two-2时对应转移到的状态one也应该相应的
+1或+2，应该从两个掉到一个嘛
要对内层的two的循环进行优化.
还有就是:
a+=b;
if(a>=mod) a-=mod;
的最后结果不一定对，因为要保证b也应该是[0,mod)才对，像这样：
a+=(b%mod);
if(a>=mod) a-=mod;
较快的写法为：
a+=b;
if(a>=mod) a%=mod;
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn=500+5;

LL dp[2][maxn][maxn];
int col[maxn];
char str[maxn];

int main()
{
    int n,m,mod,i,j;
    while(scanf("%d%d%d",&n,&m,&mod)!=EOF){
        memset(col,0,sizeof(col));
        for(i=1;i<=m;i++){
            scanf("%s",str+1);
            for(j=1;j<=n;j++)
                col[j]+=(str[j]-'0');
        }
        int one=0,two=0;
        for(i=1;i<=n;i++){
            if(col[i]==1) one++;
            else if(col[i]==0) two++;
        }
      //  printf("one=%d two=%d\n",one,two);
        memset(dp,0,sizeof(dp));
        dp[0][one][two]=1LL;
        int d=0,k;
        for(k=m+1;k<=n;k++){
            for(one=0;one<=n;one++){
                for(two=0;two<=n-k+1;two++){
                /*    if(one>=2){
                        dp[d^1][one-2][two]+=dp[d][one][two]*(one-1)*one/2;
                        dp[d^1][one-2][two]%=mod;
                    }
                    if(two>=2){
                        dp[d^1][one][two-2]+=dp[d][one][two]*(two-1)*two/2;
                        dp[d^1][one][two-2]%=mod;
                    }
                    if(one>=1 && two>=1){
                        dp[d^1][one-1][two-1]+=dp[d][one][two]*one*two;
                        dp[d^1][one-1][two-1]%=mod;
                    }*/

                    if(one>=2){         //选择两列可以放1个1的
                        dp[d^1][one-2][two]+=(dp[d][one][two]*(one-1)*one/2);
                        if(dp[d^1][one-2][two]>=mod)
                            dp[d^1][one-2][two]%=mod;
                    }
                    if(two>=2){         //选择两列可以放2个1的
                        dp[d^1][one+2][two-2]+=(dp[d][one][two]*(two-1)*two/2);
                        if(dp[d^1][one+2][two-2]>=mod)
                            dp[d^1][one+2][two-2]%=mod;
                    }
                    if(one>=1 && two>=1){   //分别选一个
                        dp[d^1][one][two-1]+=(dp[d][one][two]*one*two);
                        if(dp[d^1][one][two-1]>=mod)
                            dp[d^1][one][two-1]%=mod;//if(one==2 && two==1) printf("???\n");
                      //  printf("dp[%d][one-1][two-1]=%I64d one-1=%d two-1=%d\n",k,dp[k][one-1][two-1],one-1,two-1);
                    }
                }
            }
            d^=1;
        }
        dp[d][0][0]%=mod;
        if(dp[d][0][0]<0) dp[d][0][0]+=mod;
        printf("%I64d\n",dp[d][0][0]%mod);
    }
    return 0;
}
