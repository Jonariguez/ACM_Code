/****************
*PID:hdu2089
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
/*
const int maxn=100000+10;
int dp[10][11];

void Init(){
    memset(dp,0,sizeof(dp));    //dp[i][j]:共i位数，第i位是j的方案数。
    int i,j,k;
    dp[0][0]=1;
    for(i=1;i<=7;i++){
        for(j=0;j<10;j++){  //  第i位
            for(k=0;k<10;k++){  //第i-1位，即十进制的后面那一位
                if(j==4 || j==6 && k==2) continue;
                dp[i][j]+=dp[i-1][k];
            }
        }
    }
}


int solve(int n){
    int res=0,digit[10],cnt=0;
    while(n){
        digit[++cnt]=n%10;
        n/=10;
    }
    digit[cnt+1]=0;
    int i,j;
    for(i=cnt;i>=1;i--){
        for(j=0;j<digit[i];j++){
            if(j==4 || j==2 && digit[i+1]==6) continue;
            res+=dp[i][j];
        }
        if(digit[i]==4 || digit[i]==2 && digit[i+1]==6) break;
    }
    return res;
}

int main()
{
    int i,j,n,m;
    Init();
    while(scanf("%d%d",&n,&m)){
        if(n==0 && m==0) break;
        printf("%d\n",solve(m+1)-solve(n));
    }
    return 0;
}
*/

int dp[8][2];   //dp[i][0]:前i位符合要求 dp[i][1]:前i位符合要求，且i+1位是6
int digit[10];

int dfs(int i,int s,bool e){    //i表示当前位，s表示i位之前处理的状态(见dp)，e表示当前位是否可以随意填
    if(i==0)
        return 1 ;
    if(!e && dp[i][s]!=-1)
        return dp[i][s] ;
    int res=0 ;
    int u=e?digit[i]:9 ;
    for(int d=0;d<=u;d++){
        if(d==4 || (s && d==2)) continue;
        res+=dfs(i-1,d==6,e && d==u);
    }
    return e?res:dp[i][s]=res;
}

int solve(int n){
    int i,cnt=0;
    memset(digit,0,sizeof(digit));
    while(n){
        digit[++cnt]=n%10;
        n/=10;
    }
    return dfs(cnt,0,1);
}

int main()
{
    int i,j,n,m;
    memset(dp,-1,sizeof(dp));
    while(scanf("%d%d",&n,&m)){
        if(n==0 && m==0) break;
        printf("%d\n",solve(m)-solve(n-1));
    }
    return 0;
}



