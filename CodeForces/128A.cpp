/****************
*PID:128a div1
*Auth:Jonariguez
*****************
vis[t][x][y]:在t时刻是否(x,y)是否有S，
预处理处理就好了
*/
#define lson k*2,l,m
#define rson k*2+1,m+1,r
#define rep(i,s,e) for(i=(s);i<=(e);i++)
#define For(j,s,e) For(j=(s);j<(e);j++)
#define sc(x) scanf("%d",&x)
#define In(x) scanf("%I64d",&x)
#define pf(x) printf("%d",x)
#define pfn(x) printf("%d\n",(x))
#define Pf(x) printf("%I64d",(x))
#define Pfn(x) printf("%I64d\n",(x))
#define Pc printf(" ")
#define PY puts("YES")
#define PN puts("NO")
#include <stdio.h>
#include <string.h>
#include <string>
#include <math.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef int Ll;
Ll quick_pow(Ll a,Ll b,Ll MOD){a%=MOD;Ll res=1;while(b){if(b&1)res=(res*a)%MOD;b/=2;a=(a*a)%MOD;}return res;}

const int maxn=11;
char str[11][11];
int vis[maxn][maxn][maxn],d[maxn][maxn][maxn];
int dx[8]={0,1,0,-1,1,-1,1,-1};
int dy[8]={1,0,-1,0,-1,1,1,-1};

struct node{
    int x,y,step;
};

bool bfs(){
    node u;
    u.x=8;u.y=1;u.step=0;
    queue<node> que;
    que.push(u);
    memset(d,0,sizeof(d));
    d[0][8][1]=1;
    while(!que.empty()){
        u=que.front();que.pop();
        if(u.x==1) return true;
        for(int i=0;i<8;i++){
            int x=u.x+dx[i],y=u.y+dy[i];
            if(x<1 || x>8 || y<1 || y>8 || d[u.step+1][x][y]) continue;
            if(vis[u.step][x][y] || vis[u.step+1][x][y]) continue;
            node t;
            t.x=x;t.y=y;t.step=u.step+1;
            d[t.step][x][y]=1;
            que.push(t);
        }
        if(vis[u.step+1][u.x][u.y]==0){
            u.step++;
            que.push(u);    //选择不动
        }
    }
    return false;
}


int main()
{
    int i,j,n;
    for(i=1;i<=8;i++)
        scanf("%s",str[i]+1);
    memset(vis,0,sizeof(vis));
    for(i=1;i<=8;i++){
        for(j=1;j<=8;j++){
            if(str[i][j]=='S'){
                int now=0,x=i,y=j;
                for(;x<=8;x++){
                    vis[now][x][y]=1;
                    now++;
                }
            }
        }
    }
    if(bfs())
        puts("WIN");
    else puts("LOSE");
    return 0;
}



