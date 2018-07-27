/****************
*PID:poj1643
*Auth:Jonariguez
*****************
树形dp
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=1500+10;
vector<int> son[maxn];
int dp[maxn][2];

int dfs(int u,int flag){
    if(son[u].size()==0){   //叶子节点
        dp[u][flag]=flag;return flag;
    }
    if(dp[u][flag]>=0) return dp[u][flag];
    int& ans=dp[u][flag];
    ans=0;
    int i,j;
    if(flag){
        for(i=0;i<son[u].size();i++){
            int v=son[u][i];
            ans+=min(dfs(v,0),dfs(v,1));
        }
        ans++;
    }else {
        for(i=0;i<son[u].size();i++){
            int v=son[u][i];
            ans+=dfs(v,1);
        }
    }
    return ans;
}

int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF){
        for(i=0;i<n;i++)
            son[i].clear();
        int u,k,x,root=-1;
        for(i=0;i<n;i++){
            scanf("%d:(%d)",&u,&k);
            if(root==-1) root=u;
            while(k--){
                scanf("%d",&x);
                son[u].push_back(x);
                if(x==root) root=u;
            }
        }
        memset(dp,-1,sizeof(dp));
        printf("%d\n",min(dfs(root,1),dfs(root,0)));
    }
    return 0;
}
