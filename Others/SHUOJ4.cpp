/****************
*PID:
*Auth:Jonariguez
*****************
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
LL n,m,k;

bool C(LL v){
    LL i,j;
    LL res=0;
    for(i=1;i<=n;i++){
        LL cnt=i*2+3,sum=3*i+3;
        if(cnt+sum>v) break;
        LL temp=v-sum;
        res+=min(m,temp/cnt);
    }
    return res>=k;
}


int main()
{
    int i,j;
  /*  for(i=1;i<=5;i++){
        for(j=1;j<=5;j++)
            printf("%d ",2*i*j+3*i+3*j+3);
        puts("");
    }*/
    scanf("%lld%lld%lld",&n,&m,&k);
    LL l=11,r=n*m*2+n*3+m*3+3,res=0;
    while(l<=r){
        LL mid=(l+r)/2;
     //   printf("mid=%lld\n",mid);
        if(C(mid)){
            res=mid;
            r=mid-1;
        }else l=mid+1;
    }
    printf("%lld\n",res);
    return 0;
}

