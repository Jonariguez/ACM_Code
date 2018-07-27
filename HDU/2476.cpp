/****************
*PID:hdu2476
*Auth:Jonariguez
*****************
*/
#define lson k*2,l,m
#define rson k*2+1,m+1,r
#define rep(i,s,e) for(i=(s);i<=(e);i++)
#define For(j,s,e) For(j=(s);j<(e);j++)
#define sc(x) scanf("%d",&x)
#define In(x) scanf("%I64d",&x)
#define pf(x) printf("%d",x)
#define pfn(x) printf("%d\n",(x))
#define Pf(x) printf("%I64d",(x))
#define Pfn(x) printf("%I64d\n",(x))
#define Pc printf(" ")
#define PY puts("YES")
#define PN puts("NO")
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

const int maxn=100+10;
char str[maxn],str2[maxn];
int dp[maxn][maxn],ans[maxn];

int main()
{
    int i,j,k,n;
    while(scanf("%s%s",str+1,str2+1)!=EOF){
        n=strlen(str+1);
        memset(dp,0,sizeof(dp));
        for(i=1;i<=n;i++)
            dp[i][i]=1;
        for(i=n-1;i>=1;i--){
            for(j=i+1;j<=n;j++){
                dp[i][j]=dp[i+1][j]+1;
                for(k=i+1;k<=j;k++){
                    if(str2[i]==str2[k])
                        dp[i][j]=min(dp[i][j],dp[i+1][k]+dp[k+1][j]);
                }
            }
        }
        if(str[1]==str2[1])
            ans[1]=0;
        else ans[1]=1;
        for(i=2;i<=n;i++){
            ans[i]=dp[1][i];
            if(str[i]==str2[i])
                ans[i]=ans[i-1];
            else {
                for(j=1;j<i;j++)
                    ans[i]=min(ans[i],ans[j]+dp[j+1][i]);
            }
        }
        printf("%d\n",ans[n]);
    }
    return 0;
}



