/****************
*PID:149d div2
*Auth:Jonariguez
*****************
dp[cl][cr][l][r]:在l-1处染cl颜色，在r+1处染cr颜色，那么区间[l,r]的染色情况数
cl={0,1,2}
答案为dp[0][0][1][n]
记忆化搜索
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

const int maxn=700+10;
const int MOD=1e9+7;
LL dp[3][3][maxn][maxn];
char str[maxn];
int match[maxn];

LL DP(int cl,int cr,int l,int r){
    if(l==r+1 && cl==cr && cl!=0) return 0;
    if(l>=r) return 1;
    if(dp[cl][cr][l][r]>=0) return dp[cl][cr][l][r];
    LL &ans=dp[cl][cr][l][r];
    ans=0;
    int R=match[l];
    if(cl){
        ans=(ans+DP(3-cl,0,l+1,R-1)*DP(0,cr,R+1,r)%MOD)%MOD;
        ans=(ans+DP(0,1,l+1,R-1)*DP(1,cr,R+1,r)%MOD)%MOD;
        ans=(ans+DP(0,2,l+1,R-1)*DP(2,cr,R+1,r)%MOD)%MOD;
    }else {
        ans=(ans+DP(1,0,l+1,R-1)*DP(0,cr,R+1,r)%MOD)%MOD;
        ans=(ans+DP(2,0,l+1,R-1)*DP(0,cr,R+1,r)%MOD)%MOD;
        ans=(ans+DP(0,1,l+1,R-1)*DP(1,cr,R+1,r)%MOD)%MOD;
        ans=(ans+DP(0,2,l+1,R-1)*DP(2,cr,R+1,r)%MOD)%MOD;
    }
   // printf("cl=%d cr=%d l=%d r=%d ans=%d\n",cl,cr,l,r,ans);
    return ans;
}


int main()
{
    int i,j,n;
    while(scanf("%s",str+1)!=EOF){
        n=strlen(str+1);
        for(i=0;i<=n;i++) match[i]=n+2; //即无穷大
        stack<int> s;
        for(i=1;i<=n;i++){
            if(str[i]=='(')
               s.push(i);
            else {
                match[s.top()]=i;
                s.pop();
            }
        }
        memset(dp,-1,sizeof(dp));
        printf("%I64d\n",DP(0,0,1,n));
    }
    return 0;
}




