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

const int maxn=100+10;
const int MOD=1e9+7;
const int INF=1e9;

int a[maxn],dp[maxn][3];

int main()
{
    int i,j,n,m;
    while(scanf("%d",&n)!=EOF){
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(i=0;i<=n;i++)
            dp[i][0]=dp[i][1]=dp[i][2]=INF;
        dp[0][0]=0;
        for(i=1;i<=n;i++){
            if(a[i]==1)
                dp[i][1]=min(dp[i-1][0],dp[i-1][2]);
            else if(a[i]==2)
                dp[i][2]=min(dp[i-1][0],dp[i-1][1]);
            else if(a[i]==3){
                dp[i][1]=min(dp[i-1][0],dp[i-1][2]);
                dp[i][2]=min(dp[i-1][0],dp[i-1][1]);
            }
            dp[i][0]=min(dp[i-1][0],min(dp[i-1][1],dp[i-1][2]))+1;
        }
        printf("%d\n",min(dp[n][0],min(dp[n][1],dp[n][2])));
    }
    return 0;
}




