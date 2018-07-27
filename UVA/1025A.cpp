/****************
*PID:uva1025
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

const int maxn=50+10;
const int maxm=200+10;
const int MOD=1e9+7;
int t[maxn];
int rht[maxn][maxm],lft[maxn][maxm];
int dp[maxn][maxm];

int main()
{
    int i,j,n,T,kcase=1;
    while(scanf("%d",&n)!=EOF){
        if(n==0) break;
        scanf("%d",&T);
        for(i=1;i<n;i++)
            scanf("%d",&t[i]);
        memset(rht,0,sizeof(rht));
        memset(lft,0,sizeof(lft));
        int M1;
        scanf("%d",&M1);
        for(i=1;i<=M1;i++){
            int d;
            scanf("%d",&d);
            rht[1][d]=1;
            for(j=2;j<=n;j++){
                d+=t[j-1];
                rht[j][d]=1;
            }
        }
        scanf("%d",&M1);
        for(i=1;i<=M1;i++){
            int d;
            scanf("%d",&d);
            lft[n][d]=1;
            for(j=n-1;j>=1;j--){
                d+=t[j];
                lft[j][d]=1;
            }
        }
        memset(dp,MOD,sizeof(dp));
        dp[n][T]=0;
        for(j=T-1;j>=0;j--){
            for(i=n;i>=1;i--){
                dp[i][j]=dp[i][j+1]+1;
                if(i>1 && j+t[i-1]<=T && lft[i][j])
                    dp[i][j]=min(dp[i][j],dp[i-1][j+t[i-1]]);
                if(i<n && j+t[i]<=T && rht[i][j])
                    dp[i][j]=min(dp[i][j],dp[i+1][j+t[i]]);
            }
        }
        printf("Case Number %d: ",kcase++);
        if(dp[1][0]>T)
            printf("impossible\n");
        else printf("%d\n",dp[1][0]);
    }
    return 0;
}



