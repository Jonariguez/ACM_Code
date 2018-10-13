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

const int maxn=1000000+10;
const int maxm=6000000+10;
const int MOD=1e9+7;

struct Edge{
    int from,to,cap,flow;
};

typedef struct DINIC{
    int n,m,s,t;
    vector<Edge> edges;
    vector<int> G[maxn];
    //bool vis[maxn];
    int d[maxn],cur[maxn];

    void add(int from,int to,int cap){
        edges.push_back((Edge){from,to,cap,0});
        //edges.push_back((Edge){to,from,0,0});
        m=edges.size();
        G[from].push_back(m-1);
        //G[to].push_back(m-1);
    }

    bool bfs(){
        memset(d,0,sizeof(d));
        queue<int> que;
        while(!que.empty()) que.pop();
        que.push(s);
        d[s]=1;//vis[s]=1;
        while(!que.empty()){
            int x=que.front();que.pop();
            for(int i=0;i<G[x].size();i++){
                Edge &e=edges[G[x][i]];
                if(!d[e.to] && e.cap>e.flow){
                    //vis[e.to]=1;
                    d[e.to]=d[x]+1;
                    que.push(e.to);

                }
            }
            if(d[t]) return true;
        }
        return d[t]>0;
    }

    int dfs(int x,int a){
        if(x==t || a==0) return a;
        int flow=0,f;
        for(int &i=cur[x];i<G[x].size();i++){
            Edge &e=edges[G[x][i]];
            if(d[x]+1==d[e.to] && e.cap>e.flow){
                f=dfs(e.to,min(a,e.cap-e.flow));
                if(f){
                    e.flow+=f;
                    edges[G[x][i]^1].flow-=f;
                    flow+=f;
                    a-=f;
                }else
                    d[e.to]=-1;
                if(a==0) break;
            }
        }
        return flow;
    }

    int Maxflow(int s,int t){
        this->s=s;this->t=t;
        int flow=0;
        while(bfs()){
            memset(cur,0,sizeof(cur));
            flow+=dfs(s,1000000000);
        }
        return flow;
    }
}Dinic;

Dinic mfw;

int main()
{
    int i,j,n,m;
    scanf("%d%d",&n,&m);
    int x,y,v;
    for(i=1;i<=n;i++){
        for(j=1;j<m;j++){
            scanf("%d",&v);
            x=(i-1)*m+j;
            y=x+1;
            mfw.add(x,y,v);
            mfw.add(y,x,v);
        }
    }
    for(i=1;i<n;i++){
        for(j=1;j<=m;j++){
            scanf("%d",&v);
            x=(i-1)*m+j;
            y=x+m;
            mfw.add(x,y,v);
            mfw.add(y,x,v);
        }
    }
    for(i=1;i<n;i++){
        for(j=1;j<m;j++){
            scanf("%d",&v);
            x=(i-1)*m+j;
            y=x+m+1;
            mfw.add(x,y,v);
            mfw.add(y,x,v);
        }
    }

    printf("%d\n",mfw.Maxflow(1,n*m));
    return 0;
}





