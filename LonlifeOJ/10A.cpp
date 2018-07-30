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

const int maxn=200000+10;
const int MOD=1e9+7;

int dp[1000005][2];

int main()
{
    int i,j,n,a,b,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&a,&b,&n);
        int suma=0,sumb=0;  //sumaºÚ sumb°×
        suma=1;
        sumb=1;
        memset(dp,0,sizeof(dp));
        dp[1][0]=dp[1][1]=1;
        for(i=2;i<=n;i++){
            if(i-a>=1)
                suma-=dp[i-a][0];
            if(suma<0)
                suma+=MOD;
            if(i-b>=1)
                sumb-=dp[i-b][1];
            if(sumb<0)
                sumb+=MOD;
            dp[i][0]+=sumb;
            dp[i][0]%=MOD;
            dp[i][1]+=suma;
            dp[i][1]%=MOD;
            suma+=dp[i][0];
            suma%=MOD;
            sumb+=dp[i][1];
            sumb%=MOD;
        }
        int res=0;
        if(b>1)
            for(i=1;i<b;i++){
                if(n-i+1<=0) break;
                res=(res+dp[n-i+1][1])%MOD;
            }
        if(a>1)
            for(i=1;i<a;i++){
                if(n-i+1<=0) break;
                res=(res+dp[n-i+1][0])%MOD;
            }
        if(res<0)
            res+=MOD;
        printf("%d\n",res);
    }
    return 0;
}
