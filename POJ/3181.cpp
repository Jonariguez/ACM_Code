/****************
*PID:poj3181
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
typedef unsigned long long LL;
typedef int Ll;
Ll quick_pow(Ll a,Ll b,Ll MOD){a%=MOD;Ll res=1;while(b){if(b&1)res=(res*a)%MOD;b/=2;a=(a*a)%MOD;}return res;}

const int maxn=1000+10;
LL a[maxn],b[maxn],c[maxn];

int main()
{
    LL i,j,n,k;
    scanf("%I64d%I64d",&n,&k);
    memset(c,0,sizeof(c));
    a[0]=1;
    for(i=1;i<=k;i++){
        for(j=0;j<=n;j++){
            for(int v=0;v*i+j<=n;v++){
                c[v*i+j]+=a[j];
            }
        }
        for(j=0;j<=n;j++) a[j]=c[j];
        memset(c,0,sizeof(c));
    }
    printf("%I64d\n",a[n]);
    return 0;
}


