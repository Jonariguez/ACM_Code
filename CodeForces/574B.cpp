/****************
*PID:574b div2
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=4000+10;
bool vis[maxn][maxn];
int deg[maxn];

struct Edge{
    int f,t;
}e[maxn];

int main()
{
    int i,j,n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        int a,b;
        memset(deg,0,sizeof(deg));
        memset(vis,0,sizeof(vis));
        for(i=1;i<=m;i++){
            scanf("%d%d",&a,&b);
            vis[a][b]=vis[b][a]=1;
            deg[a]++;deg[b]++;
            e[i].f=a;e[i].t=b;
        }
        int sum=1e9;
        for(i=1;i<=m;i++){
            a=e[i].f;b=e[i].t;
            for(j=1;j<=n;j++){
                if(j!=a && j!=b && vis[a][j] && vis[b][j])
                    sum=min(sum,deg[a]+deg[b]+deg[j]);
            }
        }
        if(sum==1e9)
            sum=5;
        printf("%d\n",sum-6);
    }
    return 0;
}
