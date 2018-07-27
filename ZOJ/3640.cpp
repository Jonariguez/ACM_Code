/****************
*PID:zoj3640
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
int n,t[maxn],c[maxn];
double dp[20005];

double dfs(int f){
    if(dp[f]>=0) return dp[f];
    int i;
    double &res=dp[f];
    res=0;
    for(i=1;i<=n;i++){
        if(f-c[i]>0)
            res+=(double)t[i]/n;
        else res+=(dfs(f+c[i])+1)/n;
    }
    return res;
}

int main()
{
    int i,j,f;
    while(scanf("%d%d",&n,&f)!=EOF){
        double v=(1+sqrt(5.0))/2;
        for(i=1;i<=n;i++){
            scanf("%d",&c[i]);
            t[i]=(int)(c[i]*c[i]*v);
        }
        memset(dp,-1,sizeof(dp));
        printf("%.3f\n",dfs(f));
    }
    return 0;
}



