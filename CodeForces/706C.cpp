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
LL c[maxn],dp[maxn][2];
char str[2][maxn],t[2][maxn];

void revs(){
    int n=strlen(str[0])-1;
    int i=0;
    while(n>=0){
        str[1][i]=str[0][n];
        i++;n--;
    }
    str[1][i]='\0';
}

void revt(){
    int n=strlen(t[0])-1;
    int i=0;
    while(n>=0){
        t[1][i]=t[0][n];
        i++;n--;
    }
    t[1][i]='\0';
}

int main()
{
    int i,j,n,m;
    while(scanf("%d",&n)!=EOF){
        for(i=1;i<=n;i++)
            scanf("%I64d",&c[i]);
        memset(dp,-1,sizeof(dp));
        scanf("%s",str[0]);
        revs();
        dp[1][0]=0;dp[1][1]=c[1];
        for(i=2;i<=n;i++){
            //memset(t,'\0',sizeof(t));
            scanf("%s",t[0]);
            revt();
            if(dp[i-1][0]!=-1){
                if(strcmp(str[0],t[0])<=0){
                    if(dp[i][0]==-1) dp[i][0]=dp[i-1][0];
                    else dp[i][0]=min(dp[i][0],dp[i-1][0]);
                }
                if(strcmp(str[0],t[1])<=0){
                    if(dp[i][1]==-1) dp[i][1]=dp[i-1][0]+c[i];
                    else dp[i][1]=min(dp[i][1],dp[i-1][0]+c[i]);
                }
            }
            if(dp[i-1][1]!=-1){
                if(strcmp(str[1],t[0])<=0){
                    if(dp[i][0]==-1) dp[i][0]=dp[i-1][1];
                    else dp[i][0]=min(dp[i][0],dp[i-1][1]);
                }
                if(strcmp(str[1],t[1])<=0){
                    if(dp[i][1]==-1) dp[i][1]=dp[i-1][1]+c[i];
                    else dp[i][1]=min(dp[i][1],dp[i-1][1]+c[i]);
                }
            }
            strcpy(str[0],t[0]);
            strcpy(str[1],t[1]);
        }
        if(max(dp[n][0],dp[n][1])==-1)
            puts("-1");
        else {
            LL res;
            if(dp[n][0]==-1)
                res=dp[n][1];
            else if(dp[n][1]==-1)
                res=dp[n][0];
            else res=min(dp[n][0],dp[n][1]);
            Pfn(res);
        }
    }
    return 0;
}


