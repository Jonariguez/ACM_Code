/****************
*PID:bzoj1006
*Auth:Jonariguez
*****************
弦图最小染色，求出完美消除序列之后直接从后往前贪心染就行了
https://wenku.baidu.com/view/6f9f2223dd36a32d73758126.html
https://www.cnblogs.com/CtrlCV/p/5668664.html
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

const int maxn=10000+10;
const int maxm=2000000+5;
const int MOD=1e9+7;

int n,m;
int head[maxn],nxt[maxm],vv[maxm],e;
int vis[maxn],perf[maxn],cnt[maxn],col[maxn];

void add(int u,int v){
    vv[e]=v;nxt[e]=head[u];head[u]=e++;
}

void MSC(){
    int i,j;
    memset(vis,0,sizeof(vis));
    memset(cnt,0,sizeof(cnt));
    for(i=n;i>=1;i--){
        int u=0;
        for(j=1;j<=n;j++)
            if(!vis[j] && (u==0 || cnt[u]<cnt[j]))
                u=j;
        perf[i]=u;
        vis[u]=1;
        for(j=head[u];j;j=nxt[j]){
            int v=vv[j];
            cnt[v]++;
        }
    }
}

int solve(){
    MSC();
    int i,j;
    memset(vis,0,sizeof(vis));
    memset(col,0,sizeof(col));
    col[perf[n]]=1;     //先给最后一个染1号颜色
    for(i=n-1;i>=1;i--){
        int u=perf[i];
        for(j=head[u];j;j=nxt[j])
            vis[col[vv[j]]]=i;      //将与u相邻的节点的颜色的vis都标记为i
        for(j=1;;j++){
            if(vis[j]!=i){      //出现的最小的j使得vis[j]不等于i既可
                col[u]=j;break;
            }
        }
    }
    int res=1;
    for(i=1;i<=n;i++)
        res=max(res,col[i]);
    return res;
}


int main()
{
    int i,j;
    scanf("%d%d",&n,&m);
    e=1;
    for(i=1;i<=m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v);
        add(v,u);
    }
    printf("%d\n",solve());
    return 0;
}

