/****************
*PID:51nod 1050
*Auth:Jonariguez
*****************
将数组复制放到尾部，ST维护前缀和区间最小值，
枚举2*n个数，查询区间最小值更新最大值答案
*/
#define lson k*2,l,m
#define rson k*2+1,m+1,r
#define rep(i,n) for(i=1;i<=(n);i++)
#define rep0(i,n) for(i=0;j<=(n);i++)
#define re(i,n) for(i=1;i<(n);i++)
#define re0(i,n) for(i=0;i<(n);i++)
#define sc(x) scanf("%d",&x)
#define In(x) scanf("%I64d",&x)
#define SS(x,y) scanf("%d%d",&x,&y)
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
#include <vector>
#include <bitset>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef long long Ll;
Ll Pow(Ll a,Ll b,Ll MOD){a%=MOD;Ll res=1;while(b){if(b&1)res=(res*a)%MOD;b/=2;a=(a*a)%MOD;}return res;}

const int maxn=100000+10;
const int MOD=1e9+7;

int a[maxn];
LL sum[maxn],dp[maxn][25];

LL ask(int l,int r){
    int k=(int)log2(r-l+1);
    return min(dp[l][k],dp[r-(1<<k)+1][k]);
}

int main()
{
    int i,j,n;
    sc(n);
    sum[0]=0;
    dp[0][0]=0;
    rep(i,n){
        scanf("%I64d",&a[i]);
        sum[i]=sum[i-1]+a[i];
        dp[i][0]=sum[i];
    }
    int N=n*2;
    for(i=n+1;i<=N;i++){
        a[i]=a[i-n];
        sum[i]=sum[i-1]+a[i];
        dp[i][0]=sum[i];
    }
    for(j=1;(1<<j)<=N+1;j++){
        for(i=0;i+(1<<j)-1<=N;i++)
            dp[i][j]=min(dp[i][j-1],dp[i+(1<<j-1)][j-1]);
    }
    LL res=0;
    for(i=1;i<=N;i++){
        int last=max(0,i-n);
        res=max(res,sum[i]-ask(last,i));
       // Pfn(res);
    }
    Pfn(res);
    return 0;
}

