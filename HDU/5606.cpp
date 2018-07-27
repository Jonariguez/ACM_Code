/****************
*PID:hdu5606
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=100000+5;
int head[maxn],nxt[maxn*2],vv[maxn*2],wei[maxn*2],e;
int vis[maxn];

void init(){
    e=1;        //因为head和next被初始化为0，则e应该被初始化为1而不是0，以免混淆。则遍历时i就是！=0
    memset(head,0,sizeof(head));
   // memset(nxt,0,sizeof(nxt));
   // memset(wei,0,sizeof(wei));
}

void add(int u,int v,int w){
    vv[e]=v;wei[e]=w;nxt[e]=head[u];head[u]=e++;
}

int cnt;

void dfs(int u,int pa){
    vis[u]=1;
    int i;
    for(i=head[u];i;i=nxt[i]){
        int v=vv[i];
        if(v!=pa && wei[i]==0){
            cnt++;
            dfs(v,u);
        }
    }
}


int main()
{
    int i,j,n,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        init();
        for(i=1;i<n;i++){
            int a,b,w;
            scanf("%d%d%d",&a,&b,&w);
           // if(w) continue;
            add(a,b,w);
            add(b,a,w);
        }
        memset(vis,0,sizeof(vis));
        int res=0;
        for(i=1;i<=n;i++){
            if(!vis[i]){
                cnt=1;
                dfs(i,-1);
                if(cnt&1)
                    res^=cnt;
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
