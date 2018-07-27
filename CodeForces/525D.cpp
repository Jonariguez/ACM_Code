/****************
*PID:525d div2
*Auth:Jonariguez
*****************
删walls基于这样一个事实：如果一个2*2的方格中，恰好只有一个'*'，
那么这个'*'就是该删的。
因为删掉之后可能导致原来不能删的wall，因为删掉这个而能删了，
所以要借助bfs
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=2000+5;
int a[maxn][maxn],n,m;
char str[maxn][maxn];

struct Node{
    int x,y;
};

bool inside(int x,int y){
    if(x<1 || x>n || y<1 || y>m) return false;
    return true;
}

int sum(int x,int y){
    return a[x][y]+a[x][y+1]+a[x+1][y]+a[x+1][y+1];
}

bool check(int x,int y){
    if(a[x][y]) return false;
    if(sum(x,y)==3 || sum(x-1,y)==3 || sum(x,y-1)==3 || sum(x-1,y-1)==3) return true;
    return false;
}

void bfs(){
    int i,j;
    queue<Node> que;
    Node u;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(!a[i][j] && check(i,j)){
                u.x=i;u.y=j;
                que.push(u);
            }
        }
    }
    while(!que.empty()){
        u=que.front();que.pop();
        a[u.x][u.y]=1;str[u.x][u.y]='.';
        for(i=u.x-1;i<=u.x+1;i++)
            for(j=u.y-1;j<=u.y+1;j++){
                if(!i && !j) continue;
                if(inside(i,j) && check(i,j)){
                    a[i][j]=1;str[i][j]='.';
                    Node t;
                    t.x=i;t.y=j;que.push(t);
                }
            }
    }
}

int main()
{
    int i,j;
    while(scanf("%d%d",&n,&m)!=EOF){
        memset(a,0,sizeof(a));
        for(i=1;i<=n;i++){
            scanf("%s",str[i]+1);
            for(j=1;j<=m;j++)
                if(str[i][j]=='.')
                    a[i][j]=1;
        }
        bfs();
        for(i=1;i<=n;i++)
            printf("%s\n",str[i]+1);
    }
    return 0;
}

