/****************
*PID:uva11825
*Auth:Jonariguez
*****************
dp[s]:s表示的集合最多能分成多少组。
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

const int maxn=16;
int p[maxn],cover[(1<<maxn)],dp[(1<<maxn)];

int main()
{
    int i,j,n,kcase=1;
    while(scanf("%d",&n),n){
        for(i=0;i<n;i++){
            int k,x;
            scanf("%d",&k);
            p[i]=(1<<i);
            while(k--){
                sc(x);
                p[i]|=(1<<x);
            }
        }
        int mask=0;
        for(mask=0;mask<(1<<n);mask++){
            cover[mask]=0;
            for(i=0;i<n;i++)
                if((mask>>i)&1)
                    cover[mask]|=p[i];
        }
        int ALL=(1<<n)-1;
        dp[0]=0;
        for(mask=1;mask<(1<<n);mask++){
            dp[mask]=0;
            for(int s=mask;s;s=(s-1)&mask)
                if(cover[s]==ALL)
                    dp[mask]=max(dp[mask],dp[mask^s]+1);
        }
        printf("Case %d: %d\n",kcase++,dp[ALL]);
    }
    return 0;
}


