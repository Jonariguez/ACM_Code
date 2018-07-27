/****************
*PID:bzoj2005
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
int mu[maxn],vis[maxn],prime[maxn],sum[maxn];

void Mobius(){
    int i,j,tot=0;
    mu[1]=1;    //不要忘记这个。。。
    for(i=2;i<=100000;i++){
        if(!vis[i]){
            prime[tot++]=i;mu[i]=-1;
        }
        for(j=0;j<tot;j++){
            if(i*prime[j]>100000) break;
            vis[i*prime[j]]=1;
            if(i%prime[j]==0){
                mu[i*prime[j]]=0;break;
            }else
                mu[i*prime[j]]=-mu[i];
        }
    }
}

LL solve(int n,int m){
    if(n>m)
        swap(n,m);
    LL res=0;
    int last=0;
    for(int i=1;i<=n;i++){
        last=min(n/(n/i),m/(m/i));
        res+=(LL)(sum[last]-sum[i-1])*(n/i)*(m/i);
        i=last;
    }
    return res;
}

int main()
{
    int i,n,m,k;
    Mobius();
    sum[0]=0;
    for(i=1;i<=100000;i++)
        sum[i]=sum[i-1]+mu[i];
    scanf("%d%d",&n,&m);
    LL ans=0;
    int temp=min(n,m);
    for(k=1;k<=temp;k++)    //枚举gcd=k
        ans+=solve(n/k,m/k)*k*2;
    ans-=(LL)n*m;
    printf("%lld\n",ans);
    return 0;
}




