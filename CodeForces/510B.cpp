/****************
*PID:510b div2
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

const int maxn=50+10;
char str[maxn][maxn];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int n,m,vis[maxn][maxn];
bool yes;

struct node{
    int x,y;
};

void dfs(int x,int y,int cnt){
    if(yes) return ;
    int i;
    for(i=0;i<4;i++){
        int xx=x+dx[i],yy=y+dy[i];
        if(xx<1 || xx>n || yy<1 || yy>m || str[xx][yy]!=str[x][y]) continue;
        if(vis[xx][yy] && vis[xx][yy]!=vis[x][y]-1 && cnt>=4){
            yes=true;return ;
        }
        if(vis[xx][yy]==0){
            vis[xx][yy]=1+vis[x][y];dfs(xx,yy,cnt+1);//vis[xx][yy]=0;
        }
    }
}

int main()
{
    int i,j;
    while(scanf("%d%d",&n,&m)!=EOF){
        for(i=1;i<=n;i++)
            scanf("%s",str[i]+1);
        yes=false;
        memset(vis,0,sizeof(vis));
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                if(vis[i][j]==0){
                    yes=false;
                    vis[i][j]=1;
                    dfs(i,j,1);
                    if(yes) break;
                }
            }
            if(yes) break;
        }
        if(yes)
            printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
