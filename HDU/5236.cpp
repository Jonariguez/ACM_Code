/****************
*PID:hdu5236
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

const int maxn=100000+10;
const int MOD=1e9+7;

double dp[maxn];

int main()
{
    int i,j,n,T,kcase=1;
    scanf("%d",&T);
    while(T--){
        int x;
        double p;
        scanf("%d%lf%d",&n,&p,&x);
        dp[0]=0;
        for(i=1;i<=n;i++)
            dp[i]=(dp[i-1]+1)/(1-p);
        dp[n+1]=0;
        double res=1000000000000000.0;
        for(i=1;i<=n;i++){
            int cnt=n%i;
            res=min(res,dp[n/i+1]*cnt+dp[n/i]*(i-cnt)+x*i);
        }
        printf("Case #%d: %.6f\n",kcase++,res);
    }
    return 0;
}
