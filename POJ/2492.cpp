/*
带权并查集
*/
#include <stdio.h>
#include <string.h>
#include <math.h>

const int maxn=2000+10;

typedef struct UFSet{
    int par[maxn],rel[maxn];
    void Init(int n){ for(int i=0;i<=n;i++) par[i]=i,rel[i]=0;}
    int Find(int x){
        if(par[x]==x) return x;
        int t=Find(par[x]);
        rel[x]=rel[x]^rel[par[x]];
        return par[x]=t;
    }
    bool Union(int u,int v){        //用返回值来确定是否同性，true为同性，false为异性
        int pu=Find(u),pv=Find(v);
        if(pu==pv) return rel[u]==rel[v];
        rel[pv]=!(rel[u]^rel[v]);          //如果不在一个集合里，那么他们一定不会出现同性恋，并且能构造出pu和pv的关系
        par[pv]=pu;                     //因为pu和u有关系(rel[u]),pv和v有关系(rel[v]),而u和v也一定该是异性的关系
        return false;                    //所以pu和pv的关系就能构造出来了
    }                                   //v->pv(rel[v]) u->pu(rel[u])   pv->pu(rel[pv])
}UFSet;                                 //       0          0               1
                                        //       0          1               0
                                        //       1          0               0
                                        //       1          1               1
int main()
{
    int i,T,kcase=1,n,q,flag;
    scanf("%d",&T);
    UFSet s;
    while(T--){
        scanf("%d%d",&n,&q);
        s.Init(n);
        flag=1;
        while(q--){
            int a,b;
            scanf("%d%d",&a,&b);
            if(s.Union(a,b))
                flag=0;
        }
        printf("Scenario #%d:\n",kcase++);
        if(flag)
            printf("No suspicious bugs found!\n\n");
        else
            printf("Suspicious bugs found!\n\n");
    }
    return 0;
}
