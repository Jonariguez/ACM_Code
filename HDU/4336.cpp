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

const int maxn=20;
double p[maxn],dp[(1<<maxn)],no;
int n,vis[(1<<maxn)];

double dfs(int s){
    if(vis[s]) return dp[s];
    if(s==(1<<n)-1) return 0;
    vis[s]=1;
    double &res=dp[s],temp=1-no;
    res=0;
    for(int i=0;i<n;i++){
        if((s>>i)&1)
            temp-=p[i];
        else res+=p[i]*dfs(s|(1<<i));
    }
    res++;
    res/=temp;
    return res;
}

int main()
{
    int i,j;
    while(scanf("%d",&n)!=EOF){
        no=1;
        for(i=0;i<n;i++){
            scanf("%lf",&p[i]);
            no-=p[i];
        }
        memset(vis,0,sizeof(vis));
        printf("%.7f\n",dfs(0));
    }
    return 0;
}


