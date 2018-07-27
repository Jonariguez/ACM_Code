/*
最大权森林：边权取反+Kruskal()最小生成树
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn=10000*2+10;
int n,m,r,tot;
struct pp{
    int a,b,v;
}s[50000+5];
int cmp(const pp &x,const pp &y){ return x.v<y.v;	}
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
void Kruskal_Input(){
    int i,f,t,v;
    scanf("%d%d%d",&n,&m,&r);
    for(i=0;i<r;i++){
        scanf("%d%d%d",&s[i].a,&s[i].b,&s[i].v);
        s[i].b+=n;
        s[i].v=-s[i].v;
    }
    sort(s,s+r,cmp);
}
int Kruskal(){
    int TreeLong=0,i;
    UFSet ss; ss.Init();
    for(i=0;i<r;i++){
        if(ss.Union(s[i].a,s[i].b))
            TreeLong+=s[i].v;		//不联通的，那么就要在各个子图上求MST，此时只需去掉
    }					//cnt计数即可(即对所有的边都判断)
    return TreeLong;
}

int main()
{
    int i,T;
    scanf("%d",&T);
    while(T--){
         Kruskal_Input();
         printf("%d\n",10000*(n+m)+Kruskal());
    }
    return 0;
}
