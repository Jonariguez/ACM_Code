/****************
*PID:uva11090
*Auth:Jonariguez
*****************
*/
#define lson k*2,l,m
#define rson k*2+1,m+1,r
#define rep(i,s,e) for(i=(s);i<=(e);i++)
#define For(j,s,e) For(j=(s);j<(e);j++)
#define in(x) scanf("%d",&x)
#define In(x) scanf("%I64d",&x)
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

const int maxn=55;
const int INF=1e9;
struct Edge{
    int from,to;
    double dist;
};

struct Bellman_ford{
    int n,m,inq[maxn],cnt[maxn];
    double dis[maxn];
    vector<int> G[maxn];
    vector<Edge> edges;
    void init(int n){
        this->n=n;
        for(int i=0;i<=n;i++) G[i].clear();
        edges.clear();
    }
    void add(int u,int v,double w){
        edges.push_back((Edge){u,v,w});
        m=edges.size();
        G[u].push_back(m-1);
    }
    bool negativeCycle(){
        queue<int> que;
        memset(inq,0,sizeof(inq));
        memset(cnt,0,sizeof(cnt));
        int i;
        for(i=1;i<=n;i++){
            que.push(i);
            dis[i]=0;
        }
        dis[1]=0;
        while(!que.empty()){
            int u=que.front();que.pop();
          //  if(inq[u]) continue;
            inq[u]=0;
            for(i=0;i<G[u].size();i++){
                Edge &e=edges[G[u][i]];
                if(dis[e.to]>dis[u]+e.dist){
                    dis[e.to]=dis[u]+e.dist;
                    if(inq[e.to]==0){
                        que.push(e.to);
                        inq[e.to]=1;
                        if(++cnt[e.to]>n) return true;
                    }
                }
            }
        }
        return false;
    }
}solver;

bool C(double x){
    int i;
    for(i=0;i<solver.m;i++)
        solver.edges[i].dist-=x;
    bool res=solver.negativeCycle();
    for(i=0;i<solver.m;i++)
        solver.edges[i].dist+=x;
    return res;
}

int main()
{
    int i,j,n,m,T,kcase=1;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        solver.init(n);
        double L=0,R=0;
        for(i=1;i<=m;i++){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            solver.add(a,b,(double)c);
            R=max(R,(double)c);
        }
        printf("Case #%d: ",kcase++);
        if(!C(R+1)){
            puts("No cycle found.");continue;
        }
        for(i=0;i<105;i++){
            double M=(L+R)/2;
            if(C(M))
                R=M;
            else L=M;
        }
        printf("%.2f\n",L);
    }
    return 0;
}

