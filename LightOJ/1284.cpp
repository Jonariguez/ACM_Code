/****************
*PID:lightoj1284
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

const int maxn=100000+10;

double cal(int i,int x){
    return 1.0-1.0*((i-1)*(i-1)+(x-i)*(x-i))/(x*x);
}

int main()
{
    int i,j,x,y,z,k,n,T,kcase=1;
    sc(T);
    while(T--){
        scanf("%d%d%d%d",&x,&y,&z,&n);
        double ans=0;
        for(i=1;i<=x;i++){
            for(j=1;j<=y;j++){
                for(k=1;k<=z;k++){
                    double p=cal(i,x)*cal(j,y)*cal(k,z);
                    ans+=(1.0-pow(1-p*2,1.0*n))/2;
                }
            }
        }
        printf("Case %d: %.7f\n",kcase++,ans);
    }
    return 0;
}



