/****************
*PID:hdu4135
*Auth:Jonariguez
*****************
ÈÝ³â
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

const int maxn=50000+10;
bool vis[maxn];
int prime[maxn],tot,p[maxn],m;

void table(){
    int i,j;
    tot=0;
    for(i=2;i<=50000;i++){
        if(!vis[i]){
            prime[tot++]=i;
            if((LL)i*i>50000) continue;
            for(j=i*i;j<=50000;j+=i)
                vis[j]=1;
        }
    }
}

LL solve(LL n){
    int i,j,cnt,ALL=(1<<m);
    LL lcm=1,res=0;
    for(i=1;i<ALL;i++){
        lcm=1;cnt=0;
        for(j=0;j<m;j++){
            if((i>>j)&1){
                lcm*=p[j];cnt++;
                if(lcm>n) break;
            }
        }
        if(lcm>n) continue;
        if(cnt&1)
            res+=n/lcm;
        else res-=n/lcm;
    }
    return n-res;
}

int main()
{
    int i,j,n,T,kcase=1;
    table();
    scanf("%d",&T);
    while(T--){
        LL A,B;
        scanf("%I64d%I64d%d",&A,&B,&n);
        m=0;
        for(i=0;i<tot && prime[i]*prime[i]<=n;i++){
            if(n%prime[i]==0){
                int x=prime[i];
                p[m++]=x;
                while(n%x==0) n/=x;
            }
        }
        if(n!=1)
            p[m++]=n;
        printf("Case #%d: %I64d\n",kcase++,solve(B)-solve(A-1));
    }
    return 0;
}




