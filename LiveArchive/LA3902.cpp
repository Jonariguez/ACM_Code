/****************
*PID:ka3902
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=1000+5;
int n,s,k,par[maxn],vis[maxn];
struct Node{
    int d,u;
    bool operator < (const Node &r) const {
        return d>r.d;
    }
};
vector<int> G[maxn];
vector<Node> nodes;

void dfs1(int u,int pa,int deep){
    par[u]=pa;
    if(G[u].size()==1 && deep>k){
        nodes.push_back((Node){deep,u});
        return ;
    }
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(v!=pa)
            dfs1(v,u,deep+1);
    }
}

void dfs2(int u,int pa,int d){
    vis[u]=1;
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(v!=pa && d<k)        //d范围以内的都遍历，那怕向上走也是符合的。
            dfs2(v,u,d+1);
    }
}

int main()
{
    int i,j,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&s,&k);
        nodes.clear();
        for(i=0;i<=n;i++) G[i].clear();
        memset(par,0,sizeof(par));
        memset(vis,0,sizeof(vis));
        for(i=1;i<n;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        dfs1(s,-1,0);
        sort(nodes.begin(),nodes.end());
        int res=0;
        for(i=0;i<nodes.size();i++){
            if(vis[nodes[i].u]) continue;
            int u=nodes[i].u,cnt=k;
            while(cnt--) u=par[u];
          //  if(u==s) continue;//puts("??");
            dfs2(u,-1,0);
            res++;
        }
        printf("%d\n",res);
    }
    return 0;
}
