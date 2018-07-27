/****************
*PID:spoj104
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
const int maxn=100+10;
const int maxm=100000+10;
const int INF=1e9;

int deg[maxn],n,m;
LL g[maxn][maxn];

LL det(){
    LL res=1;
    int i,j;
    for(i=1;i<n;i++){
        for(j=i+1;j<n;j++){
            while(g[j][i]){
                LL t=g[i][i]/g[j][i];
                for(int k=i;k<n;k++)
                    g[i][k]=(g[i][k]-g[j][k]*t);
                for(int k=i;k<n;k++)
                    swap(g[i][k],g[j][k]);
                res=-res;
            }
        }
        if(g[i][i]==0) return 0LL;
        res*=g[i][i];
    }
    if(res<0) res=-res;
    return res;
}

int main()
{
    int i,j,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        int u,v;
        memset(deg,0,sizeof(deg));
        memset(g,0,sizeof(g));
        while(m--){
            scanf("%d%d",&u,&v);
            u--;v--;
            g[u][v]=g[v][u]=-1;
            deg[v]++;
            deg[u]++;
        }
        for(i=0;i<n;i++)
            g[i][i]=deg[i];
        printf("%lld\n",det());
    }
    return 0;
}
