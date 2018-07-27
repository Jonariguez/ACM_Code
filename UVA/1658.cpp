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

const int maxn=2000+20;
const int MOD=1e9+7;
const int INF=1e9;


struct Edge{
    int from,to,cap,flow,cost;
    Edge(int u,int v,int c,int f,int w):from(u),to(v),cap(c),flow(f),cost(w) {}
};

struct MCMF{
    int n,m;
    vector<Edge> edges;
    vector<int> G[maxn];
    int a[maxn];
    int d[maxn];
    int p[maxn];
    int inq[maxn];

    void init(int n){
        this->n=n;
        for(int i=0;i<n;i++) G[i].clear();
        edges.clear();
    }

    void AddEdge(int from,int to,int cap,int cost){
        edges.push_back(Edge(from,to,cap,0,cost));
        edges.push_back(Edge(to,from,0,0,-cost));
        m=edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }

    bool BellmanFord(int s,int t,int flow_limit,int &flow,int &cost){
        for(int i=0;i<n;i++) d[i]=INF;
        memset(inq,0,sizeof(inq));
        a[s]=INF;inq[s]=1;
        p[s]=0;d[s]=0;
        queue<int> que;
        que.push(s);
        while(!que.empty()){
            int u=que.front();que.pop();
            inq[u]=0;
            for(int i=0;i<G[u].size();i++){
                Edge& e=edges[G[u][i]];
                if(e.cap>e.flow && d[e.to]>d[u]+e.cost){
                    d[e.to]=d[u]+e.cost;
                    p[e.to]=G[u][i];
                    a[e.to]=min(a[u],e.cap-e.flow);
                    if(!inq[e.to]){
                        que.push(e.to);
                        inq[e.to]=1;
                    }
                }
            }
        }
        if(d[t]==INF) return false;
        if(flow+a[t]>flow_limit) a[t]=flow_limit-flow;
        flow+=a[t];
        cost+=d[t]*a[t];
        for(int u=t;u!=s;u=edges[p[u]].from){
            edges[p[u]].flow+=a[t];
            edges[p[u]^1].flow-=a[t];
        }
        return true;
    }

    int MincostFlow(int s,int t,int flow_limit,int &cost){
        int flow=0;
        cost=0;
        while(flow<flow_limit && BellmanFord(s,t,flow_limit,flow,cost));
        return flow;
    }
};

MCMF g;

int main()
{
    int i,j,n,m;
    while(scanf("%d%d",&n,&m)==2 && n){
        g.init(2*n+3);
        for(i=2;i<=n-1;i++)
            g.AddEdge(i,n+i,1,0);
        int a,b,c;
        while(m--){
            scanf("%d%d%d",&a,&b,&c);
            if(a==1 && b==n)
                g.AddEdge(a,b,1,c);
            else if(a==1 && b!=n)
                g.AddEdge(a,b,1,c);
            else if(a!=1 && b==n)
                g.AddEdge(a+n,b,1,c);
            else if(a!=1 && b!=n)
                g.AddEdge(a+n,b,1,c);
        }
        int cost=0;
        g.MincostFlow(1,n,2,cost);
        printf("%d\n",cost);
    }
    return 0;
}

