/****************
*PID:poj2186
*Auth:Jonariguez
*****************
裸的最大流 模板题
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=200+10;
const int INF=2000000002;

int n,m;

struct Edge{
    int from,to,cap,flow;
    Edge(int u,int v,int c,int f):from(u),to(v),cap(c),flow(f){}
};

struct Max_Flow{
    int n,m;
    vector<Edge> edges;
    vector<int> G[maxn];
    int a[maxn],p[maxn];

    void init(int n){
        for(int i=0;i<=n;i++) G[i].clear();
        edges.clear();
    }

    void AddEdge(int from,int to,int cap){
        edges.push_back(Edge(from,to,cap,0));
        edges.push_back(Edge(to,from,0,0));
        m=edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }

    int Maxflow(int s,int t){
        int flow=0;
        while(true){
            memset(a,0,sizeof(a));
            queue<int> que;
            que.push(s);
            a[s]=INF;
            while(!que.empty()){
                int x=que.front();que.pop();
                for(int i=0;i<G[x].size();i++){
                    Edge& e = edges[G[x][i]];
                    if(!a[e.to] && e.cap>e.flow){
                        p[e.to]=G[x][i];            //记录前驱
                        a[e.to]=min(a[x],e.cap-e.flow);
                        que.push(e.to);
                    }
                }
                if(a[t]) break;
            }
            if(!a[t]) break;
            for(int u=t;u!=s;u=edges[p[u]].from){
                edges[p[u]].flow+=a[t];
                edges[p[u]^1].flow-=a[t];
            }
            flow+=a[t];
        }
        return flow;
    }
};

Max_Flow maxFlow;

int main()
{
    int i,j;
    while(scanf("%d%d",&m,&n)!=EOF){
        maxFlow.init(n);
        for(i=0;i<m;i++){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            maxFlow.AddEdge(a,b,c);
        }
        printf("%d\n",maxFlow.Maxflow(1,n));
    }
    return 0;
}
