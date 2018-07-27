/****************
*PID:622f edu7
*Auth:Jonariguez
*****************
拉格朗日插值法
http://www.guokr.com/post/456777/
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
typedef long long  Ll;
const int maxn=1000000+5;
const LL MOD=1e9+7;
Ll quick_pow(Ll a,Ll b){a%=MOD;Ll res=1;while(b){if(b&1)res=(res*a)%MOD;b/=2;a=(a*a)%MOD;}return res;}

LL fact[maxn],p[maxn];

int main()
{
    int i,j,n,k;
    fact[0]=1;p[0]=0;
    for(i=1;i<=1000004;i++)
        fact[i]=(fact[i-1]*i)%MOD;
    while(scanf("%d%d",&n,&k)!=EOF){
        for(i=1;i<=k+2;i++){
            p[i]=(p[i-1]+quick_pow(i,k))%MOD;
        }
        if(n<=k+2){
            printf("%I64d\n",p[n]);continue;
        }
        LL res=0,now=1;
        for(i=1;i<=k+2;i++)
            now=(now*(n-i))%MOD;
        for(i=1;i<=k+2;i++){
            LL inv=quick_pow(n-i,MOD-2);
            LL temp=now*inv%MOD;
            LL t=fact[i-1]*fact[k+2-i]%MOD; //注意是f[i],不是f[i-1]
            LL sign=(k+2-i)%2==1?-1:1;
            inv=quick_pow(t,MOD-2);
            res+=temp*inv*sign%MOD*p[i];    //别忘了乘p[i]
            res%=MOD;
        }
        if(res<0) res+=MOD;
        printf("%I64d\n",res);
    }
    return 0;
}



