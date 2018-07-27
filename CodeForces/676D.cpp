/****************
*PID:676d div2
*Auth:Jonariguez
*****************
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

const int maxn=1000+10;
const int INF=0x3f3f3f3f;
char str[maxn][maxn];
int d[4][2]={{0,1},{-1,0},{0,-1},{1,0}};//右，上，左，下
bool c[maxn][maxn][4];
int dis[maxn][maxn][4],n,m;

void bfs(int sx,int sy){
    memset(dis,INF,sizeof(dis));
    queue<int> qx,qy,qd;
    dis[sx][sy][0]=0;
    qx.push(sx);
    qy.push(sy);
    qd.push(0);
    while(!qx.empty()){
        int ux=qx.front();qx.pop();
        int uy=qy.front();qy.pop();
        int ud=qd.front();qd.pop();
        if(dis[ux][uy][ud]+1<dis[ux][uy][(ud+1)%4]){ //旋转
            dis[ux][uy][(ud+1)%4]=dis[ux][uy][ud]+1;
            qx.push(ux);qy.push(uy);
            qd.push((ud+1)%4);
        }
        for(int i=0;i<4;i++){
            int tx=ux+d[i][0];
            int ty=uy+d[i][1];
            if(tx>=0 && tx<n && ty>=0 && ty<m && c[ux][uy][(i+ud)%4] && c[tx][ty][(i+ud+2)%4]){
                if(dis[tx][ty][ud]>dis[ux][uy][ud]+1){
                    dis[tx][ty][ud]=dis[ux][uy][ud]+1;
                    qx.push(tx);qy.push(ty);
                    qd.push(ud);
                }
            }
        }
    }
}

int main()
{
    int i,j;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
        scanf("%s",str[i]);
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            char t=str[i][j];
            if(t=='+' || t=='-' || t=='>' || t=='U' || t=='L' || t=='D') c[i][j][0]=1;  //右
            if(t=='+' || t=='|' || t=='^' || t=='R' || t=='L' || t=='D') c[i][j][1]=1;  //上
            if(t=='+' || t=='-' || t=='<' || t=='R' || t=='U' || t=='D') c[i][j][2]=1;  //左
            if(t=='+' || t=='|' || t=='v' || t=='R' || t=='U' || t=='L') c[i][j][3]=1;  //下
        }
    }
    int st[2],en[2];
    for(i=0;i<2;i++){
        scanf("%d",&st[i]);
        st[i]--;
    }
    for(i=0;i<2;i++){
        scanf("%d",&en[i]);
        en[i]--;
    }
    bfs(st[0],st[1]);
    int res=INF;
    for(i=0;i<4;i++)
        res=min(res,dis[en[0]][en[1]][i]);
    if(res==INF)
        res=-1;
    pfn(res);
    return 0;
}





