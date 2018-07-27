/****************
*PID:la5713
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=1000+10;
int x[maxn],y[maxn],p[maxn],par[maxn];
double maxcost[maxn][maxn];
vector<int> G[maxn],g;
struct pp{
    int a,b;
    double w;
}s[maxn*maxn];

int cmp(const pp &x,const pp &y){
    return x.w<y.w;
}

void Init(int n){
    for(int i=1;i<=n;i++){
        par[i]=i;G[i].clear();
    }
    g.clear();
    memset(maxcost,0,sizeof(maxcost));
}

int find(int x){
    return x==par[x]?x:par[x]=find(par[x]);
}

bool Union(int u,int v){
    if((u=find(u))==(v=find(v))) return false;
    par[u]=v;
    return true;
}

double dis(int i,int j){
    if(i==0 || j==0) return 0;
    return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
}

void dfs(int u,int pa){
    int i,v;
   // if(pa>0)
    for(i=0;i<g.size();i++){
        v=g[i];
        maxcost[u][v]=maxcost[v][u]=max(maxcost[v][pa],dis(u,pa));
    }
    g.push_back(u);
    for(i=0;i<G[u].size();i++){
        v=G[u][i];
        if(v==pa) continue;
        dfs(v,u);
    }
}

int main()
{
    int i,j,T,n,m;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%d%d%d",&x[i],&y[i],&p[i]);
        m=0;
        for(i=1;i<=n;i++){
            for(j=i+1;j<=n;j++){
                s[++m].a=i;s[m].b=j;
                s[m].w=dis(i,j);
            }
        }
        Init(n);
        sort(s+1,s+m+1,cmp);
        double sum=0;
        int cnt=0;
        for(i=1;i<=m;i++){
            if(Union(s[i].a,s[i].b)){
                int a=s[i].a,b=s[i].b;
                sum+=s[i].w;
                G[a].push_back(b);G[b].push_back(a);
                if(++cnt==n-1) break;
            }
        }
        dfs(1,0);
        double res=-1;
       // printf("sum=%.2f\n",sum);
        for(i=1;i<=n;i++){
            for(j=i+1;j<=n;j++){
                res=max(res,(double)(p[i]+p[j])/(sum-maxcost[i][j]));
            }
        }
        printf("%.2lf\n",res);
    }
    return 0;
}
