/****************
*PID:lightoj1030
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
typedef int Ll;
Ll quick_pow(Ll a,Ll b,Ll MOD){a%=MOD;Ll res=1;while(b){if(b&1)res=(res*a)%MOD;b/=2;a=(a*a)%MOD;}return res;}

const int maxn=100+10;
int gold[maxn];
double E[maxn];

int main()
{
    int i,j,n,T,kcase=1;
    sc(T);
    while(T--){
        sc(n);
        for(i=1;i<=n;i++)
            sc(gold[i]);
        E[n]=(double)gold[n];
        for(i=n-1;i>=1;i--){
            double sum=0.0;
            for(j=i+1;j<=min(n,i+6);j++)
                sum+=E[j];
            E[i]=sum/(j-i-1)+gold[i];   //注意这里是除以(j-i+1)，而不一直是6，因为If your new position is
            //outside the cave, then you keep throwing again until you get a suitable result.
        }
        printf("Case %d: %.8f\n",kcase++,E[1]);
    }
    return 0;
}



