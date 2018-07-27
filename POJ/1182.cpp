/*
POJ第100题
*/
#include <stdio.h>
#include <string.h>

const int maxn=50000+10;

typedef struct UFSet{
    int par[maxn],rel[maxn];
    void Init(int n){ for(int i=0;i<=n;i++) par[i]=i,rel[i]=0;}
    int Find(int x){
        if(par[x]==x) return x;
        int t=Find(par[x]);
        rel[x]=(rel[x]+rel[par[x]])%3;
        return par[x]=t;
    }
    void Union(int u,int v,int pu,int pv,int d){
        rel[pu]=(rel[v]-rel[u]+2+d)%3;      //注意这里，到底是pu，pv，不要混淆.   我发现合并时rel[pu]由rel[u],rel[v]共同决定
        par[pu]=pv;                         //那是那么为什么能决定呢？pv和v有关系，pu和u有关系，而u和v又有关系，所以u，v就能决定
                                            //pu和pv的关系，即rel[pu]
    }
}UFSet;

int main()
{
    int i,j,k,n,a,b,pa,pb,d;
    scanf("%d%d",&n,&k);
    UFSet s;
    s.Init(n);
    int res=0;
    while(k--){
        scanf("%d%d%d",&d,&a,&b);
        if(a>n || b>n || a==b && d==2){ res++;continue;}
        pa=s.Find(a);pb=s.Find(b);
        if(pa!=pb)
            s.Union(a,b,pa,pb,d);
        else if((s.rel[b]+d+2)%3!=s.rel[a]) res++;
    }
    printf("%d\n",res);
    return 0;
}
