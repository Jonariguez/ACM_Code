/****************
*PID:51nod1079
*Auth:Jonariguez
*****************
*/
#define lson k*2,l,m
#define rson k*2+1,m+1,r
#define rep(i,n) for(i=1;i<=(n);i++)
#define rep0(i,n) for(i=0;j<=(n);i++)
#define re(i,n) for(i=1;i<(n);i++)
#define re0(i,n) for(i=0;i<(n);i++)
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
#define PB push_back
#define X first
#define Y second
#define PI acos(-1.0)
#include <stdio.h>
#include <string.h>
#include <string>
#include <sstream>
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
Ll Pow(Ll a,Ll b,Ll MOD){a%=MOD;Ll res=1;while(b){if(b&1)res=(res*a)%MOD;b/=2;a=(a*a)%MOD;}return res;}

const int maxn=200000+10;
const int MOD=1e9+7;

LL a[20],m[20];

void Exgcd(LL a,LL b,LL d,LL &x,LL &y){
    if(b==0){
        d=a;x=1;y=0;return ;
    }
    Exgcd(b,a%b,d,y,x);
    y-=(a/b)*x;
}

LL inv(LL n,LL m){
    LL d,x,y;
    Exgcd(n,m,d,x,y);
    return (x%m+m)%m;
}

int main()
{
    int i,j,n;
    sc(n);
    LL M=1;
    for(i=1;i<=n;i++){
        scanf("%I64d%I64d",&m[i],&a[i]);
        M*=m[i];
    }
    LL res=0;
    for(i=1;i<=n;i++){
        LL Mi=M/m[i];
        LL t=inv(Mi,m[i]);
        res+=a[i]*t*Mi%M;
        res%=M;
    }
    if(res<0) res+=M;
    printf("%I64d\n",res);
    return 0;
}


