/****************
*PID:
*Auth:Jonariguez
*****************
*/
#define lson k*2,l,m
#define rson k*2+1,m+1,r
#define rep(i,n) for(i=1;i<=(n);i++)
#define rep0(i,n) for(i=0;j<=(n);i++)
#define re(i,n) for(i=1;i<(n);i++)
#define re0(i,n) for(i=0;i<(n);i++)
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
#define PB push_back
#define X first
#define Y second
#define PI acos(-1.0)
#include <stdio.h>
#include <string.h>
#include <string>
#include <sstream>
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
typedef long long Ll;
Ll Pow(Ll a,Ll b,Ll MOD){a%=MOD;Ll res=1;while(b){if(b&1)res=(res*a)%MOD;b/=2;a=(a*a)%MOD;}return res;}

const int maxn=600+10;
const int MOD=1e9+7;

int dis[maxn],a[maxn],ans[maxn],vis[maxn],inq[maxn];

struct node{
    int to,w;
};

vector<node> vec[maxn];

struct cmp{
    bool operator () (const int a,const int b){
        if(dis[a]==dis[b])
            return ans[a]<ans[b];   //注意，在距离都是最小的情况下，一定要取钱多的，不然会WA
        return dis[a]>dis[b];
    }
};

void DJ(int S,int T,int n){
    memset(vis,0,sizeof(vis));
    memset(inq,0,sizeof(inq));
    for(int i=0;i<=n;i++){
        dis[i]=MOD;ans[i]=0;
    }
    int i;
    priority_queue<int,vector<int>,cmp> que;
    dis[S]=0;ans[S]=a[S];inq[S]=1;
    que.push(S);
    while(!que.empty()){
        int u=que.top();que.pop();
        vis[u]=1;
        for(i=0;i<vec[u].size();i++){
            int v=vec[u][i].to,w=vec[u][i].w;
            if(vis[v]==0){
                if(dis[v]>dis[u]+w){
                    dis[v]=dis[u]+w;
                    que.push(v);
                    ans[v]=ans[u]+a[v];
                }else if(dis[v]==dis[u]+w){
                    que.push(v);
                    if(ans[v]<ans[u]+a[v]){
                        ans[v]=ans[u]+a[v];
                    }
                }
            }
        }
    }
}

int main()
{
    int i,j,n,m,S,T;
    scanf("%d%d%d%d",&n,&m,&S,&T);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(i=1;i<=m;i++){
        int x,y,w;
        scanf("%d%d%d",&x,&y,&w);
        x++;y++;
        vec[x].push_back((node){y,w});
        vec[y].push_back((node){x,w});
    }
    S++;T++;
    DJ(S,T,n);
    printf("%d %d\n",dis[T],ans[T]);
    return 0;
}


