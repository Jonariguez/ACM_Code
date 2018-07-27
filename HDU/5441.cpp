/****************
*PID:hdu5441
*Auth:Jonariguez
*****************
Changchun 05
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

const int maxn=20000+10;
int par[maxn],Rank[maxn],id[5010],order[5010];
ll res[5010];

struct Edge{
    int a,b,v;
    bool operator < (const Edge &r) const {
        return v<r.v;
    }
}s[100008];

int cmp(int i,int j){
    return order[i]<order[j];
}

void Init(int n){
    int i;
    for(i=0;i<=n;i++){
        par[i]=i;Rank[i]=1;
    }
}

int Find(int x){
    return x==par[x]?x:par[x]=Find(par[x]);
}

void Union(int u,int v,ll &cnt){
    if((u=Find(u))==(v=Find(v))) return ;
    cnt+=(ll)Rank[u]*Rank[v]*2;
    par[u]=v;Rank[v]+=Rank[u];
}

int main()
{
    int i,j,n,m,Q,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&m,&Q);
        Init(n);
        for(i=0;i<m;i++)
            scanf("%d%d%d",&s[i].a,&s[i].b,&s[i].v);
        sort(s,s+m);
        for(i=0;i<Q;i++){
            id[i]=i;
            scanf("%d",&order[i]);
        }
        sort(id,id+Q,cmp);
        ll cnt=0;
        j=0;
        for(i=0;i<m && j<Q;i++){
            if(s[i].v<=order[id[j]]){
                Union(s[i].a,s[i].b,cnt);
                if(i!=m-1)
                    continue;
            }
         //   for(int k=1;k<=n;k++)
         //       if(par[k]==k && Rank[k]>1)
         //           cnt+=(ll)Rank[k]*(Rank[k]-1);
            res[id[j]]=cnt;
            j++;
            i--;
        }
        for(i=0;i<Q;i++)
            printf("%lld\n",res[i]);
    }
    return 0;
}
