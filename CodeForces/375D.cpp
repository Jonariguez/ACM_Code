/****************
*PID:375d div1
*Auth:Jonariguez
*****************
树上莫队
start，end表示dfs序，每个节点的开始和结束位置。
c[u]:节点u的颜色
color[i]：dfs序为i的点的颜色
cnt[C]:颜色C出现的次数。
sum[v]:出现次数(即节点个数)大于等于v的颜色的个数。
如：节点：1 2 3 4 5 6
  ：颜色：1 2 2 1 1 3
那么sum[2]=2,因为出现次数大于等于2的有两种颜色，分别为
颜色2(出现2次，节点2和节点3）和颜色1（出现3次，节点1，
节点4和节点5)
http://blog.csdn.net/u010885899/article/details/50633839
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

const int maxn=100000+10;
int c[maxn],color[maxn],vis[maxn],cnt[maxn],sum[maxn],start[maxn],end[maxn],dfs_clock,n,m,unit;
int res[maxn];
vector<int> con[maxn];

struct Command{
    int L,R,id,k;
}s[maxn];

int cmp(const Command &x,const Command &y){
    if(x.L/unit==y.L/unit)
        return x.R<y.R;
    return x.L/unit<y.L/unit;
}

void Init(int n){
    dfs_clock=0;
    for(int i=0;i<=n;i++) con[i].clear();
    memset(cnt,0,sizeof(cnt));
    memset(sum,0,sizeof(sum));
    memset(color,0,sizeof(color));
    memset(vis,0,sizeof(vis));
}

void dfs(int u,int pa){
    vis[u]=1;
    start[u]=++dfs_clock;
    color[dfs_clock]=c[u];  //color只在start处标记，end处不标记，因为dfs序中下标为end[u]的并不一定是节点u。
    for(int i=0;i<con[u].size();i++){   //而是以u为根的dfs遍历时的最后一个节点，体会一下dfs序吧。
        int v=con[u][i];
        if(v==pa || vis[v]) continue;
        dfs(v,u);
    }
    end[u]=dfs_clock;
}

void Mo(){
    int L=1,R=0,i,now;
    for(i=0;i<m;i++){
        int id=s[i].id;
        if(s[i].L==s[i].R){
            res[id]=s[i].k>1?0:1;
            continue;
        }
        while(R<s[i].R){
            R++;
            sum[++cnt[color[R]]]++;
        }
        while(R>s[i].R){
            sum[cnt[color[R]]--]--;
            R--;
        }
        while(L<s[i].L){
            sum[cnt[color[L]]--]--;
            L++;
        }
        while(L>s[i].L){
            L--;
            sum[++cnt[color[L]]]++;
        }
        res[id]=sum[s[i].k];
    }
}


int main()
{
    int i,j;
    while(scanf("%d%d",&n,&m)!=EOF){
        for(i=1;i<=n;i++) sc(c[i]);
        Init(n);
        for(i=1;i<n;i++){
            int u,v;
            sc(u);sc(v);
            con[u].push_back(v);con[v].push_back(u);
        }
        dfs(1,-1);
        for(i=0;i<m;i++){
            int x,k;
            scanf("%d%d",&x,&k);
            s[i].id=i;
            s[i].k=k;
            s[i].L=start[x];
            s[i].R=end[x];
        }
        unit=(int)sqrt(dfs_clock);
        sort(s,s+m,cmp);
        Mo();
        for(i=0;i<m;i++)
            printf("%d\n",res[i]);
    }
    return 0;
}


