/****************
*PID:437c div2
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

const int maxn=1000+10;
int deg[maxn],a[maxn],inq[maxn],vis[maxn],n,m;
vector<int> con[maxn];

void Init(){
    for(int i=0;i<=n;i++) con[i].clear();
    memset(vis,0,sizeof(vis));
    memset(deg,0,sizeof(deg));
    memset(inq,0,sizeof(inq));
}

void add(int u,int v){
    con[u].push_back(v);
}

LL topo(){
    int i,j;
    LL res=0;
    queue<int> que;
    for(i=1;i<=n;i++){
        if(deg[i]==0){
            que.push(i);inq[i]=1;
        }
    }
    while(!que.empty()){
        int u=que.front();que.pop();
        vis[u]=1;
        for(i=0;i<con[u].size();i++){
            int v=con[u][i];
            if(vis[v]) continue;
            res+=a[v];
            if(a[v]!=a[u]) deg[v]--;
            if(deg[v]==0 && inq[v]==0){
                que.push(v);inq[v]=1;
            }
        }
    }
    return res;
}

int main()
{
    int i,j;
    while(scanf("%d%d",&n,&m)!=EOF){
        Init();
        for(i=1;i<=n;i++) sc(a[i]);
        for(i=1;i<=m;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            if(a[x]>a[y]){
                deg[y]++;
                add(x,y);
            }else if(a[x]<a[y]){
                deg[x]++;
                add(y,x);
            }else {
                add(y,x);add(x,y);
            }
        }
        printf("%I64d\n",topo());
    }
    return 0;
}




