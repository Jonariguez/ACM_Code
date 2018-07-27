/****************
*PID:hdu5245
*Auth:Jonariguez
*****************
http://blog.csdn.net/nightlemon/article/details/46045817
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

const int maxn=500+10;
const int MOD=1e9+7;

int main()
{
    int i,j,n,m,T,kcase=1;
    scanf("%d",&T);
    while(T--){
        int k;
        scanf("%d%d%d",&n,&m,&k);
        double res=0.0;
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                LL cnt=0;
                cnt+=1LL*(i-1)*(j-1)*(n-i+1)*(m-j+1);
                cnt+=1LL*(i-1)*(n-i+1)*m;
                cnt+=1LL*(i-1)*(m-j)*(n-i+1)*j;
                cnt+=1LL*(j-1)*n*(m-j+1);
                cnt+=1LL*n*m;
                cnt+=1LL*(m-j)*n*j;
                cnt+=1LL*(n-i)*(j-1)*i*(m-j+1);
                cnt+=1LL*(n-i)*i*m;
                cnt+=1LL*(m-j)*(n-i)*i*j;
                double p=(double)cnt/n/n/m/m;
                res+=1-pow((1-p),k);
            }
        }
        printf("Case #%d: %d\n",kcase++,(int)(res+0.5));
    }
    return 0;
}


