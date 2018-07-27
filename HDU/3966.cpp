/****************
*PID:hdu3966
*Auth:Jonariguez
*****************
tid[u]=dfs_clock表示节点u的时间戳是dfs_clock
rank[dfs_clock]=u表示被第dfs_clock戳住的节点是u
我们建线段树维护时是维护连续的dfs_clock,
如dfs_clock=2,3,4,5..
那么对应到线段树的2,3,4,5..的位置应该维护时间戳是
2,3,4,5..的节点，那么时间戳为2,3,4,5..对应的节点就
由rank[dfs_clock]给出，rank[2]=u1,rank[3]=u2,rank[4]=u3..
(u1,u2,u3..则不一定连续，所以要用rank数组来映射)
关于tid，rank，dfs_clock和线段树中节点的对应关系，可以
看以下程序和图对照看一下。
图：http://blog.sina.com.cn/s/blog_7a1746820100wp67.html
*/
#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=50000+10;
int n,m,Q,dfs_clock;
int num[maxn],Size[maxn],son[maxn],par[maxn],dep[maxn],top[maxn];
int tid[maxn], Rank[maxn];
int sum[maxn*4],add[maxn*4];
vector<int> G[maxn];

void Init(){
    memset(son,-1,sizeof(son));
    dfs_clock=0;
    for(int i=1;i<=n;i++)
        G[i].clear();
}

void add_edge(int a,int b){
    G[a].push_back(b);
    G[b].push_back(a);
}

void dfs1(int u,int fa,int d){
    dep[u]=d;
    par[u]=fa;
    Size[u]=1;
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(v!=fa){
            dfs1(v,u,d+1);
            Size[u]+=Size[v];
            if(son[u]==-1 || Size[son[u]]<Size[v])
                son[u]=v;
        }
    }
}

void dfs2(int u,int p){
    top[u]=p;
    tid[u]=++dfs_clock;
    Rank[tid[u]]=u;
    if(son[u]==-1) return ;
    dfs2(son[u],p);
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(v!=son[u] && v!=par[u])
            dfs2(v,v);
    }
}

void pushUp(int k){
    sum[k]=sum[k*2]+sum[k*2+1];
}

void pushDown(int k,int l,int r){
    int m=(l+r)/2,lc=k*2,rc=k*2+1;
    if(add[k]){
        sum[lc]+=add[k]*(m-l+1);
        sum[rc]+=add[k]*(r-m);
        add[lc]+=add[k];
        add[rc]+=add[k];
        add[k]=0;
    }
}

void build(int k,int l,int r){
    sum[k]=add[k]=0;
    if(l==r){
        sum[k]=num[Rank[l]];
        return ;
    }
    int m=(l+r)/2;
    build(k*2,l,m);
    build(k*2+1,m+1,r);
    pushUp(k);
}

void update(int a,int b,int v,int k,int l,int r){
    if(a<=l && r<=b){
        sum[k]+=v*(r-l+1);add[k]+=v;return ;
    }
    pushDown(k,l,r);
    int m=(l+r)/2;
    if(a<=m)
        update(a,b,v,k*2,l,m);
    if(b>m)
        update(a,b,v,k*2+1,m+1,r);
    pushUp(k);
}

int ask(int p,int k,int l,int r){
    if(l==r)
        return sum[k];
    pushDown(k,l,r);
    int m=(l+r)/2,res=0;
    if(p<=m)
        res=ask(p,k*2,l,m);
    else
        res=ask(p,k*2+1,m+1,r);
    pushUp(k);
    return res;
}

void solve(int x,int y,int v){
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]])
            swap(x,y);
        update(tid[top[x]],tid[x],v,1,1,n);
        x=par[top[x]];
    }
    if(dep[x]>dep[y])
        swap(x,y);
    update(tid[x],tid[y],v,1,1,n);
}



int main()
{
    int i,j;
    char op[5];
    while(scanf("%d%d%d",&n,&m,&Q)!=EOF){
        Init();
        for(i=1;i<=n;i++)
            scanf("%d",&num[i]);
        int a,b;
        for(i=0;i<m;i++){
            scanf("%d%d",&a,&b);
            add_edge(a,b);
        }

        dfs1(1,0,0);
        dfs2(1,1);
        build(1,1,n);
        while(Q--){
            scanf("%s",op);
            if(op[0]=='Q'){
                scanf("%d",&a);
                printf("%d\n",ask(tid[a],1,1,n));
            }else {
                int c;
                scanf("%d%d%d",&a,&b,&c);
                if(op[0]=='D') c=-c;
                solve(a,b,c);
            }
        }
    }
    return 0;
}
