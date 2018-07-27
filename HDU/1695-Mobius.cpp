/****************
*PID:hdu1695
*Auth:Jonariguez
*****************
解法：莫比乌斯反演
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
int mu[maxn],vis[maxn],prime[maxn];

void Mobius(){
    int tot=0,i,j;
    mu[1]=1;
    for(i=2;i<=100000;i++){
        if(!vis[i]){
            prime[tot++]=i;
            mu[i]=-1;
        }
        for(j=0;j<tot;j++){
            if(i*prime[j]>100000) break;
            vis[i*prime[j]]=1;
            if(i%prime[j]==0){
                mu[i*prime[j]]=0;
                break;
            }else
                mu[i*prime[j]]=-mu[i];
        }
    }
}

int main()
{
    int i,j,n,m,a,c,k,kcase=1,T;
    Mobius();
    sc(T);
    while(T--){
        scanf("%d%d%d%d%d",&a,&n,&c,&m,&k);
        printf("Case %d: ",kcase++);
        if(k==0){
            puts("0");continue;
        }
        n/=k;m/=k;
        if(n>m)
            swap(n,m);
        LL res1=0,res2=0;
        for(i=1;i<=n;i++){
            res1+=(LL)mu[i]*(n/i)*(m/i);
            res2+=(LL)mu[i]*(n/i)*(n/i);
        }
        printf("%I64d\n",res1-res2/2);
    }
    return 0;
}



