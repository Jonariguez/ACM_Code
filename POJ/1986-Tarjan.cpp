/****************
*PID:poj1986
*Auth:Jonariguez
*****************
Tarjan
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=40000+5;
int head[maxn],wei[maxn*2],vv[maxn*2],nxt[maxn*2],e,dis[maxn];
int par[maxn],res[10005],vis[maxn];

struct Query{
    int to,id;
    Query(int to=0,int id=0):to(to),id(id){}
};

vector<Query> qu[maxn];

void Init(int n){
    memset(head,0,sizeof(head));
    memset(vis,0,sizeof(vis));
    e=1;
    for(int i=0;i<=n;i++){
        par[i]=i;
        qu[i].clear();
    }
}

void add(int u,int v,int w){
    wei[e]=w;vv[e]=v;nxt[e]=head[u];head[u]=e++;
}

int find(int x){
    return x==par[x]?x:par[x]=find(par[x]);
}

void LCA(int u,int pa){
    par[u]=u;
    vis[u]=1;
    int i,j,v,id,w;
    for(i=0;i<qu[u].size();i++){
        v=qu[u][i].to;
        id=qu[u][i].id;
        if(vis[v]==0) continue; //��Ϊu�����ڷ��ʵĽڵ㣬Ȼ�������u���ӵĵ����б����ʹ��ģ���ô���ߵ�LCA�϶���
        int lca=find(v);        //find(v),(ע�ⲻ��v������find(v))
        res[id]=dis[v]+dis[u]-2*dis[lca];   //���ڲ�ͬ��Ŀ�������Ǵ���𰸵ĵط���
    }           //�������ѯ�ټ����ݹ顣
    for(i=head[u];i;i=nxt[i]){
        v=vv[i];w=wei[i];
        if(v==pa) continue;
        dis[v]=dis[u]+w;
        LCA(v,u);
        par[v]=u;       //��һ������v������ʱ���˳���������ô�������par��Ҫ���u���ò��鼯�Ż���ֻ���޸�par[v]����
    }
}

int main()
{
    int i,j,n,m,k;
    scanf("%d%d",&n,&m);
    Init(n);
    char str[5];
    int u,v,w;
    for(i=0;i<m;i++){
        scanf("%d%d%d%s",&u,&v,&w,str);
        add(u,v,w);add(v,u,w);
    }
    scanf("%d",&k);
    for(i=1;i<=k;i++){
        scanf("%d%d",&u,&v);
        qu[u].push_back(Query(v,i));    //��¼��ѯ������
        qu[v].push_back(Query(u,i));
        res[i]=0;
    }
    dis[1]=0;
    LCA(1,-1);
    for(i=1;i<=k;i++)
        printf("%d\n",res[i]);
    return 0;
}
