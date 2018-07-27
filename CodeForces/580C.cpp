/****************
*PID:cf580C
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
int vis[maxn],val[maxn],n,m,res;
vector<int> G[maxn];

void dfs(int u,int sum){
    if(sum>m) return ;
    int i,flag;
    if(val[u]==0) sum=0;
    else sum++;
    vis[u]=1;
    flag=0;
    for(i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(vis[v]==0){
            flag=1;
            dfs(v,sum);
        }
    }
    if(flag==0 && sum<=m)
        res++;
}

int main()
{
    int i,j;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%d",&val[i]);
    int a,b;
    for(i=0;i<n-1;i++){
        scanf("%d%d",&a,&b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(1,0);
    printf("%d\n",res);
    return 0;
}
