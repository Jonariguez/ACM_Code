/*
hdu1385
*/
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=2000+10;
const int INF=0x7fffffff;
int mp[maxn][maxn],b[maxn],d[maxn],par[maxn];
int n;

struct Edge{
    int to,wei;
};

struct Node{
    int u,D;
    bool operator < (const Node &r) const {
        return D>r.D;
    }
};

vector<Edge> con[maxn];

void Init(){
    for(int i=0;i<=n;i++)
        con[i].clear();
}

void add(int u,int v,int w){
    Edge e;
    e.to=v;e.wei=w;
    con[u].push_back(e);
}

int DIJK(int start,int End){
    int i,j,k;
    for(i=1;i<=n;i++){
        d[i]=INF;par[i]=INF;
    }
    d[start]=0;
    Node u;
    u.u=start;u.D=0;
    priority_queue<Node> que;
    que.push(u);
    while(!que.empty()){
        u=que.top();que.pop();
        if(u.D!=d[u.u]) continue;
        for(i=0;i<con[u.u].size();i++){
            Edge e=con[u.u][i];
            int v=e.to;
            if(d[v]>d[u.u]+e.wei){
                d[v]=d[u.u]+e.wei;
                par[v]=u.u;
                Node t;
                t.u=v;t.D=d[v];
                que.push(t);
            }else if(d[v]==d[u.u]+e.wei && u.u<par[v])
                par[v]=u.u;
        }
    }
    return d[End]-b[start];
}

int main()
{
    int i,j;
    while(scanf("%d",&n)!=EOF){
        if(n==0) break;
        Init();
        memset(mp,0,sizeof(mp));
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                scanf("%d",&mp[i][j]);
        for(i=1;i<=n;i++)
            scanf("%d",&b[i]);
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(mp[i][j]==-1) continue;
                add(j,i,mp[i][j]+b[j]);     //注意反向建边的方法。
            }
        }
        int g,h;
        while(scanf("%d%d",&g,&h)!=EOF){
            if(g==-1 && h==-1) break;
            printf("From %d to %d :\n",g,h);
            if(g==h){
                printf("Path: %d\n",g);
                printf("Total cost : 0\n\n");
                continue;
            }
            int res=DIJK(h,g);
            printf("Path: %d",g);
            while(g!=h){
                g=par[g];
                printf("-->%d",g);
            }
            printf("\nTotal cost : %d\n\n",res);
        }
    }
    return 0;
}
