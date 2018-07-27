/****************
*PID:659f div2
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

const int maxn=1000+5;
int a[maxn][maxn],sum[maxn*maxn],vis[maxn][maxn],mp[maxn][maxn],n,m;
LL k;
vector<int> p,jilu;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

struct node{
    int x,y;
};

int get(int x){
    return (upper_bound(p.begin(),p.end(),x)-p.begin());
}

int ID(int i,int j){
    return i*m+j;
}

int bfs(int val,int sx,int sy,int &cnt,int &X,int &Y){
    queue<node> que;
    int i;
    bool ok=false;
    cnt=0;
    node u;
    u.x=sx;u.y=sy;
    que.push(u);
    vis[sx][sy]=1;
    while(!que.empty()){
        u=que.front();que.pop();
        cnt++;
        if(a[u.x][u.y]==val){
            ok=true;
            X=u.x;Y=u.y;
        }
        for(i=0;i<4;i++){
            int x=u.x+dx[i],y=u.y+dy[i];
            if(x<0 || x>=n || y<0 || y>=m || vis[x][y] || a[x][y]<val) continue;
            node t;
            t.x=x;t.y=y;
            vis[x][y]=1;
            que.push(t);
        }
    }
    return ok;
}

void BFS(int val,int sx,int sy,int C){
    queue<node> que;
    node u;
    u.x=sx;u.y=sy;
    que.push(u);
    vis[sx][sy]=1;
    int cnt=0;
    while(!que.empty()){
        u=que.front();que.pop();
        mp[u.x][u.y]=val;
        cnt++;
        if(cnt>=C) return ;
        for(int i=0;i<4;i++){
            int x=u.x+dx[i],y=u.y+dy[i];
            if(x<0 || x>=n || y<0 || y>=m || vis[x][y] || a[x][y]<val) continue;
            node t;
            t.x=x;t.y=y;
            vis[x][y]=1;
            que.push(t);
        }
    }
}


int main()
{
    int i,j;
    int T=0;
    while(scanf("%d%d%I64d",&n,&m,&k)!=EOF){
        p.clear();
        jilu.clear();
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                sc(a[i][j]);
                p.push_back(a[i][j]);
            }
        }
        sort(p.begin(),p.end());
        p.erase(unique(p.begin(),p.end()),p.end());
        memset(sum,0,sizeof(sum));
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                int t=get(a[i][j]);
                sum[t]++;
            }
        }
        sum[0]=0;
        for(i=1;i<=p.size();i++)
            sum[i]+=sum[i-1];
        int tot=n*m,v,t,temp;
        for(i=0;i<p.size();i++){
            if(k%p[i]!=0) continue;
            v=p[i];
            t=get(v);
            temp=sum[t-1];
            if((tot-temp)<k/v) continue;
            jilu.push_back(v);
        }
        if(jilu.size()==0){
            puts("NO");continue;
        }
        int z;
        for(z=0;z<jilu.size();z++){
            v=jilu[z];
            LL zz=k/(LL)v;
            int should=(int)zz;
            int res=0;
            memset(vis,0,sizeof(vis));
            node A;
            int flag=0;
            for(i=0;i<n;i++){
                for(j=0;j<m;j++){
                    if(vis[i][j] || a[i][j]<v) continue;
                    int cc=0,X,Y;
                    bool ok=bfs(v,i,j,cc,X,Y);  //一定要注意，那个不变的值的位置也应该在该答案的联通块里
                    if(ok==false) continue;
                    if(res<cc)
                        res=cc;
                    if(res>=should){
                        A.x=X;A.y=Y;    //要从==val的位置开始BFS，因为如果不是在这里可能出现到不了这里
                        flag=1;break;       //sum之和已经等于k了。
                    }
                }
                if(flag) break;
            }
            if(flag==0){
                continue;
            }
            memset(mp,0,sizeof(mp));
            memset(vis,0,sizeof(vis));
            BFS(v,A.x,A.y,should);
            puts("YES");
            for(i=0;i<n;i++){
                for(j=0;j<m;j++)
                    printf("%d ",mp[i][j]);
                puts("");
            }
            break;
        }
        if(z>=jilu.size())
            puts("NO");
    }
    return 0;
}





