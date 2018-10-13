/****************
*PID:bzoj1003
*Auth:Jonariguez
*****************
cost[i][j]:从第i天到第j天都使用一条线路的最短路径
暴力枚举i和j，用spfa算出来最短路径即可
dp[i]:前i天的最小费用
dp[i]=min{dp[j]+cost[j+1][i]+k}
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

const int maxn=200+10;
const int maxm=10000;
const int MOD=1e9+7;

int head[maxn],nxt[maxm],wei[maxm],vv[maxm],e=1;
int n,m,k,E;
int cost[maxn][maxn],dis[maxn];
bool flag[maxn][22],vis[maxn],yes[22];
int dp[maxn];

void add(int u,int v,int w){
    wei[e]=w;nxt[e]=head[u];vv[e]=v;head[u]=e++;
}

int spfa(){
    for(int i=1;i<=m;i++)
        dis[i]=MOD;
    dis[1]=0;
    memset(vis,0,sizeof(vis));
    vis[1]=1;
    queue<int> que;
    que.push(1);

    while(!que.empty()){
        int u=que.front();que.pop();
        vis[u]=0;
        for(int i=head[u];i;i=nxt[i]){
            int v=vv[i],w=wei[i];
            if(dis[v]>dis[u]+w && !yes[v]){
                dis[v]=dis[u]+w;
                if(!vis[v]){
                    vis[v]=1;
                    que.push(v);
                }
            }
        }
    }
    return dis[m];
}


int main()
{
    int i,j;
    scanf("%d%d%d%d",&n,&m,&k,&E);
    for(i=1;i<=E;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);
        add(v,u,w);
    }
    int D;
    scanf("%d",&D);
    memset(flag,0,sizeof(flag));
    while(D--){
        int P,a,b;
        scanf("%d%d%d",&P,&a,&b);
        for(i=a;i<=b;i++)
            flag[i][P]=true;
    }
    for(i=1;i<=n;i++){
        for(j=i;j<=n;j++){
            memset(yes,0,sizeof(yes));
            for(int t=1;t<=m;t++)
                for(int z=i;z<=j;z++)
                    yes[t]|=flag[z][t];
            cost[i][j]=spfa();
            if(cost[i][j]<MOD)
                cost[i][j]*=(j-i+1);
        }
    }
    for(i=1;i<=n;i++)
        dp[i]=cost[1][i];
    for(i=2;i<=n;i++)
        for(j=1;j<i;j++)
            dp[i]=min(dp[i],dp[j]+cost[j+1][i]+k);
    printf("%d\n",dp[n]);
    return 0;
}


