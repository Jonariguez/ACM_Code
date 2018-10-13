/****************
*PID:hdu1520
*Auth:Jonariguez
*****************
dp[u][0]:以u为根的子树不选u节点的最大值，dp[u][1]为选了
然后转移即可
多组输入。。。
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

const int maxn=6000+10;
const int MOD=1e9+7;

int dp[maxn][2],a[maxn],d[maxn];
vector<int> con[maxn];

void dfs(int u){
    if(con[u].size()==0){
        dp[u][0]=0;
        dp[u][1]=a[u];
        return ;
    }
    int max0=0,max1=0;
    for(int i=0;i<con[u].size();i++){
        int v=con[u][i];
        dfs(v);
        max0+=dp[v][0];
        max1+=max(dp[v][0],dp[v][1]);
    }
    dp[u][0]=max1;
    dp[u][1]=max0+a[u];
}

int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF){
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
            con[i].clear();
        }
        memset(d,0,sizeof(d));
        int x,y;
        while(scanf("%d%d",&x,&y) && x!=0 && y!=0){
            con[y].push_back(x);
            d[x]++;
        }
        int p;
        for(i=1;i<=n;i++){
            dp[i][0]=dp[i][1]=-10000;
            if(d[i]==0) p=i;
        }
        dfs(p);
        printf("%d\n",max(dp[p][0],dp[p][1]));
    }
    return 0;
}
