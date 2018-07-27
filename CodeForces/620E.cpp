/****************
*PID:620e edu
*Auth:Jonariguez
*****************
将树dfs序一下，因为颜色的范围较小，所以每种颜色
用一个线段树维护，然后对于修改，a节点的子树改成b颜色
只需要tree[b]中将a的dfs序列段设置成1，然后把在该dfs序
中的其他颜色tree[c](c!=b)设置成0，
对于查询，枚举每种颜色然后统计即可。

内存限制开不了那么多的线段树，可以把每种颜色压缩成一个long long的
整数来表示,然后pushUp时通过|运算来合并每种颜色。
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn=400000+5;
int head[maxn],vv[maxn*2],nxt[maxn*2],e;
int start[maxn],end[maxn],dfs_clock;
int c[maxn];

void Init(){
    memset(head,0,sizeof(head));
    e=1;dfs_clock=0;
}

void add(int u,int v){
    vv[e]=v;nxt[e]=head[u];head[u]=e++;
}

typedef struct segment{
    LL sum[maxn*8],set[maxn*8],mark[maxn*8];
    void pushUp(int k){
        sum[k]=sum[k*2]|sum[k*2+1];
    }
    void pushDown(int k,int l,int r){
        int lc=k*2,rc=k*2+1,m=(l+r)/2;
        if(set[k]){
            set[lc]=set[rc]=set[k];
            sum[lc]=sum[rc]=(1LL<<set[k]);
            set[k]=0;
        }
    }
    void build(int k,int l,int r){
        set[k]=0;sum[k]=0;mark[k]=0;
        if(l==r)
            return ;
        int m=(l+r)/2;
        build(k*2,l,m);
        build(k*2+1,m+1,r);
    }
    void Set(int a,int b,int c,int k,int l,int r){
        if(a<=l && r<=b){
            set[k]=c;sum[k]=(1LL<<c);
            return ;
        }
        pushDown(k,l,r);
        int m=(l+r)/2;
        if(a<=m)
            Set(a,b,c,k*2,l,m);
        if(b>m)
            Set(a,b,c,k*2+1,m+1,r);
        pushUp(k);
    }
    LL ask(int a,int b,int k,int l,int r){
        if(a<=l && r<=b)
            return sum[k];
        pushDown(k,l,r);
        int m=(l+r)/2;
        LL res=0;
        if(a<=m)
            res|=ask(a,b,k*2,l,m);
        if(b>m)
            res|=ask(a,b,k*2+1,m+1,r);
        pushUp(k);
        return res;
    }
}Tree;

Tree tree;

void dfs(int u,int pa){
    start[u]=++dfs_clock;
    int i;
    for(i=head[u];i;i=nxt[i]){
        int v=vv[i];
        if(v!=pa)
            dfs(v,u);
    }
    end[u]=dfs_clock;
}

int main()
{
    int i,j,n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        Init();
        dfs_clock=0;
        for(i=1;i<=n;i++)
            scanf("%d",&c[i]);
        int a,b;
        for(i=1;i<n;i++){
            scanf("%d%d",&a,&b);
            add(a,b);add(b,a);
        }
        dfs(1,-1);
        tree.build(1,1,dfs_clock);
        for(i=1;i<=n;i++)
            tree.Set(start[i],start[i],c[i],1,1,dfs_clock);
        int k,C;
        while(m--){
            scanf("%d",&k);
            if(k==1){
                scanf("%d%d",&a,&C);
                tree.Set(start[a],end[a],C,1,1,dfs_clock);
            }else {
                scanf("%d",&a);
                LL res=tree.ask(start[a],end[a],1,1,dfs_clock);
                int cnt=0;
                while(res){
                    if(res&1) cnt++;
                    res/=2;
                }
                printf("%d\n",cnt);
            }
        }
    }
    return 0;
}

