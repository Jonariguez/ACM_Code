/****************
*PID:poj3616
*Auth:Jonariguez
*****************
dp[i]:到第i小时的最大值。
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

const int maxn=1000000+10;
int dp[1005];
struct interval{
    int start,en,eff;
}s[1005];

int cmp(const interval &x,const interval &y){
    if(x.start==y.start)
        return x.en<y.en;
    return x.start<y.start;
}

int main()
{
    int i,j,n,m,R;
    scanf("%d%d%d",&n,&m,&R);
    for(i=1;i<=m;i++){
        scanf("%d%d%d",&s[i].start,&s[i].en,&s[i].eff);
    }
    sort(s+1,s+m+1,cmp);
    for(i=1;i<=m;i++) dp[i]=s[i].eff;
    for(i=1;i<=m;i++){
        int x=s[i].start,y=s[i].en,z=s[i].eff;
        for(j=1;j<i;j++){
            if(s[i].start-R>=s[j].en)
                dp[i]=max(dp[i],dp[j]+z);
        }
    }
    int res=0;
    for(i=1;i<=m;i++)
        res=max(res,dp[i]);
    printf("%d\n",res);
    return 0;
}



