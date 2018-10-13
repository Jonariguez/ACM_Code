/****************
*PID:uva10294
*Auth:Jonariguez
*****************
项链：只有旋转
//下面说法不对
对于恒等置换，有t^n种着色
而对于其他旋转，当n是奇数时，t*(n-1);当n是偶数时，t^2*(n/2-1)+t*(n/2)
//应该为:
sigma{i=0:n-1,t^gcd(i,n)}
然后除以n即为答案。
手镯：同时考虑旋转和翻转  旋转和项链一样，看翻转
当n是奇数时，t^((n+1)/2) *n
当n是偶数时，t^(n/2+1) * (n/2)   +   t^(n/2) * (n/2)

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
const int MOD=1e9+7;

LL fact[100];

int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}

int main()
{
    int i,j,n,t;
    while(scanf("%d%d",&n,&t)==2 && n){
        LL res=0;
        fact[0]=1;
        for(i=1;i<=n;i++) fact[i]=fact[i-1]*t;
        for(i=1;i<=n;i++)
            res+=fact[gcd(i,n)];
        printf("%lld ",res/n);
        if(n&1)
            res+=n*fact[(n+1)/2];
        else
            res+=n/2*fact[n/2]+n/2*fact[n/2+1];
        printf("%lld\n",res/n/2);
    }
    return 0;
}
