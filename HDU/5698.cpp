/****************
*PID:hdu5698
*Auth:Jonariguez
*****************
在行和列方向是独立的，但是要求步数相同，所以枚举步数
然后求组合数，然后累加即可。
还有公式直接是：C(n+m-4,n-2)
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
Ll quick_pow(Ll a,LL b,LL MOD){a%=MOD;Ll res=1;while(b){if(b&1)res=(res*a)%MOD;b/=2;a=(a*a)%MOD;}return res;}

const int maxn=100000+10;
const int MOD=1e9+7;
LL fact[maxn],inv[maxn];

LL C(int n,int m){
    LL res=fact[n];
    res=res*inv[m]%MOD;
    res=res*inv[n-m]%MOD;
    return res;
}

int main()
{
    int i,j,n,m,T;
    fact[0]=1;
    inv[0]=quick_pow(1LL,MOD-2,MOD);
    for(i=1;i<=100000;i++){
        fact[i]=fact[i-1]*i%MOD;
        inv[i]=quick_pow(fact[i],MOD-2,MOD);
    }
    while(scanf("%d%d",&n,&m)!=EOF){
        n--;m--;
        int k=min(n,m);
        LL res=0;
        for(i=0;i<k;i++){
            res=res+(C(n-1,i)*C(m-1,i))%MOD;
            res%=MOD;
        }
        if(res<0)
            res+=MOD;
        printf("%I64d\n",res%MOD);
    }
    return 0;
}
