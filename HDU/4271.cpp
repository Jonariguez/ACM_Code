/****************
*PID:hdu4271
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
const int INF=1e9;
char str[maxn],dict[13][20];
int dp[20][maxn+10];

int DP(char *s1,int l1,char *s2,int l2){    //s1->s2
    int res=INF,i,j;
    for(i=1;i<=l1;i++)
        dp[i][0]=i;
    for(i=1;i<=l1;i++){
        for(j=1;j<=l2;j++){
            dp[i][j]=min(dp[i-1][j-1]+(s1[i]!=s2[j]),min(dp[i-1][j],dp[i][j-1])+1);
            if(i==l1)
                res=min(res,dp[i][j]);
        }
    }
    return res;
}

int main()
{
    int i,j,k,n,m;
    while(scanf("%s",str+1)!=EOF){
        n=strlen(str+1);
        int q;
        scanf("%d",&q);
        for(i=1;i<=q;i++)
            scanf("%s",dict[i]+1);
        int ans=-1,ansid=-1;
        while(q){
            m=strlen(dict[q]+1);
            for(i=1;i<=m;i++) dp[0][i]=i;
            int res=1000000000;
            if(n<20){
                for(i=1;i<=n;i++){
                    res=min(res,DP(dict[q],m,str+i-1,n));
                    str[n+i]=str[i];
                }
            }else {
                for(i=1;i<=20;i++)
                    str[++n]=str[i];
                res=DP(dict[q],m,str,n);
            }
            if(ans==-1){
                ans=res;
                ansid=q;
            }else if(ans>res || (res==ans && strcmp(dict[ansid]+1,dict[q]+1)>0)){
                ans=res;ansid=q;
            }
            q--;
        }
        printf("%s %d\n",dict[ansid]+1,ans);
    }
    return 0;
}


/*
aaabbbb
2
alice
bob

aaabbbb
2
aaaaaaaaaa
bbbbbbbbbb
*/

