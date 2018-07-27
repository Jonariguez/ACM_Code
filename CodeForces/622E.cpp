/****************
*PID:622e edu7
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn=500000+10;
vector<int> g[maxn],leaf;
int deep[maxn];

void dfs(int u,int pa){
    if(g[u].size()==1)  //р╤вс╫з╣Ц
        leaf.push_back(deep[u]);
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v==pa) continue;
        deep[v]=deep[u]+1;
        dfs(v,u);
    }
}

int main()
{
    int i,j,n,m;
    scanf("%d",&n);
    for(i=1;i<n;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int res=0;
    for(i=0;i<g[1].size();i++){
        int u=g[1][i];
        leaf.clear();
        deep[u]=1;
        dfs(u,1);
        sort(leaf.begin(),leaf.end());
        int temp=0;
        for(j=0;j<leaf.size();j++){
            int v=leaf[j];
            if(temp>=v)
                temp++;
            else temp=v;
        }
        res=max(res,temp);
    }
    printf("%d\n",res);
    return 0;
}
