/****************
*PID:
*Auth:Jonariguez
*****************
dp[n]=min{i*(i-1)/2*j+dp[j]} i*j==n
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

const int maxn=5000000+10;
const int MOD=1e9+7;

LL dp[maxn];

int main()
{
    LL i,j,r,l;
    LL t;
    scanf("%I64d%I64d%I64d",&t,&l,&r);
    dp[1]=0;dp[2]=1;dp[3]=3;
    for(i=4;i<=r;i++) dp[i]=(i*(i-1)/2);
    for(i=2;i<=r;i++){
        for(j=1;j<=i && j*i<=r;j++){    //注意，计算dp的时候，一定不要对MOD取模
            dp[j*i]=min(dp[j*i],(j*(j-1)/2)*i+dp[i]);
            dp[j*i]=min(dp[j*i],(i*(i-1)/2)*j+dp[j]);
        }
    }
    LL res=0,temp=1;
    for(i=l;i<=r;i++){
        dp[i]%=MOD;     //而计算答案时一定要对MOD取模
        res+=temp*dp[i]%MOD;
        res%=MOD;
        temp*=t;
        temp%=MOD;
    }
    if(res<0) res+=MOD;
    Pfn(res);
    return 0;
}
