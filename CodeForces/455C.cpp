/****************
*PID:455c div1
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

const int maxn=300000+5;
int par[maxn],cnt[maxn],vis[maxn],d[maxn];
vector<int> con[maxn],ver;

void Init(int n){
    for(int i=0;i<=n;++i){
        con[i].clear();par[i]=i;cnt[i]=0;
    }
    memset(vis,0,sizeof(vis));
}

void add(int u,int v){
    con[u].push_back(v);
}

int find(int x){
    return x==par[x]?x:par[x]=find(par[x]);
}

void Union(int u,int v){
    if((u=find(u))==(v=find(v))) return ;
    if(cnt[u]<cnt[v])
        swap(u,v);  //注意要取cnt[u]和新增的情况的max值，因为即便增加新的边，可能不会破坏之前的最长链的长度。
    cnt[u]=max(cnt[u],(cnt[u]+1)/2+(cnt[v]+1)/2+1); //两边最长链的一半相加再加上中间新增的边即为最长链。(保证最短)
    par[v]=u;
}

void dfs(int u,int pa,int deep){
    d[u]=deep;
    vis[u]=1;
    ver.push_back(u);
    for(int i=0;i<con[u].size();i++){
        int v=con[u][i];
        if(vis[v]) continue;
        dfs(v,u,deep+1);
    }
}

int main()
{
    int i,j,n,m,Q;
    while(scanf("%d%d%d",&n,&m,&Q)!=EOF){
        Init(n);
        for(i=1;i<=m;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            add(a,b);add(b,a);
        }
        for(i=1;i<=n;i++){
            if(!vis[i]){
                ver.clear();
                dfs(i,-1,0);
                int v=-1;
                for(j=0;j<ver.size();j++)
                    if(v==-1 || d[v]<d[ver[j]]) v=ver[j];
                for(j=0;j<ver.size();j++)
                    vis[ver[j]]=0;
                ver.clear();
                dfs(v,-1,0);
                for(j=0;j<ver.size();j++)
                    if(v==-1 || d[v]<d[ver[j]]) v=ver[j];
                for(j=0;j<ver.size();j++)
                    par[ver[j]]=v;
                cnt[v]=d[v];
            }
        }
        while(Q--){
            int o,x,y;
            scanf("%d",&o);
            if(o==1){
                scanf("%d",&x);
                printf("%d\n",cnt[find(x)]);
            }else {
                scanf("%d%d",&x,&y);
                Union(x,y);
            }
        }
    }
    return 0;
}

