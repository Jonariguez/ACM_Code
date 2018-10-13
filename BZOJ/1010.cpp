/****************
*PID:bzoj1010
*Auth:Jonariguez
*****************
dp+斜率优化
在找i的函数f[i](本题的sum[i])时，f[i]应为递增的
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

const int maxn=50000+10;
const int MOD=1e9+7;

LL sum[maxn],dp[maxn],st[maxn];
int a[maxn];

bool better(int j,int k,LL f_i){
    return f_i*(sum[j]-sum[k])<dp[j]+sum[j]*sum[j]-dp[k]-sum[k]*sum[k];
}

bool cmp(int k,int j,int i){
    return (dp[k]+sum[k]*sum[k]-dp[j]-sum[j]*sum[j])*(sum[j]-sum[i])>=(dp[j]+sum[j]*sum[j]-dp[i]-sum[i]*sum[i])*(sum[k]-sum[j]);
}


int main()
{
    int i,j,n,L;
    scanf("%d%d",&n,&L);
    L++;
    sum[0]=0;
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        sum[i]=sum[i-1]+a[i];
    }
    for(i=1;i<=n;i++)
        sum[i]+=i;
    int head=0,tail=0;
    st[tail++]=0;
    dp[0]=0;
    for(i=1;i<=n;i++){
        while(head<tail && better(st[head],st[head+1],2*(sum[i]-L))) head++;
        int t=st[head];
        dp[i]=dp[t]+(sum[i]-L-sum[t])*(sum[i]-L-sum[t]);
        while(head<tail-1 && cmp(st[tail-2],st[tail-1],i)) tail--;
        st[tail++]=i;
    }
    printf("%lld\n",dp[n]);
    return 0;
}





