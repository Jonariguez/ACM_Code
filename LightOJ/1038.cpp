/****************
*PID:lightoj1038
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

const int maxn=100000+10;
double dp[maxn];
int vis[maxn];

double DP(int n){
    if(n==1) return 0.0;
    if(vis[n]) return dp[n];
    vis[n]=1;
    double &ans=dp[n];
    ans=0.0;
    int cnt=0;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            ans+=DP(i);
            cnt++;
            if(n/i!=i){
                ans+=DP(n/i);cnt++;
            }
        }
    }
    cnt+=2; //µ¥¶À¼ÆËã1ºÍn
    ans=(ans+cnt)/(cnt-1);
    return ans;
}


int main()
{
    int i,j,n,T,kcase=1;
    scanf("%d",&T);
    memset(vis,0,sizeof(vis));
    while(T--){
        scanf("%d",&n);
        printf("Case %d: %.8f\n",kcase++,DP(n));
    }
    return 0;
}



