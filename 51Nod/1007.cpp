/****************
*PID:
*Auth:Jonariguez
*****************
*/
#define lson k*2,l,m
#define rson k*2+1,m+1,r
#define rep(i,n) for(i=1;i<=(n);i++)
#define rep0(i,n) for(i=0;j<=(n);i++)
#define re(i,n) for(i=1;i<(n);i++)
#define re0(i,n) for(i=0;i<(n);i++)
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
#define PB push_back
#define X first
#define Y second
#define PI acos(-1.0)
#include <stdio.h>
#include <string.h>
#include <string>
#include <sstream>
#include <math.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef long long Ll;
Ll Pow(Ll a,Ll b,Ll MOD){a%=MOD;Ll res=1;while(b){if(b&1)res=(res*a)%MOD;b/=2;a=(a*a)%MOD;}return res;}

const int maxn=200000+10;
const int MOD=1e9+7;
/*
sol 1:
int a[maxn],dp[101][20001];

int main()
{
    int i,j,n;
    sc(n);
    for(i=1;i<=n;i++) sc(a[i]);
    int off=10000;
    memset(dp,0,sizeof(dp));
    dp[1][off+a[1]]=1;
    dp[1][off-a[1]]=1;
    for(i=2;i<=n;i++){
        for(j=0;j<=20000;j++){
            if(j>=a[i]) dp[i][j]|=dp[i-1][j-a[i]];
            if(j+a[i]<=20000) dp[i][j]|=dp[i-1][j+a[i]];
        }
    }
    int res=0;
    for(i=0;i<=off;i++){
        if(dp[n][off+i] || dp[n][off-i]) break;
    }
    printf("%d\n",i);
    return 0;
}
*/
// sol 2
int a[101];
bitset<10001> dp,temp;

int main()
{
    int i,j,n,sum=0;
    sc(n);
    rep(i,n){
        sc(a[i]);sum+=a[i];
    }
    dp.reset();
    dp.set(0);
    rep(i,n){
        temp=(dp<<a[i]);
        dp|=temp;
    }
    int res=sum;
    for(i=0;i<=sum;i++){
        if(dp[i]){//puts("??");
            res=min(res,abs(sum-2*i));
        }
    }
    printf("%d\n",res);
    return 0;
}

