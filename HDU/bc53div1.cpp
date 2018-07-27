/****************
*ID:bc53
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=1000+10;
int vis[maxn];
vector<int> mp[maxn];
bool yes;
int deep,first;

void dfs(int cur,int v){
    if(!yes) return ;
    int i,flag=0;
    vis[v]=1;
    for(i=0;i<mp[v].size();i++){
        int x=mp[v][i];
        if(vis[x]==0){
            vis[x]=1;
            dfs(cur+1,x);
            vis[x]=0;
            flag=1;
        }
    }
    if(flag==0){
        if(first==0){
            deep=cur;
            first=1;
        }
        else if(cur!=deep){
            yes=false;
            return ;
        }
    }
}

int main()
{
    int i,j,k,n,m,T,kcase=1;
    while(scanf("%d",&n)!=EOF){
        memset(vis,0,sizeof(vis));
        for(i=0;i<=n;i++)
            mp[i].clear();
        int u,v;
        int cnt=0;
        for(i=1;i<n;i++){
            scanf("%d%d",&u,&v);
            mp[u].push_back(v);
            mp[v].push_back(u);
          //  if(u==1 || v==1) cnt++;
        }
        yes=true;
        first=0;
        dfs(1,1);
        if(yes)
            printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}

