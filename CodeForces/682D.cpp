/****************
*PID:682d div2
*Auth:Jonariguez
*****************
dp1[i][j][k]:.......一定用上s[i]和t[j]的最长长度。所以在s[i]==t[j]时转移
dp2[i][j][k]:.......时的前缀最大值。类似LCS一样转移的同时
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

const int maxn=1000+10;
const int MOD=1e9+7;
char s[maxn],t[maxn];
int dp1[maxn][maxn][12],dp2[maxn][maxn][12];

int main()
{
    int i,j,p,q,n,m,k;
    while(scanf("%d%d%d",&n,&m,&k)!=EOF){
        scanf("%s",s+1);
        scanf("%s",t+1);
        memset(dp1,0,sizeof(dp1));
        memset(dp2,0,sizeof(dp2));
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                if(s[i]==t[j]){
                    for(p=1;p<=k;p++)
                        dp1[i][j][p]=max(dp2[i-1][j-1][p-1]+1,dp1[i-1][j-1][p]+1);
                }
                for(p=1;p<=k;p++)
                    dp2[i][j][p]=max(max(dp2[i-1][j-1][p],dp1[i][j][p]),max(dp2[i-1][j][p],dp2[i][j-1][p]));
            /*    for(p=1;p<=k;p++){
                    int t=dp[i][j];
                    if(t==0) d[i][j][p]=max(d[i-1][j][p],d[i][j-1][p]);
                    else {
                        for(q=1;q<=t;q++)
                            d[i][j][p]=max(d[i][j][p],d[i-q][j-q][p-1]+q);
                    }
                } */
            }
        }
        int res=0;
        for(i=1;i<=k;i++)
            res=max(res,dp2[n][m][i]);
        printf("%d\n",res);
    }
    return 0;
}




