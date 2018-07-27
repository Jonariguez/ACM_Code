/****************
*PID:div1
*Auth:Jonariguez
*****************
dp[i][j][k]:前i个数，组成的和为j时，是否能够得到k
*/
#define lson k*2,l,m
#define rson k*2+1,m+1,r
#define rep(i,s,e) for(i=(s);i<=(e);i++)
#define For(j,s,e) For(j=(s);j<(e);j++)
#define sc(x) scanf("%d",&x)
#define In(x) scanf("%I64d",&x)
#define SS(x,y) scanf("d",&x,&y)
#define pf(x) printf("%d",x)
#define pfn(x) printf("%d\n",(x))
#define Pf(x) printf("%I64d",(x))
#define Pfn(x) printf("%I64d\n",(x))
#define Pc printf(" ")
#define PY puts("YES")
#define PN puts("NO")
#define MP make_pair
#define X first
#define Y second
#define PI acos(-1.0)
#include <stdio.h>
#include <string.h>
#include <string>
#include <math.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef int Ll;
Ll quick_pow(Ll a,Ll b,Ll MOD){a%=MOD;Ll res=1;while(b){if(b&1)res=(res*a)%MOD;b/=2;a=(a*a)%MOD;}return res;}

const int maxn=503;
const int MOD=1e9+7;
bool dp[maxn][maxn][maxn];
int c[maxn];
vector<int> res;

int main()
{
    int i,j,p,n,k;
    while(scanf("%d%d",&n,&k)!=EOF){
        memset(dp,0,sizeof(dp));
        for(i=1;i<=n;i++)
            sc(c[i]);
        dp[0][0][0]=1;
        res.clear();
        for(i=1;i<=n;i++){
            for(j=0;j<=k;j++){
                for(p=0;p<=k;p++)
                    dp[i][j][p]|=dp[i-1][j][p];
                if(j>=c[i])
                    for(p=0;p<=k;p++){
                        dp[i][j][p]|=dp[i-1][j-c[i]][p];
                        if(p>=c[i])
                            dp[i][j][p]|=dp[i-1][j-c[i]][p-c[i]];
                    }
             //   if(i==3 && j==1)
              //  for(p=0;p<=k;p++)
               //     printf("dp[%d][%d][%d]=%d\n",i,j,p,dp[i][j][p]);
            }
        }
        for(i=0;i<=k;i++)
            if(dp[n][k][i]) res.push_back(i);
        printf("%d\n",res.size());
        for(i=0;i<res.size();i++)
            printf("%d ",res[i]);
        puts("");
    }
    return 0;
}



