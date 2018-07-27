/****************
*PID:poj3764
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

const int maxn=100000+10;
LL head[maxn],vv[maxn*2],wei[maxn*2],nxt[maxn*2],e;
LL f[maxn];

void add(LL u,LL v,LL w){
    vv[e]=v;wei[e]=w;nxt[e]=head[u];head[u]=e++;
}

void dfs(LL u,LL pa){
    LL i;
    for(i=head[u];i;i=nxt[i]){
        LL v=vv[i];
        if(v==pa) continue;
        f[v]=f[u]^wei[i];
        dfs(v,u);
    }
}

typedef struct Trie{
    LL chi[maxn*8][2],val[maxn*8],Size;
    void Init(){
        memset(chi[0],0,sizeof(chi[0]));
        Size=1;
    }
    void Insert(LL z){
        LL u=0,i;
        for(i=30;i>=0;i--){
            LL v=(z&(1LL<<i))>0?1:0;
            if(!chi[u][v]){
                memset(chi[Size],0,sizeof(chi[Size]));
                val[Size]=0;
                chi[u][v]=Size++;
            }
            u=chi[u][v];
        }
      //  val[u]=z;
    }
    LL ask(LL z){
        LL u=0,res=0,i;
        for(i=30;i>=0;i--){
            LL v=(z&(1LL<<i))>0?1:0;
            if(chi[u][v^1]){
                res|=(1LL<<i);u=chi[u][v^1];
            }else
                u=chi[u][v];
        }
        return res;
    }
}Trie;

Trie trie;

int main()
{
    LL i,j,n,m;
    while(scanf("%lld",&n)!=EOF){
        memset(head,0,sizeof(head));
        e=1;
        LL u,v,w;
        for(i=1;i<n;i++){
            scanf("%lld%lld%lld",&u,&v,&w);
            u++;v++;
            add(u,v,w);add(v,u,w);
        }
        f[1]=0;
        dfs(1,-1);
        trie.Init();
       // for(i=1;i<=n;i++) trie.Insert(f[i]);
        LL res=0;
        for(i=1;i<=n;i++){
            trie.Insert(f[i]);
            res=max(res,trie.ask(f[i]));
        }
        printf("%lld\n",res);
    }
    return 0;
}

