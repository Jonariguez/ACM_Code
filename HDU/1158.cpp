/****************
*PID:hdu1158
*Auth:Jonariguez
*****************
dp[i][j]:到第i个
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

const int maxn=100000+10;
const int INF=1e9;
int dp[13][maxn];
int f,h,c,a[14];

int main()
{
    int i,j,k,n;
    while(scanf("%d",&n)!=EOF){
        if(n==0) break;
        int mx=0;
        scanf("%d%d%d",&h,&c,&f);
        for(i=1;i<=n;i++){
            sc(a[i]);
            mx=max(mx,a[i]);
        }
        for(i=0;i<=n;i++)
            for(j=0;j<=mx;j++)
                dp[i][j]=INF;
        a[0]=0;
        dp[0][0]=0;
        for(i=0;i<n;i++){
            for(j=0;j<=mx;j++){
                if(dp[i][j]<INF){
                    if(j<a[i]) continue;    //上个月至少得有a[i]个人，即上个月的人得够上个月的需求a[i]才行。
                    for(k=j;k<=mx;k++)
                        dp[i+1][k]=min(dp[i+1][k],dp[i][j]+(k-j)*h+k*c);    //这个月雇人
                    for(k=j;k>=0;k--)
                        dp[i+1][k]=min(dp[i+1][k],dp[i][j]+(j-k)*f+k*c);    //这个月解雇人
                }
            }
        }
        int res=INF;
        for(i=a[n];i<=mx;i++)
            res=min(res,dp[n][i]);
        printf("%d\n",res);
    }
    return 0;
}


