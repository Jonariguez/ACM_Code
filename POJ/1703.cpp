/*
带权并查集(基本上同POJ2492)
*/
#include <stdio.h>
#include <string.h>
#include <math.h>

const int maxn=100000+10;
int vis[maxn];

typedef struct UFSet{
    int par[maxn],rel[maxn];
    void Init(int n){ for(int i=0;i<=n;i++) par[i]=i,rel[i]=0;}
    int Find(int x){
        if(par[x]==x) return x;
        int t=Find(par[x]);
        rel[x]=rel[x]^rel[par[x]];
        return par[x]=t;
    }
    bool Union(int u,int v){
        int pu=Find(u),pv=Find(v);
        if(pu==pv) return rel[u]==rel[v];
        rel[pv]=!(rel[u]^rel[v]);
        par[pv]=pu;
        return false;
    }
}UFSet;

int main()
{
    int i,j,k,T,n,m;
    char op[2];
    scanf("%d",&T);
    UFSet s;
    while(T--){
        scanf("%d%d",&n,&m);
        s.Init(n);
        memset(vis,0,sizeof(vis));
        while(m--){
            int a,b;
            scanf("%s%d%d",op,&a,&b);
            if(op[0]=='D')
                s.Union(a,b);
            else{
                int pa=s.Find(a),pb=s.Find(b);
                if(vis[a]==0 || vis[b]==0 || pa!=pb)        //注意这里，当pa!=pb时也是不确定的一种情况
                    printf("Not sure yet.\n");
                else if(s.rel[a]==s.rel[b])
                    printf("In the same gang.\n");
                else
                    printf("In different gangs.\n");
            }
            vis[a]=1;vis[b]=1;
        }
    }
    return 0;
}

