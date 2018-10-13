/****************
*PID:bzoj1008
*Auth:Jonariguez
*****************
M^N-M*(M-1)^(N-1)
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
const int MOD=100003;

LL Pow(LL n,LL m){
    LL res=1;
    while(m){
        if(m&1)
            res=(res*n)%MOD;
        m/=2;
        n=(n*n)%MOD;
    }
    return res;
}

int main()
{
    int i,j;
    LL m,n;
    scanf("%lld%lld",&m,&n);
    if(m==1){
        if(n==1)
            printf("0\n");
        else printf("1\n");
        return 0;
    }
    LL res=Pow(m,n)-m*Pow(m-1,n-1);
    res%=MOD;
    if(res<0)
        res+=MOD;
    printf("%lld\n",res);
    return 0;
}

