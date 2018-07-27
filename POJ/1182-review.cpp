#include <stdio.h>
#include <string.h>

const int maxn=50000+10;

typedef struct WUFSet{
    int par[maxn],rel[maxn];    //0:同类 1:吃祖先 2:被祖先吃
    void init(int n){
        for(int i=0;i<=n;i++){
            par[i]=i;rel[i]=0;
        }
    }
    int Find(int x){
        if(par[x]==x)
            return x;
        int y=Find(par[x]);
        rel[x]=(rel[x]+rel[par[x]])%3;
        return par[x]=y;
    }
    bool Union(int u,int v,int D){
        int pu=Find(u),pv=Find(v);
        if(pu==pv)
            return (rel[v]+2+D)%3!=rel[u];
        rel[pu]=(rel[v]-rel[u]+2+D)%3;
        par[pu]=pv;
        return false;
    }
}WUFSet;

int main()
{
    int i,n,m,res,D,a,b;
    scanf("%d%d",&n,&m);
    WUFSet s;
    s.init(n);
    res=0;
    while(m--){
        scanf("%d%d%d",&D,&a,&b);
        if(a>n || b>n || D==2 && a==b){
            res++;continue;
        }
        if(s.Union(a,b,D))
            res++;
    }
    printf("%d\n",res);
    return 0;
}
