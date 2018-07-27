/****************
*PID:
*Auth:Jonariguez
*****************
*/
#define lson k*2,l,m
#define rson k*2+1,m+1,r
#define rep(i,n) for(i=1;i<=(n);i++)
#define rep0(i,n) for(i=0;j<=(n);i++)
#define re(i,n) for(i=1;i<(n);i++)
#define re0(i,n) for(i=0;i<(n);i++)
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
#include <sstream>
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

const int maxn=1000+10;
const int MOD=1e9+7;

char a[maxn],b[maxn];
int dp[maxn][maxn],di[maxn][maxn],dj[maxn][maxn];

void print(int n,int m){
    if(dp[n][m]==0) return ;
    if(a[n]==b[m] && dp[n][m]==dp[n-1][m-1]+1){
        print(n-1,m-1);
        printf("%c",a[n]);
        return ;
    }
    print(di[n][m],dj[n][m]);
}

int main()
{
    int i,j,n,m;
    scanf("%s",a+1);
    n=strlen(a+1);
    scanf("%s",b+1);
    m=strlen(b+1);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(a[i]==b[j]){
                dp[i][j]=dp[i-1][j-1]+1;
                di[i][j]=i-1;dj[i][j]=j-1;
            }
            else {
                if(dp[i][j]<dp[i-1][j]){
                    dp[i][j]=dp[i-1][j];di[i][j]=i-1;dj[i][j]=j;
                }
                if(dp[i][j]<dp[i][j-1]){
                    dp[i][j]=dp[i][j-1];di[i][j]=i;dj[i][j]=j-1;
                }
            }
        }
    }
    print(n,m);
    puts("");
    return 0;
}


