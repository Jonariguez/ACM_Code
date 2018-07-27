/*
用并查集优化，还是挺好玩的。
注意并查集初始化时用a[i].d的最大值而不是n
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn=10000+10;

struct Sell{
    int p,d;
}a[maxn];

typedef struct UFSet{
    int par[maxn];
    void Init(int n){
        for(int i=0;i<=n;i++) par[i]=i;
    }
    int Find(int x){return par[x]==x?x:par[x]=Find(par[x]);}
    void Union(int u,int v){
        if((u=Find(u))==(v=Find(v)))
            return ;
        par[v]=u;
    }
}UFSet;

int cmp(const Sell &x,const Sell &y){
 //   if(x.p==y.p) return x.d>y.d;
    return x.p>y.p;
}

int main()
{
    UFSet s;
    int i,j,n;
    while(scanf("%d",&n)!=EOF){
        int maxv=-1;
        for(i=0;i<n;i++){
            scanf("%d%d",&a[i].p,&a[i].d);
            maxv=max(maxv,a[i].d);
        }
        sort(a,a+n,cmp);
        s.Init(maxv);
        int res=0;
        for(i=0;i<n;i++){
            int t=s.Find(a[i].d);
            if(t>0){
                res+=a[i].p;
                s.Union(t-1,a[i].d);
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
