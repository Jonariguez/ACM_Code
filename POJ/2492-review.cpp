/*
带权并查集
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn=2000+10;

typedef struct WUFSet{
    int par[maxn],rel[maxn];    //0同性，1异性
    void init(int n){
        for(int i=0;i<=n;i++){
            par[i]=i;rel[i]=0;
        }
    }
    int Find(int x){
        if(x==par[x]) return x;
        int y=Find(par[x]);
        rel[x]=rel[x]^rel[par[x]];
        return par[x]=y;
    }
    bool Union(int u,int v){    //返回true：同性；否则异性
        int pu=Find(u),pv=Find(v);
        if(pu==pv) return rel[u]==rel[v];   //如果在同一个集合里，那么两者与祖先的性别关系一样的话说明两者同性
        rel[pv]=!(rel[u]^rel[v]);
        par[pv]=pu;
        return false;
    }
}WUFSet;

int main()
{
    int i,T,n,m,kcase=1;
    WUFSet s;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        s.init(n);
        bool yes=true;
        while(m--){
            int a,b;
            scanf("%d%d",&a,&b);
            if(s.Union(a,b))
                yes=false;
        }
        printf("Scenario #%d:\n",kcase++);
        if(yes)
            printf("No suspicious bugs found!\n\n");
        else
            printf("Suspicious bugs found!\n\n");
    }
    return 0;
}
