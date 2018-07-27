/****************
*PID:hdu4858
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=100000+10;
int n,m;
vector<int> G[maxn];
int sum[maxn];

int main()
{
    int i,j,q,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(i=0;i<=n;i++) G[i].clear();
        for(i=0;i<m;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            G[a].push_back(b);
            G[b].push_back(a);
        }
        scanf("%d",&q);
        memset(sum,0,sizeof(sum));
        int cmd,u,v;
        while(q--){
            scanf("%d",&cmd);
            if(cmd){
                scanf("%d",&u);
                printf("%d\n",sum[u]);
            }else {
                scanf("%d%d",&u,&v);
                for(i=0;i<G[u].size();i++)
                    sum[G[u][i]]+=v;
            }
        }
    }
    return 0;
}
