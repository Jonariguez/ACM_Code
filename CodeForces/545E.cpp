#include <stdio.h>
#include <string.h>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
typedef __int64 ll;

const int maxn=300000+10;
const int maxm=300000+10;
int n,m,tot;
struct pp{
    int a,b,v,id;
}s[maxm];
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

ll Kruskal(){
    ll TreeLong=0,i,cnt=0;
    UFSet ss; ss.Init();

    return 0;
}
