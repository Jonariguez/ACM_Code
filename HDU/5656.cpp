/****************
*PID:hdu5656
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

const int maxn=1000+10;
const int MOD=1e8+7;
int a[maxn],dp[maxn][maxn],G[maxn][maxn];

int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}

int main()
{
    int i,j,n,T;
    for(i=0;i<=1000;i++){
        for(j=i;j<=1000;j++){
            G[i][j]=gcd(i,j);
        }
    }
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        int mx=0;
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
            mx=max(mx,a[i]);
        }
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(i=0;i<n;i++){
            for(j=0;j<=mx;j++){
                dp[i+1][j]+=dp[i][j];
                if(dp[i+1][j]>=MOD)
                    dp[i+1][j]-=MOD;
                int temp=G[min(j,a[i])][max(j,a[i])];
                dp[i+1][temp]+=dp[i][j];
                dp[i+1][temp]%=MOD;
            }
        }
        LL res=0;
        for(i=1;i<=mx;i++){
            res+=(LL)dp[n][i]*i%MOD;
            if(res>=MOD) res-=MOD;
        }
        printf("%I64d\n",res);
    }
    return 0;
}


