/****************
*PID:463e div2
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn=100000+10;
int a[maxn],head[maxn],nxt[maxn*2],vv[maxn*2],par[maxn],e;

void Init(){
    memset(head,0,sizeof(head));
    e=1;
}

void add(int u,int v){
    vv[e]=v;nxt[e]=head[u];head[u]=e++;
}

int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}

void dfs(int u,int pa){
    par[u]=pa;
    for(int i=head[u];i;i=nxt[i]){
        int v=vv[i];
        if(v==pa) continue;
        dfs(v,u);
    }
}

int main()
{
    int i,j,n,Q;
    while(scanf("%d%d",&n,&Q)!=EOF){
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        Init();
        int u,v;
        for(i=1;i<n;i++){
            scanf("%d%d",&u,&v);
            add(u,v);add(v,u);
        }
        dfs(1,-1);
        int o,w;
        while(Q--){
            scanf("%d",&o);
            if(o==1){
                scanf("%d",&u);
                if(u==1)
                    puts("-1");
                else {
                    int now=par[u];
                    while(now!=-1 && gcd(a[now],a[u])<=1)
                        now=par[now];
                    printf("%d\n",now);
                }
            }else {
                scanf("%d%d",&u,&w);
                a[u]=w;
            }
        }
    }
    return 0;
}
