/****************
*PID:poj3280
*Auth:Jonariguez
*****************
对于当前区间[i,j]，如果去掉i或者j形成的区间
[i+1,j]或者[i,j-1]是回文，那么我们就应该取点i或者j，
也可以在另一端加上这个字符，都符合题意，所以
对于每个字符是添加还是删除，只取决于两者的消耗cost。
其实就是删除和添加的效果都是一样的，取cost小的那个用就好了
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

const int maxn=2000+10;
char str[maxn];
int cost[30],dp[maxn][maxn];

int main()
{
    int i,j,n,m,res;
    scanf("%d%d",&n,&m);
    scanf("%s",str+1);
    char s[3];
    for(i=1;i<=n;i++){
        int x,y;
        scanf("%s%d%d",s,&x,&y);
        cost[s[0]-'a']=min(x,y);
    }
    memset(dp,0,sizeof(dp));
    for(j=2;j<=m;j++){
        for(i=j-1;i>=1;i--){
            if(str[i]==str[j])
                dp[i][j]=dp[i+1][j-1];
            else dp[i][j]=min(dp[i+1][j]+cost[str[i]-'a'],dp[i][j-1]+cost[str[j]-'a']);
        }
    }
    printf("%d\n",dp[1][m]);
    return 0;
}


