/****************
*PID:
*Auth:Jonariguez
*****************
dp[i][j]:前i天孵化出j个不同的蛋
ans：Min{x|dp[x][k]>=p/2000}
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

const int maxn=1000+10;
const int MOD=1e9+7;

double dp[10005][maxn];

int main()
{
    int i,j,k,q,p;
    scanf("%d%d",&k,&q);
    dp[1][1]=1;
    for(i=1;i<=10000;i++){
        for(j=1;j<=i && j<=k;j++){
            if(i==1 && j==1) continue;
            dp[i][j]=dp[i-1][j-1]*(k-j+1)/k+dp[i-1][j]*j/k;
        }
    }
    while(q--){
        scanf("%d",&p);
        for(i=1;i<=10000;i++){
            if(dp[i][k]>=p/2000.0) break;
        }
        printf("%d\n",i);
    }
    return 0;
}

