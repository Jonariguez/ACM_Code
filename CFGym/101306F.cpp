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

const int maxn=200000+10;
const int MOD=1e9+7;

int main()
{
    LL n,m,x,k;
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%I64d%I64d%I64d",&n,&m,&x);
        k=min(n,m);
        if(n%2==0){
            LL res=n/2;
            if(res>=0 && res<=k);
            else res=k;
            printf("%I64d %I64d\n",res,(res*n-res*res)*x);
        }else {
            LL res=n/2;
            LL ans1=res*n-res*res;
            res++;
            LL ans2=res*n-res*res;
            if(ans1>=ans2) res--;
            if(res>k) res=k;
            printf("%I64d %I64d\n",res,(res*n-res*res)*x);
        }
    }
    return 0;
}

