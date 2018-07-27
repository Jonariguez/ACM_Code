/****************
*PID:
*Auth:Jonariguez
*****************
莫比乌斯反演
g[x]:满足gcd(a1,a2...ak)=x的所有组合的数的个数
f[x]:所有gcd为x的倍数的所有组合的数的个数
则f[x]=∑g(d),且x|d(d%x==0)
则f[x]=∑k，满足x|a1,x|a2,..,x|ak
f[x]可以用组合求出来
然后由f[x]求g[x]用反演即可。
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
const int maxm=1000005;
const int MOD=1e9+7;

int a[maxn],vis[maxm];
int prime[maxn],mu[maxm];
int f[maxm],g[maxm];

void Mobius(){
    int tot=0,i,j;
    mu[1]=1;
    for(i=2;i<=1000001;i++){
        if(!vis[i]){
            prime[tot++]=i;mu[i]=-1;
        }
        for(j=0;j<tot;j++){
            if(i*prime[j]>1000001) break;
            vis[i*prime[j]]=1;
            if(i%prime[j]==0){
                mu[i*prime[j]]=0;break;
            }else mu[i*prime[j]]=-mu[i];
        }
    }
}

LL Pow(LL a,LL b){
    LL res=1;
    while(b){
        if(b&1) res=res*a%MOD;
        b/=2;
        a=a*a%MOD;
    }
    return res;
}

LL sum[maxm];

int main()
{
    int i,j,n;
    Mobius();
    scanf("%d",&n);
    memset(vis,0,sizeof(vis));
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        vis[a[i]]++;
    }
    LL cur=0;
    for(i=2;i<=1000000;i++){
        cur=0;
        for(j=i;j<=1000000;j+=i)
            cur+=vis[j];
        if(cur)
            f[i]=cur*Pow(2LL,cur-1)%MOD;
    }
    for(i=2;i<=1000000;i++){
        for(j=i;j<=1000000;j+=i)
            sum[i]=(sum[i]+mu[j/i]*f[j])%MOD;
    }
    LL res=0;
    for(i=2;i<=1000000;i++){
        res+=sum[i]*i%MOD;
        res%=MOD;
    }
    printf("%I64d\n",res);
    return 0;
}



