/****************
*PID:515d div2
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

const int maxn=2000+10;
char str[maxn][maxn];
int deg[maxn][maxn],n,m;
int dx[4]={0,1,0,-1};   //right,down,left,up
int dy[4]={1,0,-1,0};

struct node{
    int x,y;
};
queue<node> que;

int isPoint(int x,int y){
    if(x>=1 && x<=n && y>=1 && y<=m && str[x][y]=='.') return 1;
    return 0;
}

int cal(int x,int y){
    int cnt=0;
    for(int i=0;i<4;i++){
        int xx=x+dx[i],yy=y+dy[i];
        cnt+=isPoint(xx,yy);
    }
    return cnt;
}

void update(int x,int y){
    for(int i=0;i<4;i++){
        int xx=x+dx[i],yy=y+dy[i];
        if(isPoint(xx,yy)){
            deg[xx][yy]=cal(xx,yy);
            if(deg[xx][yy]==1){
                node u;
                u.x=xx;u.y=yy;
                que.push(u);
            }
        }
    }
}

void solve(){
    node u;
    memset(deg,0,sizeof(deg));
    while(!que.empty()) que.pop();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(isPoint(i,j)){
                deg[i][j]=cal(i,j);
                if(deg[i][j]==1){
                    u.x=i;u.y=j;
                    que.push(u);
                }
            }
        }
    }
    while(!que.empty()){
        u=que.front();que.pop();
        for(int i=0;i<4;i++){
            int x=u.x+dx[i],y=u.y+dy[i];
            if(isPoint(x,y)){
                if(i==0) str[u.x][u.y]='<',str[x][y]='>';
                if(i==1) str[u.x][u.y]='^',str[x][y]='v';
                if(i==2) str[u.x][u.y]='>',str[x][y]='<';
                if(i==3) str[u.x][u.y]='v',str[x][y]='^';
                update(u.x,u.y);update(x,y);
                break;
            }
        }
    }
}

bool check(){
    int i,j;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
             if(str[i][j]=='.') return false;
    return true;
}

int main()
{
    int i,j;
    while(scanf("%d%d",&n,&m)!=EOF){
        for(i=1;i<=n;i++)
            scanf("%s",str[i]+1);
        solve();
        if(check()){
            for(i=1;i<=n;i++){
                printf("%s\n",str[i]+1);
            }
        }else printf("Not unique\n");
    }
    return 0;
}
