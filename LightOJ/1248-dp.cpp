/****************
*PID:lightoj
*Auth:Jonariguez
*****************
E[i]:抛出不同的i面的期望次数
E[i+1]=(n-i)/n*E[i]+i/n*E[i+1]+1;
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
double E[maxn];

int main()
{
    int i,j,n,T,kcase=1;
    sc(T);
    while(T--){
        sc(n);
        E[1]=1;
        for(i=1;i<n;i++)
            E[i+1]=E[i]+1.0*n/(n-i);
        printf("Case %d: %.8f\n",kcase++,E[n]);
    }
    return 0;
}



