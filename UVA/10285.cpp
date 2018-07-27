/****************
*PID:uva10285
*Auth:Jonariguez
*****************
记忆化搜索
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=100+10;
int dp[maxn][maxn],a[maxn][maxn],n,m;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

int dfs(int x,int y){
    if(dp[x][y]>0) return dp[x][y];
    int i;
    for(i=0;i<4;i++){
        int xx=x+dx[i],yy=y+dy[i];
        if(xx<1 || xx>n || yy<1 || yy>m || a[xx][yy]>a[x][y]) continue;
        if(a[xx][yy]<a[x][y])   //这一句必须要有
            dp[x][y]=max(dp[x][y],dfs(xx,yy)+1);
    }
    return dp[x][y];
}

int main()
{
    int i,j,T;
    char name[110];
    scanf("%d",&T);
    while(T--){
        scanf("%s%d%d",name,&n,&m);
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
                scanf("%d",&a[i][j]);
        memset(dp,0,sizeof(dp));
        int res=1;
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                int t=dfs(i,j);
                if(res<t) res=t;
            }
        }
        printf("%s: %d\n",name,res+1);
    }
    return 0;
}
