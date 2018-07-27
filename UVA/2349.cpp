#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;

const int maxn=500+10;
const int maxm=10000+10;
int n,m,tot;
int x[maxn],y[maxn];
double res[maxn];

struct pp{
    int a,b;
    double v;
}s[maxn*maxn];

int cmp(const pp &x,const pp &y){ return x.v<y.v;	}

double dis(int x1,int y1,int x2,int y2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
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
    int i,j;
    tot=0;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++) scanf("%d%d",&x[i],&y[i]);
    for(i=1;i<m;i++)
        for(j=i+1;j<=m;j++){
            s[tot].a=i;s[tot].b=j;s[tot++].v=dis(x[i],y[i],x[j],y[j]);
        }
    sort(s,s+tot,cmp);
}

int cmp1(double x,double y){
    return x>y;
}

double Kruskal(){
    int i,cnt=0;
    UFSet ss; ss.Init();
    for(i=0;i<tot;i++){
        if(ss.Union(s[i].a,s[i].b)){
            res[cnt++]=s[i].v;
            if(cnt==m-1) break;
        }
    }
  //  sort(res,res+m-1,cmp1);
    return res[m-n-1];    //这里注意一下
}

int main()
{
    int i,T;
    scanf("%d",&T);
    while(T--){
        Kruskal_Input();

        printf("%.2f\n",Kruskal());
    }
    return 0;
}
