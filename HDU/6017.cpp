/****************
*PID:hdu6017
*Auth:Jonariguez
*****************
dp[i][j][k]:第i个2放在第j位置，用了k次交换最多能得到多少个233
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

const int maxn=100+5;
const int MOD=1e9+7;

int dp[maxn][maxn][maxn],pos[maxn];
char str[maxn];

int main()
{
    int i,j,n,m,k,q,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        m/=2;
        scanf("%s",str+1);
        int tot=0;
        pos[0]=0;
        for(i=1;i<=n;i++){
            if(str[i]=='2')
                pos[++tot]=i;
        }
        memset(dp,-1,sizeof(dp));
        dp[0][0][0]=0;
        for(i=1;i<=tot;i++){
            for(j=i;j<=n-(tot-i);j++){
                for(k=abs(pos[i]-j);k<=m;k++){
                 //   if(k==0) dp[i][j][k]=max(dp[i][j][k],dp[i-1][pos[i-1]][k]);
                //    else {
                       // dp[i][j][k]=max(dp[i][j][k],dp[i-1][pos[i-1]][k]);
                     //   if(k>=abs(pos[i]-j)){
                        //    if(j>=1 && dp[i-1][j-1][k-abs(pos[i]-j)]>=0)
                        //        dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k-abs(pos[i]-j)]);
                        //    if(j>=2 && dp[i-1][j-2][k-abs(pos[i]-j)]>=0)
                        //        dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-2][k-abs(pos[i]-j)]);
                            for(q=1;q+i<=j+1;q++)  //这是枚举第i-1个2和第i个2之间的距离
                                if(dp[i-1][j-q][k-abs(pos[i]-j)]>=0)
                                    dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-q][k-abs(pos[i]-j)]+((q>=3 && q!=j)?1:0)); //q!=j一定要有
                    //    }
                //    }
                }
            }
        }
        int res=0;
        if(tot) //这里一定要判断
            for(i=tot;i<=n;i++)
                for(j=0;j<=m;j++)
                    res=max(res,dp[tot][i][j]+((i<n-1)?1:0));   //看最后一个2能否产生233
        printf("%d\n",res);
    }
    return 0;
}

