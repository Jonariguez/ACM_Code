/****************
*PID:uva10859
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

const int maxn=1000+10;
const int base=2000;
int vis[maxn][2],dp[maxn][2],mark[maxn];
vector<int> G[maxn];

int DP(int u,int j,int pa){
    if(vis[u][j]) return dp[u][j];
    vis[u][j]=1;
    int &ans=dp[u][j];
    ans=2000;   //先放灯
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(v==pa) continue;
        ans+=DP(v,1,u);
    }
    if(j==0 && pa>=0) ans++; //u不是根且父亲没有放灯，ans++
    if(j==1 || pa<0){
        int sum=0;
        for(int i=0;i<G[u].size();i++){
            int v=G[u][i];
            if(v==pa) continue;
            sum+=DP(v,0,u);
        }
        if(pa>0) sum++; //父亲节点放了灯，而u没放，则只被一个灯照亮的边又增加一条，边(f[u],u)
        ans=min(ans,sum);
    }
    return ans;
}

int main()
{
    int i,j,n,m,T;
    sc(T);
    while(T--){
        sc(n);sc(m);
        rep(i,1,n) G[i].clear();
        rep(i,1,m){
            int a,b;
            sc(a);sc(b);a++;b++;
            G[a].push_back(b);G[b].push_back(a);
        }
        memset(vis,0,sizeof(vis));
        int res=0;
        rep(i,1,n)
            if(!vis[i][0])
                res+=DP(i,0,-1);
        printf("%d %d %d\n",res/base,m-res%base,res%base);
    }
    return 0;
}


