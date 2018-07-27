/****************
*PID:hdu3974
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=50000+10;
int head[maxn],nxt[maxn*2],vv[maxn*2],e,dfs_clock,start[maxn],en[maxn],vis[maxn];
int sum[maxn*4],set[maxn*4];

void init(){
    e=1;     //因为head和next被初始化为0，则e应该被初始化为1而不是0
    memset(head,0,sizeof(head));
    dfs_clock=0;
}
void add(int u,int v){
    vv[e]=v;nxt[e]=head[u];head[u]=e++;
}

void pushDown(int k){
    int lc=k*2,rc=k*2+1;
    if(set[k]>=0){
        set[lc]=set[rc]=set[k];
       // sum[lc]=sum[rc]=set[k];
        set[k]=-1;
    }
}

void build(int k,int l,int r){
    set[k]=-1;sum[k]=0;
    if(l==r) return ;
    int m=(l+r)/2;
    build(k*2,l,m);
    build(k*2+1,m+1,r);
}

void update(int a,int b,int v,int k,int l,int r){
    if(a<=l && r<=b){
        set[k]=v;return ;
    }
    pushDown(k);
    int m=(l+r)/2;
    if(a<=m)
        update(a,b,v,k*2,l,m);
    if(b>m)
        update(a,b,v,k*2+1,m+1,r);
}

int ask(int p,int k,int l,int r){
    if(l==r){
        return set[k];
    }
    pushDown(k);
    int m=(l+r)/2;
    if(p<=m)
        return ask(p,k*2,l,m);
    else return ask(p,k*2+1,m+1,r);
}

void dfs(int u,int pa){
    start[u]=++dfs_clock;
    int i;
    for(i=head[u];i;i=nxt[i]){
        int v=vv[i];
        if(v==pa) continue;
        dfs(v,u);
    }
    en[u]=dfs_clock;
}

int main()
{
    int i,j,n,m,T,kcase=1;
    scanf("%d",&T);
    while(T--){
        printf("Case #%d:\n",kcase++);
        scanf("%d",&n);
        init();
        memset(vis,0,sizeof(vis));
        int u,v;
        for(i=1;i<n;i++){
            scanf("%d%d",&u,&v);
            add(v,u);
            vis[u]++;
        }
        for(i=1;i<=n;i++)
            if(vis[i]==0){
                dfs(i,-1);break;
            }
      //  printf("dfs=%d\n",dfs_clock);
        build(1,1,dfs_clock);
        scanf("%d",&m);
        char str[3];
        int x,y;
        while(m--){
            scanf("%s",str);
            if(str[0]=='C'){
                scanf("%d",&x);
                printf("%d\n",ask(start[x],1,1,dfs_clock));
            }else {
                scanf("%d%d",&x,&y);
                update(start[x],en[x],y,1,1,dfs_clock);
            }
        }
    }
    return 0;
}
