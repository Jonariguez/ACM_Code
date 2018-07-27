/****************
*PID:poj3669
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;

const int maxn=50000+10;
const int maxw=300+10;
const int INF=1000+10;
int a[maxw][maxw],vis[maxw][maxw];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

struct Point{
    int x,y;
};

int bfs(){
    Point u;
    int i;
    u.x=0;u.y=0;
    vis[0][0]=0;
    queue<Point> que;
    que.push(u);
    while(!que.empty()){
        u=que.front();que.pop();
        if(a[u.x][u.y]==INF){
                return vis[u.x][u.y];
        }
        for(i=0;i<4;i++){
            int x=u.x+dx[i],y=u.y+dy[i];
            int now=vis[u.x][u.y]+1;
            if(x<0 || y<0 || vis[x][y]>=0 || a[x][y]<=now) continue;
            vis[x][y]=now;
            Point t;
            t.x=x;t.y=y;
            que.push(t);
        }
    }
    return -1;
}


int main()
{
    int i,j,n,x,y,t;
    for(i=0;i<maxw;i++)
        for(j=0;j<maxw;j++)
            a[i][j]=INF;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d%d%d",&x,&y,&t);
        a[x][y]=min(a[x][y],t);
        if(x-1>=0)
            a[x-1][y]=min(a[x-1][y],t);
        a[x+1][y]=min(a[x+1][y],t);
        if(y-1>=0)
            a[x][y-1]=min(a[x][y-1],t);
        a[x][y+1]=min(a[x][y+1],t);
    }
    memset(vis,-1,sizeof(vis));
    printf("%d\n",bfs());
    return 0;
}
