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

const int maxn=100000+10;
const int maxm=1000+10;
const int MOD=1e9+7;

const LL INF=(LL)1e17;

int a[maxn],b[maxn];
LL dp[12][maxm];
int K[maxm],p[maxm];

int main()
{
    int i,j,k,n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        int N=-1;
        for(i=1;i<=n;i++){
            scanf("%d%d",&a[i],&b[i]);
            N=max(N,b[i]);
        }
        int y=0;
        for(i=1;i<=m;i++){
            scanf("%d%d",&K[i],&p[i]);
            if(p[i]>N)
                y=1;
        }
        if(y==0){
            puts("-1");continue;
        }
        for(k=0;k<=10;k++){
            for(i=0;i<=1000;i++)
                dp[k][i]=INF;
            dp[k][0]=0;
            for(i=0;i<=1000;i++){
                for(j=1;j<=m;j++){
                    if(p[j]>k)
                        dp[k][i]=min(dp[k][i],dp[k][max(0,i-(p[j]-k))]+K[j]);
                }
            }
        }
        LL res=0;
        for(i=1;i<=n;i++){
            LL z=INF;
            for(j=a[i];j<=1000;j++)
                z=min(z,dp[b[i]][j]);
            res+=z;
        }
        printf("%I64d\n",res);
    }
    return 0;
}


