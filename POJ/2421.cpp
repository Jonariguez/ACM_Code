/*
MST-kruskal
其实就是在给定一部分边的情况下，再求最小生成树，肯定整个树不是MST
但是我们要必须要用已经给出的边，然后整个MST-已给出的边的长度和=答案
为什么我们不忽略这些已知边去求最小生成树而是必须要用上这些边求出的结果
是最优解。其正确性是可以证明的：
假设给定的是一条边e，连接a、b，在求出的最小生成树T中，先假定没有这条边，那么a
和b分别在两个连通分量A和B里，那么连接A和B只有用e这条边最优（因为加这条边不
花钱），如果加别的边连连接A和B的话，那么怕比e小也要有花费的。
多条边也是这样。
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn=110;
int vis[maxn][maxn],n,q;

struct pp{
    int a,b,v;
}s[maxn*maxn];

int cmp(const pp &x,const pp &y){
    return x.v<y.v;
}

typedef struct UFSet{
    int par[maxn];
    void Init(){ for(int i=0;i<maxn;i++) par[i]=i; }
    int Find(int x){ return x==par[x]?x:par[x]=Find(par[x]);}
    bool Union(int u,int v){
        if((u=Find(u))==(v=Find(v))) return false;
        par[v]=u;
        return true;
    }
}UFSet;

UFSet ss;
int cnt,tot;

void Kruskal_Input(){
    int i,j;
    scanf("%d",&n);
    ss.Init();
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&vis[i][j]);
    for(i=1;i<=n;i++)
        for(j=1;j<i;j++){
            s[tot].a=i;s[tot].b=j;s[tot++].v=vis[i][j];
        }
    scanf("%d",&q);
    cnt=0;
    while(q--){
        int x,y;
        scanf("%d%d",&x,&y);
        if(ss.Union(x,y))
            cnt++;
    }
    sort(s,s+tot,cmp);
}

int Kruskal(){
    int i,j,TreeLong=0;
    for(i=0;i<tot;i++){
        if(ss.Union(s[i].a,s[i].b)){
            TreeLong+=s[i].v;
            if(++cnt==n-1) break;
        }
    }
    return TreeLong;
}

int main()
{
    Kruskal_Input();
    printf("%d\n",Kruskal());
    return 0;
}
