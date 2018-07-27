/****************
*PID:poj3026
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn=55;
int vis[maxn][maxn],par[maxn*2],n,m,tot,cnt;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
char str[maxn][maxn];
map<pair<int,int>,int> mp;

struct pp{
    int a,b,w;
}s[maxn*maxn*4];

struct point{
    int x,y;
};

int cmp(const pp &x,const pp &y){
    return x.w<y.w;
}

int find(int x){
    return x==par[x]?x:par[x]=find(par[x]);
}

bool merge(int u,int v){
    if((u=find(u))==(v=find(v))) return false;
    par[v]=u;
    return true;
}

void bfs(int si,int sj,int c){
    queue<point> que;
    point u;
    u.x=si;u.y=sj;
    int i,j;
    que.push(u);
    memset(vis,-1,sizeof(vis));
    vis[si][sj]=0;
    while(!que.empty()){
        u=que.front();que.pop();
        if(str[u.x][u.y]=='A' || str[u.x][u.y]=='S'){
            int id=mp[make_pair(u.x,u.y)];
            if(id>c){
                s[tot].a=c;s[tot].b=id;s[tot++].w=vis[u.x][u.y];
            }
        }
        for(i=0;i<4;i++){
            int x=u.x+dx[i],y=u.y+dy[i];
            if(x<1 || x>n || y<1 || y>m || str[x][y]=='#' || vis[x][y]>=0) continue;
          //  printf("x=%d y=%d\n",x,y);
            vis[x][y]=vis[u.x][u.y]+1;
            point v;
            v.x=x;v.y=y;
            que.push(v);
        }
    }
}

int main()
{
    int i,j,res,T;
    scanf("%d",&T);
  //  getchar();
    while(T--){
        scanf("%d%d",&m,&n);
        char aa[maxn];
        gets(aa);        // 不加这个会WA的很惨。
        for(i=0;i<=101;i++) par[i]=i;       //100个alien，另外还有一个S呢，最多101个。..
        mp.clear();
        cnt=0;
        for(i=1;i<=n;i++){
            gets(str[i]+1);
            for(j=1;j<=m;j++)
                if(str[i][j]=='A' || str[i][j]=='S')
                    mp[make_pair(i,j)]=++cnt;
        }
        tot=0;
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                if(str[i][j]=='A' || str[i][j]=='S'){
                    bfs(i,j,mp[make_pair(i,j)]);
                }
            }
        }
        sort(s,s+tot,cmp);
        res=0;
        int c=0;
        for(i=0;i<tot;i++){
            if(merge(s[i].a,s[i].b)){
                res+=s[i].w;
              //  printf("s.w=%d\n",s[i].w);
                if(++c==cnt-1) break;
            }
        }
        printf("%d\n",res);
    }
    return 0;
}

