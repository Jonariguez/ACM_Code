/****************
*PID:poj3046
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

const int maxn=100000+10;
const int mod=1000000;
int dp[2][maxn],cnt[1005],sum[maxn];

int main()
{
    int i,j,k,n,T,A,S,B;
    scanf("%d%d%d%d",&T,&A,&S,&B);
    for(i=1;i<=A;i++){
        int x;
        scanf("%d",&x);
        cnt[x]++;
    }
    dp[0][0]=1;
    int *pre=dp[0],*now=dp[1];
    int tot=0;
    for(i=1;i<=T;i++){
        tot+=cnt[i];
        sum[0]=pre[0];
        for(k=1;k<=tot;k++){
            sum[k]=(sum[k-1]+pre[k])%mod;
        }
        for(j=0;j<=tot;j++){
            int temp=max(0,j-cnt[i]);
            now[j]=temp==0?sum[j]:sum[j]-sum[temp-1];
            now[j]%=mod;
        }
        swap(pre,now);
    }
    int res=0;
    for(i=S;i<=B;i++){
        res+=pre[i];
        res%=mod;
    }
    if(res<0) res+=mod;
    printf("%d\n",res);
    return 0;
}
