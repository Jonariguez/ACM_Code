/****************
*PID:hdu4323
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

const int maxn=1500+10;
int dp[20][20],len[maxn];
char dict[maxn][20],str[20];

int DP(char *s1,int l1,char *s2,int l2){
    memset(dp,0,sizeof(dp));
    int i,j;
    for(i=0;i<=l1;i++) dp[i][0]=i;
    for(i=0;i<=l2;i++) dp[0][i]=i;
    for(i=1;i<=l1;i++){
        for(j=1;j<=l2;j++){
            if(s1[i]==s2[j])
                dp[i][j]=dp[i-1][j-1];
            else{
                dp[i][j]=min(dp[i-1][j],dp[i][j-1])+1;
                dp[i][j]=min(dp[i][j],dp[i-1][j-1]+1);
            }
        }
    }
    return dp[l1][l2];
}

int main()
{
    int i,j,n,m,T,kcase=1;
    sc(T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++){
            scanf("%s",dict[i]+1);
            len[i]=strlen(dict[i]+1);
        }
        printf("Case #%d:\n",kcase++);
        while(m--){
            int d,cnt=0;
            scanf("%s%d",str+1,&d);
            int l=strlen(str+1);
            for(i=1;i<=n;i++){
                if(abs(len[i]-l)>d) continue;
                if(DP(dict[i],len[i],str,l)<=d)
                    cnt++;
            }
            pfn(cnt);
        }
    }
    return 0;
}



