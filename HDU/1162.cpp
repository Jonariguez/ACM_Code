#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;

const int maxn=2000+10;
const int maxm=10000+10;
int n,m,tot;
struct pp{
    double a,b,v;
}s[maxm];

int cmp(const pp &x,const pp &y){ return x.v<y.v;	}

double dis(double x1,double y1,double x2,double y2){
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
    double x[110],y[110];
    for(i=0;i<n;i++)
        scanf("%lf%lf",&x[i],&y[i]);
    m=0;
    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++){
            s[m].a=i;s[m].b=j;s[m++].v=dis(x[i],y[i],x[j],y[j]);
        }
    sort(s,s+m,cmp);
}
double Kruskal(){
    double TreeLong=0;
    int i,cnt=0;
    UFSet ss; ss.Init();
    for(i=0;i<m;i++){
        if(ss.Union(s[i].a,s[i].b)){
            TreeLong+=s[i].v;
            if(++cnt==n-1) break;		//这里默认整个图是联通的，如果是
        }				//不联通的，那么就要在各个子图上求MST，此时只需去掉
    }					//cnt计数即可(即对所有的边都判断)
  //  if(i==m) return -1;
    return TreeLong;
}

int main()
{
    int i;
    while(scanf("%d",&n)!=EOF){
        Kruskal_Input();
        printf("%.2f\n",Kruskal());
    }
    return 0;
}
