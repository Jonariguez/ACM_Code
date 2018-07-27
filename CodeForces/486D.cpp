/****************
*PID:486d div2
*Auth:Jonariguez
*****************
枚举下界，树形dp
如何去重，规定从编号小的往编号大的dp，如：
设1,2,3的权值相等，则从1开始做dp得到{1},{1,2},{1,2,3}
从2开始做dp得到{2},{2,3}(即不往编号比自己小的1做)
从3开始做dp得到{3}（不往1和2做）
这样就可以去重了。
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=2000+5;
const int mod=1000000007;

int head[maxn],vv[maxn*2],nxt[maxn*2],a[maxn],e,d,n;
LL dp[maxn];

void add(int u,int v){
    vv[e]=v;nxt[e]=head[u];head[u]=e++;
}

void dfs(int u,int pa,int w,int ori){
    if((a[u]>w && a[u]-w<=d) || a[u]==w && ori<=u){
        dp[u]=1;
        int i;
        for(i=head[u];i;i=nxt[i]){
            int v=vv[i];
            if(v==pa) continue;
            dfs(v,u,w,ori);
            dp[u]*=(dp[v]+1);
            dp[u]%=mod;
        }
    }
}

int main()
{
    int i,j;
    while(scanf("%d%d",&d,&n)!=EOF){
        for(i=1;i<=n;i++) scanf("%d",&a[i]);
        memset(head,0,sizeof(head));
        e=1;
        for(i=1;i<n;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            add(a,b);
            add(b,a);
        }
        LL res=0;
        for(i=1;i<=n;i++){
            memset(dp,0,sizeof(dp));
            dfs(i,-1,a[i],i);
            res+=dp[i];
           // printf("dp=%I64d\n",dp[i]);
            res%=mod;
        }
        printf("%I64d\n",res);
    }
    return 0;
}
