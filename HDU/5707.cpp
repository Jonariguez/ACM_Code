/****************
*PID:hdu5707
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

const int maxn=2000+10;
char a[maxn],b[maxn],c[maxn];
int dp[maxn][maxn];

int main()
{
    int i,j,n,m,l;
    while(scanf("%s",a+1)!=EOF){
        scanf("%s%s",b+1,c+1);
        n=strlen(a+1);
        m=strlen(b+1);
        l=strlen(c+1);
        if(n+m!=l){
            puts("No");continue;
        }
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(i=0;i<=n;i++){
            for(j=0;j<=m;j++){
                if(i && c[i+j]==a[i])
                    dp[i][j]|=dp[i-1][j];
                if(j && c[i+j]==b[j])
                    dp[i][j]|=dp[i][j-1];
            }
        }
        if(dp[n][m])
            puts("Yes");
        else puts("No");
    }
    return 0;
}




