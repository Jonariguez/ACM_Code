/****************
*PID:poj1141
*Auth:Jonariguez
*****************
区间dp，类似于poj2955
dp[i][j]:i到j需要添加的最少括号
而这些dp值，只是为构造最终解提供依据。
详细见print函数

dp决策有两种：
①如果两边匹配，则抛去两边剩[i+1][j-1]
②不管两边匹配不匹配都要尝试在中间分开是否有最优解，即dp[i][j]=min(dp[i][k]+dp[k+1][j])
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

const int maxn=100+10;
char str[maxn];
int dp[maxn][maxn];

bool match(int i,int j){
    return str[i]=='[' && str[j]==']' || str[i]=='(' && str[j]==')';
}

void print(int x,int y){
    if(x>y) return ;
    if(x==y){       //如果是剩一个，那么自然就是手动添加括号进行匹配
        if(str[x]=='(' || str[x]==')')
            printf("()");
        else printf("[]");
        return ;
    }
    if(match(x,y) && dp[x][y]==dp[x+1][y-1]){   //如果两边相等，输入两边，并递归中间的，但前提是dp[x][y]是由
        printf("%c",str[x]);                                                    //dp[x+1][y-1]转移过来的
        print(x+1,y-1);
        printf("%c",str[y]);
        return ;
    }
    int k;
    for(k=x;k<y;k++){
        if(dp[x][y]==dp[x][k]+dp[k+1][y]){
            print(x,k);
            print(k+1,y);
            return ;
        }
    }
}

int main()
{
    int i,j,k,n;
    scanf("%s",str+1);
    n=strlen(str+1);
    memset(dp,0,sizeof(dp));
    for(i=1;i<=n;i++) dp[i][i]=1;
    for(i=n-1;i>=1;i--){
        for(j=i+1;j<=n;j++){
            dp[i][j]=n+1;
            if(match(i,j)) dp[i][j]=dp[i+1][j-1];
            for(k=i;k<j;k++)
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
        }
    }
    print(1,n);
    puts("");
    return 0;
}








