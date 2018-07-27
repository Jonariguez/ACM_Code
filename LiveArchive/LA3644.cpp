#include <stdio.h>
#include <string.h>

const int maxn=100000+10;

struct UFSet{
    int par[maxn];
    void Init(){for(int i=0;i<maxn;i++) par[i]=i;}
    int Find(int x){
        return x==par[x]?x:par[x]=Find(par[x]);
    }
    bool Union(int u,int v){
        if((u=Find(u))==(v=Find(v)))
            return true;
        par[u]=v;
        return false;
    }
}s;

int main()
{
    int res,a,b;
    while(scanf("%d",&a)!=EOF){
        s.Init();
        res=0;
        while(a!=-1){
            scanf("%d",&b);
            if(s.Union(a,b)) res++;
            scanf("%d",&a);
        }
        printf("%d\n",res);
    }
    return 0;
}
