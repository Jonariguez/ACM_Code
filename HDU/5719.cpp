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
const int MOD=998244353;

int b[maxn],c[maxn];

int main()
{
    int i,j,T,n;
    sc(T);
    while(T--){
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%d",&b[i]);
        for(i=1;i<=n;i++)
            sc(c[i]);
        if(b[1]!=c[1]){
            puts("0");continue;
        }
        int yes=1;
        for(i=2;i<=n;i++)
            if(b[i]>b[i-1]){
                yes=0;break;
            }
        if(yes==0){
            puts("0");continue;
        }
        yes=1;
        for(i=2;i<=n;i++)
            if(c[i]<c[i-1]){
                yes=0;break;
            }
        if(yes==0){
            puts("0");continue;
        }
        LL res=1;
        int cnt=0;
        for(i=2;i<=n;i++){
            if(b[i]>c[i]){
                res=0;break;
            }
            if(b[i]!=b[i-1] && c[i]!=c[i-1]){
                res=0;break;
            }
            if(b[i]!=b[i-1] && c[i]==c[i-1]){
                cnt+=b[i-1]-b[i]-1;continue;
            }
            if(b[i]==b[i-1] && c[i]!=c[i-1]){
                cnt+=c[i]-c[i-1]-1;continue;
            }
            res*=cnt;cnt--;
            res%=MOD;
        }
        printf("%lld\n",res);
    }
    return 0;
}

