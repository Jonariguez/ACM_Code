/****************
*PID:zoj3710
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

const int maxn=100+10;
int head[maxn],nxt[maxn*maxn*4],vv[maxn*maxn*4],vis[maxn],mp[maxn][maxn],e,n,m,k;
int fri[maxn],cnt[maxn];
set<int> f[maxn];

void Init(){
    memset(head,0,sizeof(head));
    memset(fri,0,sizeof(fri));
    e=1;
}

void add(int u,int v){
    vv[e]=v;nxt[e]=head[u];head[u]=e++;
}

int bfs(){
    int i,j,res=0;
    queue<int> que;
    memset(vis,0,sizeof(vis));
    for(i=1;i<=n;i++)
        if(fri[i]>=k){
            que.push(i);vis[i]=1;
        }
    while(!que.empty()){
        int u=que.front();que.pop();
        vis[u]=0;
        memset(cnt,0,sizeof(cnt));
        for(i=head[u];i;i=nxt[i]){
            int z=vv[i];
            for(j=head[z];j;j=nxt[j]){
                int v=vv[j];
                if(v==u || mp[u][v]) continue;
                cnt[v]++;
            }
        }
        for(i=1;i<=n;i++){
            if(i==u) continue;
            if(cnt[i]>=k){
                add(i,u);add(u,i);mp[u][i]=mp[i][u]=1;
                fri[u]++;fri[i]++;
                res++;
                if(vis[i]==0 && fri[i]>=k){
                    que.push(i);vis[i]=1;
                }
            }
        }
    }
    return res;
}

int main()
{
  //  freopen("zoj3710.txt","r",stdin);
  //  freopen("zoj3710myout.txt","w",stdout);
    int i,j,T,t;
    sc(T);
    while(T--){
        scanf("%d%d%d",&n,&m,&k);
        Init();
        memset(mp,0,sizeof(mp));
        for(i=1;i<=n;i++){
            mp[i][i]=1;f[i].clear();
        }
        for(i=0;i<m;i++){
            int u,v;
            sc(u);sc(v);
            u++;v++;
            if(mp[u][v]) continue;
            add(u,v);add(v,u);
            fri[u]++;fri[v]++;
            mp[u][v]=mp[v][u]=1;
        }
        if(k==0){
            printf("%d\n",n*(n-1)/2-m);continue;
        }
        int res=0;
        while(t=bfs()) res+=t;
        printf("%d\n",res);
    }
    return 0;
}




