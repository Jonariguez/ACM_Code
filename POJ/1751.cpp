/****************
*PID:
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn=750+5;
const int maxm=1000+5;
int par[maxn],x[maxn],y[maxn],n,m,tot;
bool vis[maxn][maxn];
vector<int> res;

struct pp{
    int a,b,w;
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
    while(scanf("%d",&n)!=EOF){
        for(i=1;i<=n;i++){
            scanf("%d%d",&x[i],&y[i]);
            par[i]=i;
        }
        scanf("%d",&m);
        memset(vis,0,sizeof(vis));
        for(i=1;i<=m;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            vis[a][b]=vis[b][a]=1;
        }
        m=0;
        for(i=1;i<=n;i++)
            for(j=1;j<i;j++){
                s[m].a=i;s[m].b=j;
                s[m].w=dis(i,j);
                if(vis[i][j])
                    s[m].w=0;
                m++;
            }
        sort(s,s+m,cmp);
        int cnt=0;
        res.clear();
        for(i=0;i<m;i++){
            if(merge(s[i].a,s[i].b)){
                if(s[i].w){
                    res.push_back(s[i].a);
                    res.push_back(s[i].b);
                   // puts("???");
                }
                if(++cnt==n-1) break;
            }
        }
        for(i=0;i<res.size();i+=2)
            printf("%d %d\n",res[i],res[i+1]);
    }
    return 0;
}
