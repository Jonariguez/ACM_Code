/****************
*PID:300c div2
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
typedef long long Ll;
Ll quick_pow(Ll a,Ll b,Ll MOD){a%=MOD;Ll res=1;while(b){if(b&1)res=(res*a)%MOD;b/=2;a=(a*a)%MOD;}return res;}

const int maxn=1000000+10;
const LL mod=1e9+7;
LL inv[maxn],fact[maxn];
int a,b;

bool ok(int n){
    while(n){
        int t=n%10;
        if(t!=a && t!=b) return false;
        n/=10;
    }
    return true;
}

LL C(int n,int m){
    LL res=fact[n];
    res=(res*inv[m])%mod;
    res=(res*inv[n-m])%mod;
    return res;
}

int main()
{
    int i,j,n;
    fact[0]=1;
    inv[0]=quick_pow(1LL,mod-2,mod);
    for(i=1;i<=1000000;i++){
        fact[i]=fact[i-1]*i%mod;
        inv[i]=quick_pow(fact[i],mod-2,mod);
    }
    while(scanf("%d%d%d",&a,&b,&n)!=EOF){
        LL res=0;
        for(i=0;i<=n;i++){
            if(!ok(i*a+b*(n-i))) continue;
            res=(res+C(n,i))%mod;
        }
        printf("%I64d\n",res);
    }
    return 0;
}



