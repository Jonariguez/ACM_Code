/****************
*PID:uva10054
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=50;
int G[maxn+1][maxn+1],deg[maxn+1];
struct Edge{
    int from,to;
    Edge(int from=0,int to=0):from(from),to(to){}
};
vector<Edge> res;

void Euler(int u){
    for(int i=1;i<=maxn;i++){
        if(G[u][i]){
            G[u][i]--;G[i][u]--;
            Euler(i);
            res.push_back(Edge(u,i));
        }
    }
}

int main()
{
    int i,j,n,T,kcase=1;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        memset(G,0,sizeof(G));
        memset(deg,0,sizeof(deg));
        int u,v,start=-1;
        for(i=1;i<=n;i++){
            scanf("%d%d",&u,&v);
            deg[u]++;deg[v]++;
            G[u][v]++;G[v][u]++;
            start=u;
        }
        int yes=1;
        for(i=1;i<=maxn;i++){
            if(deg[i]&1){
                yes=0;break;
            }
        }
        if(yes){
            res.clear();
            Euler(start);
            if(res.size()!=n || res[0].to!=res[res.size()-1].from)
                yes=0;
        }
        printf("Case #%d\n", kcase++);
        if(yes==0)
            printf("some beads may be lost\n");
        else for(i=0;i<res.size();i++)
                printf("%d %d\n",res[i].to,res[i].from);
        if(T)
            puts("");
    }
    return 0;
}
