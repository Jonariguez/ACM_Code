/*
MST-Kruskal
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long ll;

const int maxn=2000+10;
const int maxm=10000+10;

int n,m,tot;

struct pp{
    int a,b,v;
}s[maxm];

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

void Kruskal_Input(){
    int i;
    for(i=0;i<m;i++)
        scanf("%d%d%d",&s[i].a,&s[i].b,&s[i].v);
    sort(s,s+m,cmp);
}

int Kruskal(){
    int longE=-1,i,cnt=0;
    UFSet ss;
    ss.Init();
    for(i=0;i<m;i++){
        if(ss.Union(s[i].a,s[i].b)){
            longE=max(longE,s[i].v);
            if(++cnt==n-1) break;
        }
    }
    return longE;
}

int main()
{
    int i;
    scanf("%d%d",&n,&m);
    Kruskal_Input();
    printf("%d\n",Kruskal());
    return 0;
}
