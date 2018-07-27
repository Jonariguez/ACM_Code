/****************
*PID:585D div2
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

const int maxn=100+10;
char str[4][maxn];
bool vis[4][maxn];
int n;

struct Point{
    int x,y;
};

int up(int x){
    return x-1;
}

int down(int x){
    if(x==3) return 0;
    return x+1;
}

bool bfs(int s){
    if(str[s][2]!='.') return false;
    memset(vis,0,sizeof(vis));
    queue<Point> que;
    int i,j,k;
    Point t;
    t.x=s;t.y=1;
    vis[t.x][t.y]=1;
    que.push(t);
    while(!que.empty()){
        Point u=que.front();que.pop();
        if(u.y>=n) return true;
        if(str[u.x][u.y+1]!='.') continue;
        u.y++;                  //向右走一步
        int y=u.y;
        for(i=-1;i<=1;i++){
            int x=u.x+i;
            if(x<=0 || x>3 || str[x][y]!='.'|| vis[x][y]==1) continue;
            if(str[x][y+1]=='.' && str[x][y+2]=='.'){
                vis[x][y+1]=vis[x][y+2]=1;
                t.x=x;t.y=y+2;vis[t.x][t.y]=1;
                que.push(t);`
            }
        }
    }
    return false;
}

int main()
{
    int i,j,k,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&k);
        for(i=1;i<=3;i++){
            scanf("%s",str[i]+1);
            str[i][n+1]='.';
        }
        for(i=1;i<=3;i++)
            if(str[i][1]=='s') break;
        if(bfs(i))
            printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
