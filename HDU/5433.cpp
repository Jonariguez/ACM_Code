/****************
*PID:hdu5433
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

const int maxn=55;
const double INF=1e9;

char str[maxn][maxn];
int sx,sy,tarx,tary,n,m,k;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
double vis[maxn][maxn][maxn];

struct node{
    int x,y,K;
    double power;
    bool operator < (const node &r) const {
        return power>r.power;
    }
};

double res;
bool flag;

void bfs(){
    queue<node> que;
    node u;
    u.x=sx;u.y=sy;u.K=k;u.power=0.0;
    vis[u.x][u.y][k]=0.0;
    que.push(u);
    while(!que.empty()){
        u=que.front();que.pop();
        if(u.x==tarx && u.y==tary){
            flag=true;continue;
        }
        if(u.K<=0)
            continue;
        int i;
        for(i=0;i<4;i++){
            int x=u.x+dx[i],y=u.y+dy[i];
            if(x>n || x<1 || y<1 || y>m) continue;
            if(str[x][y]=='#') continue;
            int p=str[x][y]-'0',q=str[u.x][u.y]-'0';
            double temp=u.power+1.0*abs(p-q)/u.K;
            if(vis[x][y][u.K-1]-temp<=0) continue;
            node t;
            vis[x][y][u.K-1]=temp;
            t.x=x;t.y=y;t.K=u.K-1;t.power=temp;
            que.push(t);
           // }
          //  puts("??");
        }
    }
}


int main()
{
    int i,j,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&m,&k);
        for(i=1;i<=n;i++)
            scanf("%s",str[i]+1);
        scanf("%d%d%d%d",&sx,&sy,&tarx,&tary);
        if(k<=0){
            puts("No Answer");continue;
        }
        for(i=0;i<=n;i++)
            for(j=0;j<=m;j++)
                for(int z=0;z<=k;z++) vis[i][j][z]=INF;
        flag=false;
        bfs();
        if(flag){
            res=INF;
            for(i=0;i<=k;i++)
                res=min(res,vis[tarx][tary][i]);
            printf("%.2f\n",res);
        } else puts("No Answer");
    }
    return 0;
}
