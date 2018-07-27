/****************
*PID:
*Auth:Jonariguez
*****************
*/
#define lson k*2,l,m
#define rson k*2+1,m+1,r
#define rep(i,n) for(i=1;i<=(n);i++)
#define rep0(j,n) for(j=0;j<=(n);j++)
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
typedef long long Ll;
Ll Pow(Ll a,Ll b,Ll MOD){a%=MOD;Ll res=1;while(b){if(b&1)res=(res*a)%MOD;b/=2;a=(a*a)%MOD;}return res;}

const int maxn=100+10;
const int MOD=1e9+7;

int dp[20][200],yes[20],lef[maxn],rht[maxn];
char str[maxn][maxn];

int main()
{
    int i,j,n,m;
    scanf("%d%d",&n,&m);
    int mx=0,up=0;
    for(i=1;i<=n;i++){
        scanf("%s",str[i]);
        lef[i]=m+1;
        for(j=1;j<m+1;j++){
            if(str[i][j]=='1'){
                rht[i]=j;yes[i]=1;mx=i;
                if(up==0) up=i;
            }
        }
        for(j=m;j>=1;j--)
            if(str[i][j]=='1')
                lef[i]=j;
    }
    dp[mx][0]=0;dp[mx][1]=m+1;
    if(yes[mx]){
        dp[mx][0]=rht[mx]*2;
        dp[mx][1]=m+1;
    }
    for(i=mx-1;i>=up;i--){
        dp[i][0]=min(dp[i+1][0]+1+rht[i]*2,dp[i+1][1]+1+m+1);
        dp[i][1]=min(dp[i+1][0]+1+m+1,dp[i+1][1]+1+(m+1-lef[i])*2);
    }
    printf("%d\n",min(dp[up+1][0]+1+rht[up],dp[up+1][1]+1+(m+1-lef[up])));
    return 0;
}
/*
int mx,m;

int dfs(int x,int y){
    if(mx==x){
        if(y==0)
            return rht[x];
        else return m+1-lef[x];
    }
    int res=0;
    if(y==0){
        if(yes[x])
            res=rht[x]*2;
        else res=0;
        return min(res+1+dfs(x-1,0),m+1+1+dfs(x-1,1));
    }else {
        if(yes[x])
            res=(m+1-lef[x])*2;
        else res=0;
        return min(res+1+dfs(x-1,1),m+1+1+dfs(x-1,0));
    }
}

int main()
{
    int i,j,n;
    scanf("%d%d",&n,&m);
    mx=n;
    for(i=1;i<=n;i++){
        scanf("%s",str[i]);
        for(j=1;j<=m;j++){
            if(str[i][j]=='1'){
                rht[i]=j;yes[i]=1;
                if(mx==n) mx=i;//puts("??");
            }
        }
        for(j=m;j>=1;j--)
            if(str[i][j]=='1')
                lef[i]=j;
        //printf("l=%d r=%d\n",lef[i],rht[i]);
    }
    printf("%d\n",dfs(n,0));
    return 0;
}
*/

