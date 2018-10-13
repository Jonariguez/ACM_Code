/****************
*PID:bzoj1011
*Auth:Jonariguez
*****************
看题解说是估计题
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

const int maxn=100000+10;
const int MOD=1e9+7;

double a[maxn],sum[maxn];

int main()
{
    int i,j,n;
    double A;
    scanf("%d%lf",&n,&A);
    sum[0]=0;
    for(i=1;i<=n;i++){
        scanf("%lf",&a[i]);
        sum[i]=sum[i-1]+a[i];
    }
    for(j=1;j<=n;j++){
        i=(int)(A*j+1e-8);
        double res=0;
        if(i<=67){
            for(int k=1;k<=i;k++)
                res+=(a[k]*a[j])/(1.0*j-k);
            printf("%.6f\n",res);
        }else {
            printf("%.6f\n",sum[i]*a[j]*1.0/(j-0.5*(i+1)));
        }
    }
    return 0;
}


