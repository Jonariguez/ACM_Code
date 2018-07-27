/****************
*PID:677d div2
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

const int maxn=200000+10;
const int MOD=1e9+7;
const int INF=1e9;
int dp[maxn][maxn],d[maxn][maxn],a[maxn][maxn];
vector<pair<int,int> > g[maxn*maxn];
vector<pair<int,pair<int,int> > > lst,bfs;
int fx,fy;
int dir[4][2]={{0,1},{1,0},{-1,0},{0,-1}};

int dist(int x1,int y1,int x2,int y2){
    return abs(x1-x2)+abs(y1-y2);
}

int main()
{
    int i,j,n,m,p;
    scanf("%d%d%d",&n,&m,&p);
    for(i=0;i<n;i++)
        for(j=0;j<m;j++) dp[i][j]=INF;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            sc(a[i][j]);
            g[a[i][j]].push_back(make_pair(i,j));
            if(a[i][j]==1)
                dp[i][j]=i+j;   //因为二维数组是从0开始的，所以和j就不用都-1
            if(a[i][j]==p)
                fx=i,fy=j;
        }
    }
    int k;
    for(i=2;i<=p;i++){
        int now_size=g[i].size();
        int last_size=g[i-1].size();
        if(now_size*last_size<=n*m){    //暴力转移dp
            for(j=0;j<now_size;j++){
                int x=g[i][j].X,y=g[i][j].Y;
                for(k=0;k<last_size;k++){
                    int tx=g[i-1][k].X,ty=g[i-1][k].Y;
                    dp[x][y]=min(dp[x][y],dp[tx][ty]+dist(tx,ty,x,y));
                }
            }
        }else { //跑全局最短路
            bfs.clear();
            lst.clear();
            for(j=0;j<n;j++)
                for(k=0;k<m;k++) d[j][k]=-1;
            for(j=0;j<last_size;j++){
                int x=g[i-1][j].X;
                int y=g[i-1][j].Y;
                lst.push_back(make_pair(dp[x][y],make_pair(x,y)));
            }
            sort(lst.begin(),lst.end());
            int now=1;
            j=0;
            bfs.push_back(lst[0]);
            d[lst[0].Y.X][lst[0].Y.Y]=lst[0].X;
            while(j<bfs.size()){
                int x=bfs[j].Y.X;
                int y=bfs[j].Y.Y;
                int val=bfs[j].X;
                j++;
                while(now<lst.size() && lst[now].X<=val)    //把同dp值的点放进bfs队列中进行拓展
                    bfs.push_back(lst[now++]);
                for(k=0;k<4;k++){
                    int xx=x+dir[k][0],yy=y+dir[k][1];
                    if(xx<0 || xx>=n || yy<0 || yy>=m || d[xx][yy]>=0) continue;
                    d[xx][yy]=val+1;
                    bfs.push_back(MP(d[xx][yy],MP(xx,yy)));
                }
            }
            for(k=0;k<now_size;k++)   //将bfs求得的现在g[i]的每个点的最小值复制给dp数组。
                dp[g[i][k].X][g[i][k].Y]=d[g[i][k].X][g[i][k].Y];
        }
    }
    printf("%d\n",dp[fx][fy]);
    return 0;
}


