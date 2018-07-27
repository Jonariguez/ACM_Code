/****************
*PID:442b div1
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
double p[maxn];

int cmp(double a,double b){
    return a>b;
}

int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF){
        for(i=1;i<=n;i++){
            scanf("%lf",&p[i]);
        }
        double res=0;
        sort(p+1,p+n+1,cmp);
        for(i=1;i<=n;i++){
            double temp=0,now=0;
            for(j=1;j<=i;j++){
                temp=p[j];
                for(int k=1;k<=i;k++){
                    if(k==j) continue;
                    temp*=(1-p[k]);
                }
                now+=temp;
            }
            res=max(res,now);
        }
        printf("%.11f\n",res);
    }
    return 0;
}



