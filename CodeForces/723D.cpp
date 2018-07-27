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

const int maxn=50+10;
const int MOD=1e9+7;
char str[maxn][maxn];
int n,m,vis[maxn][maxn],cnt;
bool yes;
struct node{
    int x,y,cnt;
}res[maxn*maxn];

bool cmp(const node &a,const node &b){
    return a.cnt<b.cnt;
}

void dfs(int x,int y){
    if(x<1 || x>m || y<1 || y>n || str[y][x]=='*') return ;
    if(x==1 || y==1 || x==m || y==n) yes=false;
    if(vis[y][x]) return ;
    vis[y][x]=1;
    cnt++;
    dfs(x+1,y);
    dfs(x-1,y);
    dfs(x,y-1);
    dfs(x,y+1);
}

void dfs2(int x,int y){
    if(x<1 || x>m || y<1 || y>n || str[y][x]=='*') return ;
    str[y][x]='*';
    dfs2(x+1,y);
    dfs2(x-1,y);
    dfs2(x,y-1);
    dfs2(x,y+1);
}


int main()
{
    int i,j,k;
    scanf("%d%d%d",&n,&m,&k);
    for(i=1;i<=n;i++)
        scanf("%s",str[i]+1);
    int tot=0;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(str[i][j]=='*' || vis[i][j]) continue;
            cnt=0;
            yes=true;
            dfs(j,i);
            if(yes){
                res[++tot].x=j;res[tot].y=i;res[tot].cnt=cnt;
            }
        }
    }
    sort(res+1,res+tot+1,cmp);
    k=tot-k;
    int ans=0;
    for(i=1;i<=k;i++){
        dfs2(res[i].x,res[i].y);
        ans+=res[i].cnt;
    }
    printf("%d\n",ans);
    for(i=1;i<=n;i++)
        printf("%s\n",str[i]+1);
    return 0;
}



