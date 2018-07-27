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

const int maxn=500+10;
const int MOD=1e9+7;

int mp[maxn][maxn];
char str[maxn];
int vis[maxn][maxn];
int n,m;

struct node{
    int x,y;
};

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

int bfs(int flag){
    int i,j;
    memset(vis,0,sizeof(vis));
    queue<node> que;
    vis[1][1]=1;
    que.push((node){1,1});
    while(!que.empty()){
        node u=que.front();
        que.pop();
        for(i=0;i<4;i++){
            int xx=dx[i]+u.x,yy=dy[i]+u.y;
            if(xx<1 || xx>n || yy<1 || yy>m || mp[xx][yy]==1 || vis[xx][yy]) continue;
            if(mp[xx][yy]==-1 && !flag) continue;
            vis[xx][yy]=vis[u.x][u.y]+1;
            if(xx==n && yy==m){
                return vis[xx][yy]-1;
            }
            que.push((node){xx,yy});
        }
    }
    return -1;
}



int main()
{
    int i,j,k;
    scanf("%d%d%d",&n,&m,&k);
    memset(mp,0,sizeof(mp));
    for(i=1;i<=n;i++){
        scanf("%s",str+1);
        for(j=1;j<=m;j++)
            if(str[j]=='.')
                mp[i][j]=0;
            else if(str[j]=='x')
                mp[i][j]=1;
    }
    for(i=1;i<=k;++i){
        int a,b;
        scanf("%d%d",&a,&b);
        a++;b++;
        mp[a][b]=-1;
    }
    int res1=bfs(0);
    int res2=bfs(1);
   // printf("res1=%d res2=%d\n",res1,res2);
    if(res1==-1 && res2==-1){
        puts("NO");
        return 0;
    }
    if(res1==-1 && res2>=0){
        puts("YES");return 0;
    }
    if(res2+5<res1)
        puts("YES");
    else puts("NO");
    return 0;
}

