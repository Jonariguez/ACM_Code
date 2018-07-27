/****************
*PID:bzoj2440
*Auth:Jonariguez
*****************
二分+莫比乌斯
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
    int i,j,tot=0;
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

LL C(LL x){
    LL res=x;
    for(LL i=2;i*i<=x;i++)
        res+=(LL)mu[i]*(x/(i*i));
    return res;
}

int main()
{
    int i,j,T;
    Mobius();
    sc(T);
    while(T--){
        LL k;
        scanf("%lld",&k);
        LL L=0,R=2*k;   //(L,R]
        while(L<R-1){
            LL M=L+(R-L)/2;
            LL temp=C(M);
            if(temp==k)
                R=M;
            else if(temp<k)
                L=M;
            else if(temp>k)
                R=M-1;
           // printf("temp=%I64d M=%I64d L=%I64d R=%I64d\n",temp,M,L,R);
        }
        printf("%lld\n",R);
    }
    return 0;
}



