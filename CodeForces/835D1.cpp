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

const int maxn=5000+10;
const int MOD=1e9+7;

char str[maxn];
unsigned int cnt[maxn][maxn];
int dp[maxn][maxn];
bool vis[maxn][maxn];
int n,Id;

int dfs(int l,int r){
    if(l<1 || r>n || l>r) return 0;
    if(l==r) return dp[l][r]=1;
    if(dp[l][r]>=0) return dp[l][r];
    int &res=dp[l][r];
    res=0;
    if(vis[l][r]){
        res=1;
        int len=r-l+1;
        len/=2;
        int v1=dfs(l,l+len-1);
        res=max(res,v1+1);
    }
    if(dp[l+1][r]<0)
        dfs(l+1,r);
    if(dp[l][r-1]<0)
        dfs(l,r-1);
    return res;
}

int sum[maxn];

int main()
{
    int i,j,k;
    scanf("%s",str+1);
    n=strlen(str+1);
    memset(vis,0,sizeof(vis));
    for(i=1;i<=n;i++){
        vis[i][i]=1;
        j=i-1;
        k=i+1;
        while(j>=1 && k<=n){
            if(str[j]==str[k]){
                vis[j][k]=vis[k][j]=1;
                j--;k++;
            }else break;    //不相等了那么以后就不会是回文了，所以一定要break掉
        }
        j=i;
        k=i+1;
        while(j>=1 && k<=n){
            if(str[j]==str[k]){
                vis[j][k]=vis[k][j]=1;
                j--;k++;
            }else break;
        }
        j=i-1;
        k=i;
        while(j>=1 && k<=n){
            if(str[j]==str[k]){
                vis[j][k]=vis[k][j]=1;
                j--;k++;
            }else break;
        }
    }
    memset(dp,-1,sizeof(dp));
    dfs(1,n);
    sum[0]=0;
    for(i=1;i<=n;i++){
        for(j=i;j<=n;j++){
            sum[dp[i][j]]++;
        }
    }
    sum[n+1]=0;
    for(i=n;i>=1;i--){
        sum[i]+=sum[i+1];
    }
    for(i=1;i<=n;i++){
        printf("%d ",sum[i]);
    }
    puts("");
    return 0;
}
