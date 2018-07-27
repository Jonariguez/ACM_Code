/****************
*PID:hdu5622
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=100+5;
const int maxk=1000+5;
const LL MOD=1e9+7;
LL dp[maxn][2];
int head[maxn],vv[maxn*2],nxt[maxn*2],e,vis[maxn];
int cycle,Size;

void Init(){
    memset(head,0,sizeof(head));
    e=1;
}

void add(int u,int v){
    vv[e]=v;nxt[e]=head[u];head[u]=e++;
}

void dfs(int u,int pa,int step){
    if(vis[u]){
        if(!cycle) cycle=step-vis[u];
        return ;
    }
    vis[u]=step;
    Size++;
    for(int i=head[u];i;i=nxt[i]){
        int v=vv[i];
        if(v==pa) continue;
        dfs(v,u,step+1);
    }
}

int main()
{
    int i,j,n,k,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&k);
        Init();
        for(i=1;i<=n;i++){
            int c;
            scanf("%d",&c);
            ++c;
            add(i,c);add(c,i);
        }
        dp[1][1]=1;dp[1][0]=0;
        for(i=2;i<=n;i++){
            dp[i][0]=(dp[i-1][0]*(k-2)%MOD+dp[i-1][1]*(k-1)%MOD)%MOD;
            dp[i][1]=dp[i-1][0];
        }
        LL res=1LL;
        memset(vis,0,sizeof(vis));
        for(i=1;i<=n;i++){
            if(vis[i]) continue;
            cycle=0;Size=0;
            dfs(i,-1,1);
            if(cycle==0)
                cycle=2;
            res=(res*dp[cycle][0]%MOD*k)%MOD;
           // printf("c=%d\n",cycle);
            Size-=cycle;
            while(Size--){
                res=(res*(k-1))%MOD;
            }
        }
        printf("%I64d\n",res);
    }
    return 0;
}



