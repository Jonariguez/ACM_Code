/****************
*PID:hdu5706
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
int vis[maxn][maxn],kkk;
char str[maxn][maxn];
char t1[4]={'g','i','r','l'},t2[3]={'c','a','t'};
int ansg,ansc,n,m;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

void dfs1(int xx,int yy,int cur){
    if(cur>=4) return ;
    if(cur==3){
        ansg++;return ;
    }
    for(int i=0;i<4;i++){
        int x=xx+dx[i];
        int y=yy+dy[i];
        if(x<1 || x>n || y<1 || y>m || vis[x][y]) continue;
        if(str[x][y]!=t1[cur+1]) continue;
        vis[x][y]=1;
        dfs1(x,y,cur+1);
        vis[x][y]=0;
    }
}

void dfs2(int xx,int yy,int cur){
    if(cur>=3) return ;
    if(cur==2){
        ansc++;return ;
    }
    for(int i=0;i<4;i++){
        int x=xx+dx[i];
        int y=yy+dy[i];
        if(x<1 || x>n || y<1 || y>m || vis[x][y]) continue;
        if(str[x][y]!=t2[cur+1]) continue;
        vis[x][y]=1;
        dfs2(x,y,cur+1);
        vis[x][y]=0;
    }
}

int main()
{
    int i,j,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)
            scanf("%s",str[i]+1);
      //  memset(vis,0,sizeof(vis));
        ansg=ansc=0;
        int a,b;
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                if(str[i][j]=='g'){
                    for(a=max(1,i-3);a<=min(n,i+3);a++)
                        for(b=max(1,j-3);b<=min(m,j+3);b++)
                            vis[a][b]=0;
                    dfs1(i,j,0);
                }
                if(str[i][j]=='c'){
                    for(a=max(1,i-2);a<=min(n,i+2);a++)
                        for(b=max(1,j-2);b<=min(m,j+2);b++)
                            vis[a][b]=0;
                    dfs2(i,j,0);
                }
            }
        }
        printf("%d %d\n",ansg,ansc);
    }
    return 0;
}



