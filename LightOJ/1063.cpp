/****************
*PID:Light1063
*Auth:Jonariguez
*****************
¸îµã
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=10000+10;
vector<int> map[maxn];
int low[maxn],num[maxn],flag[maxn],n,dfs_seq,res;

void Tarjan(int cur,int fa){
    int i,chi=0;
    low[cur]=num[cur]=++dfs_seq;
    for(i=0;i<map[cur].size();i++){
        int u=map[cur][i];
        if(num[u]==0){
            chi++;
            Tarjan(u,cur);
            low[cur]=min(low[cur],low[u]);
            if((cur==1 && chi>1 || cur!=1 && low[u]>=num[cur]) && flag[cur]==0){
                res++;flag[cur]=1;
            }
        }else if(u!=fa)
            low[cur]=min(low[cur],num[u]);
    }
}

int main()
{
    int i,j,T,m,kcase=1;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(i=0;i<=n;i++)
            map[i].clear();
        fill(flag,flag+n+1,0);
        memset(num,0,sizeof(num));
        memset(low,0,sizeof(low));
        int a,b;
        for(i=0;i<m;i++){
            scanf("%d%d",&a,&b);
            map[a].push_back(b);
            map[b].push_back(a);
        }
        dfs_seq=res=0;
        Tarjan(1,1);
        printf("Case %d: %d\n",kcase++,res);
    }
    return 0;
}

