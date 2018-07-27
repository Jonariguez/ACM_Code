/****************
*PID:5646
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
const LL mod=1e9+7;
Ll quick_pow(Ll a,Ll b,Ll MOD){a%=MOD;Ll res=1;while(b){if(b&1)res=(res*a)%MOD;b/=2;a=(a*a)%MOD;}return res;}

const int maxn=100000+10;
vector<LL> res;

int main()
{
    LL i,j,m,T;
    LL n,k;
    scanf("%I64d",&T);
    while(T--){
        scanf("%I64d%I64d",&n,&k);
        if(n<k*(k+1)/2){
            puts("-1");continue;
        }
        res.clear();
        LL t=(k+1)*k/2;
        LL temp=n-t;
        LL start=temp/k+1,r=temp%k;
        LL ans=1;
        for(i=start;i<=start+k-1;i++){
            if(i+r-1>=start+k-1)
                ans=ans*(i+1);
            else ans=ans*i;
            ans%=mod;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
