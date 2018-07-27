/****************
*PID:POJ2031
*Auth:Jonariguez
*****************
距离为点心距-两个球的半径，重叠的或者接触的
距离为0
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn=100+10;

double x[maxn],y[maxn],z[maxn],r[maxn];
int n,m,par[maxn];

struct Edge{
    double w;
    int a,b;
}s[maxn*maxn];

int cmp(const Edge &x,const Edge &y){
    return x.w<y.w;
}

double dis(int i,int j){
    return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])+(z[i]-z[j])*(z[i]-z[j]));
}

int find(int x){
    return x==par[x]?x:par[x]=find(par[x]);
}

bool merge(int u,int v){
    if((u=find(u))==(v=find(v))) return false;
    par[u]=v;
    return true;
}

int main()
{
    int i,j;
    while(scanf("%d",&n),n){
        for(i=1;i<=n;i++)
            scanf("%lf%lf%lf%lf",&x[i],&y[i],&z[i],&r[i]);
        m=0;
        for(i=1;i<=n;i++){
            for(j=1;j<i;j++){
                s[m].a=i;s[m].b=j;
                s[m++].w=max(dis(i,j)-r[i]-r[j],(double)0);
            }
        }
        sort(s,s+m,cmp);
        for(i=0;i<=n;i++) par[i]=i;
        int cnt=0;
        double res=0;
        for(i=0;i<m;i++){
            if(merge(s[i].a,s[i].b)){
                res+=s[i].w;
                if(++cnt==n-1)
                    break;
            }
        }
        printf("%.3f\n",res);
    }
    return 0;
}


