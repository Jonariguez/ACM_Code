/****************
*PID:bzoj1015
*Auth:Jonariguez
*****************
离线，倒着做，将删除节点操作变成添加节点操作即可。
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

const int maxn=400000+10;
const int MOD=1e9+7;

int head[maxn],nxt[maxn],vv[maxn],e=1;
int node[maxn],vis[maxn],par[maxn],res[maxn];
bool del[maxn];

void Init(int n){
    for(int i=0;i<=n;i++)
        par[i]=i;
    e=1;
}

int find(int x){
    return x==par[x]?x:par[x]=find(par[x]);
}

bool Union(int u,int v){
    if((u=find(u))==(v=find(v)))
        return false;
    par[u]=v;
    return true;
}

void add(int u,int v){
    vv[e]=v;nxt[e]=head[u];head[u]=e++;
}

int main()
{
    int i,j,n,m;
    memset(del,0,sizeof(del));
    scanf("%d%d",&n,&m);
    Init(n);
    int x,y;
    for(i=1;i<=m;i++){
        scanf("%d%d",&x,&y);
        x++;y++;
        add(x,y);add(y,x);
    }
    int K;
    scanf("%d",&K);
    for(i=1;i<=K;i++){
        scanf("%d",&node[i]);
        node[i]++;
        del[node[i]]=1;     //将删除的节点标记
    }
    res[K+1]=n-K;
    for(i=1;i<=n;i++){  //先忽略掉所有已经删除的结点，用剩下的结点构造出最终的图，然后从最终的图倒着添加那些“删除”的点
        if(del[i]) continue;
        for(j=head[i];j;j=nxt[j]){
            int v=vv[j];
            if(del[v]) continue;
            if(Union(i,v))
                res[K+1]--;
        }
    }

    for(i=K;i>=1;i--){
        int u=node[i],cnt=-1;
        for(j=head[u];j;j=nxt[j]){
            int v=vv[j];
            if(del[v]) continue;    //如果是还没有添加到图中的就忽略
            int f=find(v);
            if(f!=u)    //这里可以vis[f]!=i来标记的，不过在不Union的情况下要先求出cnt，然后遍历一遍所有的v再去Union
                cnt++;      //故根据Union函数中固定的par[u]=v,采用这种f!=u可以判断。
            //vis[f]=i;
            Union(f,u);
        }
        del[u]=0;   //这个点添加到图中之后，去掉“删除”标记
        res[i]=res[i+1]-cnt;
    }
    for(i=1;i<=K+1;i++)
        printf("%d\n",res[i]);
    return 0;
}



