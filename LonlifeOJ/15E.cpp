#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=100000+10;
const int maxm=1000000+5;
const LL INF=(LL)1e18;

int head[maxn],nxt[maxm],cost[maxm],vv[maxm],e;
bool vis[maxn];
LL dis[maxn];

void Init(){
    memset(head,0,sizeof(head));
    e=1;
}

void add(int u,int v,int w){
    cost[e]=w;vv[e]=v;nxt[e]=head[u];head[u]=e++;
}

struct cmp{
    bool operator () (const int a,const int b){
        return dis[a]>dis[b];
    }
};

int S,T,n;
bool DJ(int val){
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++){
        dis[i]=INF;
    }
    int i;
    priority_queue<int,vector<int>,cmp> que;
    dis[S]=0;
    que.push(S);
    while(!que.empty()){
        int u=que.top();que.pop();
        vis[u]=1;
        if(u==T){
            if(dis[u]<INF) return true;
            else return false;
        }
        for(i=head[u];i;i=nxt[i]){
            int v=vv[i],cc=cost[i];
            if(cc>val) continue;
            if(vis[v]==0 && dis[v]>dis[u]+cc){
                dis[v]=dis[u]+cc;
                que.push(v);
            }
        }
    }
    return dis[T]<INF;
}

int main()
{
    int i,j;
    int m;
    scanf("%d%d",&n,&m);
    Init();
    int l=1,r=0;
    for(i=1;i<=m;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        if(u==v) continue;
        add(u,v,w);
        add(v,u,w);
        r=max(r,w);
    }
    scanf("%d%d",&S,&T);
    int res=-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(DJ(mid)){
            res=mid;
            r=mid-1;
        }else l=mid+1;
    }
    while(true){
        if(DJ(res-1)) res--;
        else break;
    }
    printf("%d\n",res);
    return 0;
}
