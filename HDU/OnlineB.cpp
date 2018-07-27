/****************
*PID:B
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;

const int maxn=10000+10;
struct Node{
    int b,id;
};
vector<Node> mp[maxn];

int val[maxn],deg[maxn],vis[maxn*10];
int x[maxn],y[maxn];

struct Edge{
    int a,b,id;
}s[maxn*10];



typedef struct UFSet{
    int par[maxn],rank[maxn];
    ll sum[maxn];
    void Init(int n){
         for(int i=0;i<maxn;i++){
                rank[i]=1;par[i]=i;
         }
         for(int i=1;i<=n;i++)
            sum[i]=val[i];
    }
    int Find(int x){
        if(par[x]==x) return x;
        int y=Find(par[x]);
        sum[x]+=sum[par[x]];
        return par[x]=y;
    }
    void Union(int u,int v){
        if((u=Find(u))==(v=Find(v))) return ;
        par[v]=u;
        rank[u]+=rank[v];
        sum[u]+=sum[v];
    }
}UFSet;

void solve(int n){
    queue<int> que;
    int i,j;
    for(i=1;i<=n;i++)
        if(deg[i]<=1)
            que.push(i);
    while(!que.empty()){
        int t=que.front();que.pop();
        for(i=0;i<mp[t].size();i++){
            Node u=mp[t][i];
            if(vis[u.id]==1) continue;
            vis[u.id]=1;deg[t]--;deg[u.b]--;
            if(deg[u.b]<=1)
                que.push(u.b);
        }
    }
}

UFSet uf;

int main()
{
    int i,j,T,n,m;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        fill(deg,deg+n+1,0);
        fill(vis,vis+m+1,0);
        for(i=0;i<=n;i++)
            mp[i].clear();
        for(i=1;i<=n;i++)
            scanf("%d",&val[i]);
        for(i=0;i<m;i++){
            scanf("%d%d",&x[i],&y[i]);
            deg[x[i]]++;deg[y[i]]++;
            Node u;
            u.id=i;u.b=y[i];
            mp[x[i]].push_back(u);
            u.b=x[i];
            mp[y[i]].push_back(u);
        }
        solve(n);
        uf.Init(n);
        for(i=0;i<m;i++){
            if(!vis[i]){
                uf.Union(x[i],y[i]);
            }
        }
        ll res=0;
        for(i=1;i<=n;i++){
            if(uf.par[i]==i && uf.rank[i]!=1 && uf.rank[i]&1)
                res+=uf.sum[i];
        }
        printf("%lld\n",res);
    }
    return 0;
}



