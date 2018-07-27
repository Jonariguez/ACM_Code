/****************
*PID:
*Auth:Jonariguez
*****************
*/
#define lson k*2,l,m
#define rson k*2+1,m+1,r
#define rep(i,s,e) for(i=(s);i<=(e);i++)
#define For(j,s,e) For(j=(s);j<(e);j++)
#define sc(x) scanf("%d",&x)
#define In(x) scanf("%I64d",&x)
#define SS(x,y) scanf("d",&x,&y)
#define pf(x) printf("%d",x)
#define pfn(x) printf("%d\n",(x))
#define Pf(x) printf("%I64d",(x))
#define Pfn(x) printf("%I64d\n",(x))
#define Pc printf(" ")
#define PY puts("YES")
#define PN puts("NO")
#define MP make_pair
#define X first
#define Y second
#define PI acos(-1.0)
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

const int maxn=300+10;
const int MOD=1e9+7;

int T[44],n;
bool vis[maxn][maxn][8][6][31],mp[maxn][maxn];
int dxy[][2]={{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};

void dfs(int x,int y,int dir,int step,int now){
    if(vis[x][y][dir][step][now] || now>n) return ;
    vis[x][y][dir][step][now]=1;
    mp[x][y]=1;
    if(step)
        dfs(x+dxy[dir][0],y+dxy[dir][1],dir,step-1,now);
    else {
        dfs(x+dxy[(dir-1+8)%8][0],y+dxy[(dir-1+8)%8][1],(dir-1+8)%8,T[now+1]-1,now+1);
        dfs(x+dxy[(dir+1)%8][0],y+dxy[(dir+1)%8][1],(dir+1)%8,T[now+1]-1,now+1);
    }
}

int main()
{
    int i,j;
    while(scanf("%d",&n)!=EOF){
        for(i=1;i<=n;i++)
            scanf("%d",&T[i]);
        memset(vis,0,sizeof(vis));
        memset(mp,0,sizeof(mp));
        dfs(150,150,0,T[1]-1,1);
        int res=0;
        for(i=0;i<=300;i++)
            for(j=0;j<=300;j++)
                if(mp[i][j]) res++;
        printf("%d\n",res);
    }
    return 0;
}


