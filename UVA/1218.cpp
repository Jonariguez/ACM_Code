/****************
*PID:uva1218
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=10000+10;
const int INF = 1000000000;
int dp[maxn][3],p[maxn],n;
vector<int> G[maxn],ver;

void dfs(int u,int fa){
    ver.push_back(u);
    p[u]=fa;
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(v!=fa) dfs(v,u);
    }
}

int main()
{
    int i,j;
    while(scanf("%d",&n)==1){
        for(i=0;i<=n;i++)
            G[i].clear();
        for(i=0;i<n-1;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            u--;v--;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        ver.clear();
        dfs(0,-1);
        for(i=ver.size()-1;i>=0;i--){
            int u=ver[i];
            dp[u][0]=1;dp[u][1]=0;
            for(j=0;j<G[u].size();j++){
                int v=G[u][j];
                if(v==p[u]) continue;
                dp[u][0]+=min(dp[v][0],dp[v][1]);
                dp[u][1]+=dp[v][2];
                if(dp[u][0]>INF) dp[u][0]=INF;
                if(dp[u][1]>INF) dp[u][1]=INF;
            }
            dp[u][2]=n;
            for(j=0;j<G[u].size();j++){
                int v=G[u][j];
                if(v!=p[u])
                    dp[u][2]=min(dp[u][2],dp[u][1]-dp[v][2]+dp[v][0]);
            }
        }
        printf("%d\n",min(dp[0][0],dp[0][2]));
        scanf("%d",&n);
        if(n==-1) break;
    }
    return 0;
}
