/****************
*PID:hdu1875
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn=100+5;
const int maxm=1000+5;
int par[maxn],x[maxn],y[maxn],n,m,tot;
vector<int> res;

struct pp{
    int a,b;
    double w;
}s[maxn*maxn];

int cmp(const pp &x,const pp &y){
    return x.w<y.w;
}

int find(int x){
    return x==par[x]?x:par[x]=find(par[x]);
}

bool merge(int u,int v){
    if((u=find(u))==(v=find(v))) return false;
    par[u]=v;
    return true;
}

int dis(int i,int j){
    return (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
}

int main()
{
    int i,j,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d%d",&x[i],&y[i]);
            par[i]=i;
        }
        int yes=1;
        m=0;
        for(i=1;i<=n;i++)
            for(j=1;j<i;j++){
                s[m].a=i;s[m].b=j;
                s[m].w=sqrt((double)dis(i,j));
                if(dis(i,j)<100 || dis(i,j)>1000000) continue;
                m++;
            }
        sort(s,s+m,cmp);
        int cnt=0;
        double res=0;
        for(i=0;i<m;i++){
            if(merge(s[i].a,s[i].b)){
                res+=s[i].w;
                if(++cnt==n-1) break;
            }
        }
        if(cnt!=n-1)
            puts("oh!");
        else printf("%.1f\n",res*100);
    }
    return 0;
}
