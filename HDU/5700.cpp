/****************
*PID:hdu5700
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

LL a[maxn],sum[maxn];
vector<int> I[maxn];
multiset<int> S;

int main()
{
    int i,j,n,k,m,T;
    while(scanf("%d%d%d",&n,&k,&m)!=EOF){
        sum[0]=0;
        for(i=1;i<=n;i++){
            scanf("%I64d",&a[i]);
            sum[i]=sum[i-1]+a[i];
            I[i].clear();
        }
        for(i=1;i<=m;i++){
            int l,r;
            sc(l);sc(r);
            I[l].push_back(r);
        }
        S.clear();
        LL res=0;
        for(i=1;i<=n;i++){
            for(j=0;j<I[i].size();j++)
                S.insert(I[i][j]);
            while(S.size()>k)
                S.erase(S.begin());
            if(S.size()==k && *S.begin()>=i)
                res=max(res,sum[*S.begin()]-sum[i-1]);
        }
        printf("%I64d\n",res);
    }
    return 0;
}

