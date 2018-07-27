/****************
*PID:
*Auth:Jonariguez
*****************
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

const int maxn=300+10;
const int MOD=1e9+7;
int g[maxn][maxn],a[maxn],v[maxn];
LL dp[maxn][maxn],sum[maxn];

int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}

LL solve(int l,int r){
    if(l>=r) return 0LL;
    if(dp[l][r]>=0) return dp[l][r];
    if(l+1==r){
        if(g[l][r]) dp[l][r]=v[l]+v[r];
        else dp[l][r]=0;
        return dp[l][r];
    }
    LL &res=dp[l][r];
    res=0;
    if(g[l][r] && sum[r-1]-sum[l]==solve(l+1,r-1))
        res=sum[r]-sum[l-1];
    for(int i=l;i<r;i++)
        res=max(res,solve(l,i)+solve(i+1,r));
    return res;
}


int main()
{
    int i,j,n,m,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        memset(g,0,sizeof(g));
        sum[0]=0;
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        for(i=1;i<=n;i++){
            scanf("%d",&v[i]);sum[i]=sum[i-1]+v[i];
        }
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(gcd(a[i],a[j])>1) g[i][j]=1;
        memset(dp,-1,sizeof(dp));
        printf("%I64d\n",solve(1,n));
    }
    return 0;
}

