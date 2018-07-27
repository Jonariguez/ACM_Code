/****************
*PID:620f edu6
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

const int maxn=50000+10;
int a[maxn],b[maxn],res[maxn],x[maxn],y[maxn],sum[1000005],f[1000005];

int main()
{
    int i,j,n,m;
    sum[0]=0;
    for(i=1;i<=1000000;i++)
        sum[i]=(sum[i-1]^i);
    while(scanf("%d%d",&n,&m)!=EOF){
        for(i=1;i<=n;i++){
            sc(a[i]);
            f[i]=sum[a[i]];
        }
        for(i=1;i<=m;i++){
            scanf("%d%d",&x[i],&y[i]);
            res[i]=-1;
        }
        for(i=1;i<=n;i++){
            b[i-1]=0;
            for(j=i;j<=n;j++){  //计算从i开始到j时的最大值。
                b[j]=max(b[j-1],f[i]^f[j]^(a[i]<a[j]?a[i]:a[j]));
            }
            for(j=1;j<=m;j++){
                if(x[j]<=i && y[j]>=i){ //尽量向最右取，因为b是递增的，所以有区间的右端点的值更新该区间的max
                    res[j]=max(res[j],b[y[j]]);
                }
            }
        }
        for(i=1;i<=m;i++)
            printf("%d\n",res[i]);
    }
    return 0;
}


