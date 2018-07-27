/****************
*PID:cdvs1001
*Auth:Jonariguez
*****************
枚举最小边，然后用并查集来一个一个的加边判断s和t
是否联通，如果联通则停止。
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn=500+5;
const int maxm=5000+5;
int head[maxn],wei[maxm*2],vv[maxm*2],nxt[maxm*2],e;
int par[maxn],vis[maxn],n,m;

void add(int u,int v,int w){
    wei[e]=w;vv[e]=v;nxt[e]=head[u];head[u]=e++;
}

struct pp{
    int a,b,w;
}s[maxm];

int cmp(const pp &x,const pp &y){
    return x.w<y.w;
}

void Init(int n){
    for(int i=0;i<=n;i++)
        par[i]=i;
    memset(head,0,sizeof(head));
    memset(vis,0,sizeof(vis));
    e=1;
}

int find(int x){
    return x==par[x]?x:par[x]=find(par[x]);
}

void Union(int u,int v){
    if((u=find(u))==(v=find(v))) return ;
    par[u]=v;
}

LL gcd(LL a,LL b){
    return b==0?a:gcd(b,a%b);
}

int main()
{
    int i,j,res;
    while(scanf("%d%d",&n,&m)!=EOF){
        int a,b,c;
        Init(n);
        for(i=1;i<=m;i++){
            scanf("%d%d%d",&a,&b,&c);
            s[i].a=a;s[i].b=b;s[i].w=c;
            add(a,b,c);add(b,a,c);
            Union(a,b);
        }
        int S,T;
        scanf("%d%d",&S,&T);
        if(find(S)!=find(T)){
            puts("IMPOSSIBLE");continue;
        }
        sort(s+1,s+m+1,cmp);
        LL resa=-1,resb;
        for(i=1;i<=m;i++){
            LL tb=s[i].w;
            for(j=0;j<=n;j++) par[j]=j;
            j=i;
            while(j<=m){
                int a=s[j].a,b=s[j].b;
                Union(a,b);
                if(find(S)==find(T)) break;
                j++;
            }
            if(j>m) continue;
            LL ta=(LL)s[j].w;
            if(resa==-1 || resa*tb>ta*resb){
                resa=ta;resb=tb;
            }
        }
        LL g=gcd(resa,resb);
        resa/=g;resb/=g;
        if(resa%resb==0)
            printf("%lld\n",resa/resb);
        else printf("%lld/%lld\n",resa,resb);
    }
    return 0;
}


