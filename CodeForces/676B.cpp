/****************
*PID:676b div2
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
#define eps 1e-9
typedef int Ll;
Ll quick_pow(Ll a,Ll b,Ll MOD){a%=MOD;Ll res=1;while(b){if(b&1)res=(res*a)%MOD;b/=2;a=(a*a)%MOD;}return res;}

const int maxn=100000+10;
double c[30][30];

LL gcd(LL a,LL b){
    return b==0?a:gcd(b,a%b);
}

struct pp{
    LL a,b;
    void gao(){
        LL g=gcd(a,b);
        a/=g;b/=g;
    }
}s[30][30];

struct node{
    int x,y;
    double v;
};

int main()
{
    int i,j,n,m;
    double t;
    while(scanf("%d%lf",&n,&t)!=EOF){
        memset(c,0,sizeof(c));
        c[1][1]=t;
        int res=0;
        for(i=1;i<=n;i++){
            for(j=1;j<=i;j++){
                if(c[i][j]>=1){
                    res++;
                    c[i+1][j]+=(c[i][j]-1)/2;
                    c[i+1][j+1]+=(c[i][j]-1)/2;
                }
            }
        }
        pfn(res);
    }
    return 0;
}

