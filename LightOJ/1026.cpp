/****************
*PID:light1026
*Auth:Jonariguez
*****************
割边，桥
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=10000+10;
vector<int> map[maxn];
int low[maxn],dfn[maxn],flag[maxn],dfs_seq,tot,n,m;

struct Bridge{
    int a,b;
    Bridge(){}
    Bridge(int aa=0,int bb=0):a(aa),b(bb){}
    bool operator < (const Bridge r) const {
        if(a==r.a) return b<r.b;
        return a<r.a;
    }
};

vector<Bridge> bridge;

void init(){
    int i;
    bridge.clear();
    dfs_seq=0;
    memset(flag,0,sizeof(flag));
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    for(i=0;i<=n;i++)
        map[i].clear();
}

void add_Edge(int a,int b){
    map[a].push_back(b);
  //  map[b].push_back(a);
}

void Tarjan(int cur,int fa){
    int i,chi=0;
    low[cur]=dfn[cur]=++dfs_seq;
    for(i=0;i<map[cur].size();i++){
        int u=map[cur][i];
        if(dfn[u]==0){
            chi++;
            Tarjan(u,cur);
            low[cur]=min(low[cur],low[u]);
            if(low[u]>dfn[cur])
                bridge.push_back(Bridge(min(u,cur),max(u,cur)));
        }else if(u!=fa)
            low[cur]=min(low[cur],dfn[u]);
    }
}

int main()
{
    int i,j,T,kcase=1;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        init();
        int a,k,b;
        for(i=0;i<n;i++){
            scanf("%d (%d)",&a,&k);
            while(k--){
                scanf("%d",&b);
                add_Edge(a,b);
            }
        }
        for(i=0;i<n;i++)
            if(dfn[i]==0)
                Tarjan(i,i);        //一定要是dfs(i,i),而不是dfs(-1,i),dfs(0,i),dfs(1,i)
        sort(bridge.begin(),bridge.end());
        printf("Case %d:\n%d critical links\n",kcase++,bridge.size());
        for(i=0;i<bridge.size();i++)
            printf("%d - %d\n",bridge[i].a,bridge[i].b);
    }
    return 0;
}

