#include <stdio.h>
#include <string.h>
#include <math.h>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=100+10;
struct pp{
    int f,t;
    double v;
}s[maxn*maxn];

int cmp(const pp &x,const pp &y){
    return x.v<y.v;
}

double dis(int x1,int y1,int x2,int y2){
    return sqrt((double)(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

typedef struct UFSet{
    int par[maxn];        //按秩合并应该会好一点
    void init(int n){for(int i=0;i<=n;i++) par[i]=i;}
    int Find(int x){ return par[x]==x?x:par[x]=Find(par[x]);}
    bool Union(int u,int v){
        if((u=Find(u))==(v=Find(v))) return false;
        par[u]=v;
        return true;
    }
}UFSet;

double x[maxn],y[maxn];

int main()
{
    int i,j,n,a,b;
    UFSet ss;
    scanf("%d",&n);
    ss.init(n);
    for(i=0;i<n;i++)
        scanf("%lf%lf",&x[i],&y[i]);
    int cnt=0;
    for(i=0;i<n-1;i++)
    for(j=i+1;j<n;j++){
        s[cnt].f=i;s[cnt].t=j;
        s[cnt++].v=dis(x[i],y[i],x[j],y[j]);
    }
    sort(s,s+cnt,cmp);
    double res=0;
    int tot=0;
    for(i=0;i<cnt;i++)
        if(ss.Union(s[i].f,s[i].t)){
            res+=s[i].v;
            if(++tot==n-1) break;
        }
    printf("%.2f\n",res);
    return 0;
}
