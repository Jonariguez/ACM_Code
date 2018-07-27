/****************
*PID:520b div2
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=20000+10;
int vis[maxn];

int bfs(int n,int m){
    queue<int> que;
    memset(vis,-1,sizeof(vis));
    vis[n]=0;
    que.push(n);
    while(!que.empty()){
        int u=que.front();que.pop();
        if(u==m) return vis[u];
        if(u<m && vis[u*2]==-1){
            que.push(u*2);vis[u*2]=vis[u]+1;
        }
        if(u>1 && vis[u-1]==-1){
            que.push(u-1);vis[u-1]=vis[u]+1;
        }
    }
}

int main()
{
    int i,j,n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        printf("%d\n",bfs(n,m));
    }
    return 0;
}
