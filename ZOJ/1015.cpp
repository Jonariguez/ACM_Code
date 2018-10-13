/****************
*PID:zoj1015
*Auth:Jonariguez
*****************
орм╪╣деп╤о
https://blog.csdn.net/g1n0st/article/details/60145467
https://blog.csdn.net/coldef/article/details/60153786
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

const int maxn=1000+10;
const int maxm=2000000+4;
const int MOD=1e9+7;

int head[maxn],vv[maxm],nxt[maxm];
int cnt[maxn],mark[maxn],e;
bool mp[maxn][maxn],vis[maxn];
int n,m;
vector<int> c;

void add(int u,int v){
    vv[e]=v;nxt[e]=head[u];head[u]=e++;
}

bool check(){
    int i,j;
    for(i=n;i>=1;i--){
        c.clear();
        int u=mark[i];
        for(j=i+1;j<=n;j++)
            if(mp[u][mark[j]])
                c.push_back(mark[j]);
        for(j=1;j<c.size();j++)
            if(!mp[c[0]][c[j]])
                return false;
    }
    return true;
}


bool MSC(){
    memset(cnt,0,sizeof(cnt));
    memset(vis,0,sizeof(vis));
    int i,j;
    for(i=n;i>=1;i--){
        int u=-1;
        for(j=1;j<=n;j++)
            if(!vis[j] && (u==-1 || cnt[u]<cnt[j]))
                u=j;
        mark[i]=u;
        vis[u]=1;
        for(j=head[u];j;j=nxt[j])
            cnt[vv[j]]++;
    }
    return check();
}

int main()
{
    int i,j;
    while(scanf("%d%d",&n,&m)!=EOF && n && m){
        memset(head,0,sizeof(head));
        memset(mp,0,sizeof(mp));
        e=1;
        for(i=1;i<=m;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            add(u,v);add(v,u);
            mp[u][v]=mp[v][u]=1;
        }
        if(MSC())
            puts("Perfect\n");
        else
            puts("Imperfect\n");
    }
    return 0;
}




