#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;

const int maxn=20000+10;

typedef struct WUFSet{
    int par[maxn],dis[maxn];
    void Init(int n){
        for(int i=0;i<=n;i++){
            par[i]=i;dis[i]=0;
        }
    }
    int Find(int x){
        if(x==par[x]) return x;
        int y=Find(par[x]);
        dis[x]+=dis[par[x]];
        return par[x]=y;
    }
    void Union(int u,int v){
        dis[u]=(int)fabs(u-v)%1000;
        par[u]=v;
    }
}WUFSet;

int main()
{
    int i,T,n,x,y;
    char p[5];
    WUFSet s;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        s.Init(n);
        while(scanf("%s",p)){
            if(p[0]=='O') break;
            if(p[0]=='I'){
                scanf("%d%d",&x,&y);
                s.Union(x,y);
            }else {
                scanf("%d",&x);
                s.Find(x);
                printf("%d\n",s.dis[x]);
            }
        }
    }
    return 0;
}

/*
void Init(int n){
    for(int i=0;i<=n;i++) par[i]=i,rel[i]=0;}
