/****************
*PID:613d div2
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=200000+10;
const int maxm=200000+10;
const LL MOD=1e9+7;
const LL mod=1e9+6;

vector<LL> prime[maxn]; //prime[i]：i中包含的素因子
bool vis[maxn];

void prime_table(){
    LL i,j;
    vis[0]=vis[1]=1;
    for(i=2;i<=200000;i++){
        if(!vis[i]){
           // prime[i].push_back(i);
            for(j=i*2;j<=200000;j+=i){
           //     prime[j].push_back(i);
                vis[j]=1;
            }
        }
    }
}

LL quick_pow(LL a,LL b,LL m){
    a=(a%m+m)%m;
  //  b=(b%m+m)%m;
    LL res=1;
    while(b){
        if(b&1)
            res=res*a%m;
        b/=2;
        a=a*a%m;
    }
    return res;
}

LL cal(LL x){
    LL a=x,b=x-1;
    if(a&1) b/=2;
    else a/=2;
    return (a%mod)*(b%mod)%mod;
}

LL cnt[maxn];
LL L[maxn],R[maxn];

int main()
{
    LL i,j,n,m;
    prime_table();
    while(scanf("%I64d",&m)!=EOF){
        memset(cnt,0,sizeof(cnt));
        n=0;
        LL x;
        for(i=1;i<=m;i++){
            scanf("%I64d",&x);
            cnt[x]++;
            n=max(n,x);
        }
        for(i=1;i<=n;i++)
            cnt[i]++;
        L[1]=1;R[n+1]=1;
        for(i=2;i<=n;i++) L[i]=L[i-1]*cnt[i]%mod;
        for(i=n;i>=1;i--) R[i]=R[i+1]*cnt[i]%mod;
        LL res=1;
        for(i=1;i<=n;i++){
            if(vis[i]) continue;
            res=(res*quick_pow((LL)i,cal(cnt[i])*(L[i-1]*R[i+1]%mod)%mod,MOD))%MOD;
        }
        printf("%I64d\n",res);
    }
    return 0;
}
