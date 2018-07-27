/*
并查集
用pos[]数组为每个数编号，初始时pos[i]=i;
对于2操作，为pos[p]重新分配一个新位置++tot，
但其值还依然是p，而不是++tot,初始化sum[pos[p]]
cnt[pos[p]]之后，将pos[p]作为新节点参与一般的
并查集操作即可，对于每个操作给出的p或q，都不能
直接对p或q操作，而是对其对应的节点pos[p],pos[q]
操作即可
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long ll;

const int maxn=100000+10;
ll sum[maxn*2],cnt[maxn*2],par[maxn*2],pos[maxn*2],tot;

void Init(ll n){
    for(ll i=0;i<=n;i++){
        par[i]=i;sum[i]=i;cnt[i]=1;pos[i]=i;
    }
}

void New(ll p){
    pos[p]=++tot;cnt[pos[p]]=1;sum[pos[p]]=p;par[pos[p]]=pos[p];
}

ll Find(ll x){
    return par[x]==x?x:par[x]=Find(par[x]);
}

void Union(ll u,ll v){
    if((u=Find(u))==(v=Find(v)))
        return ;
    par[u]=v;sum[v]+=sum[u];cnt[v]+=cnt[u];
}

int main()
{
    ll i,j;
    ll n,m;
    while(scanf("%lld%lld",&n,&m)!=EOF){
        tot=n;
        Init(n);
        ll o,p,q;
        while(m--){
            scanf("%lld",&o);
            if(o==3){
                scanf("%lld",&p);
                ll f=Find(pos[p]);
                printf("%lld %lld\n",cnt[f],sum[f]);
            }else if(o==1){
                scanf("%lld%lld",&p,&q);
                Union(pos[p],pos[q]);
            }else {
                scanf("%lld%lld",&p,&q);
                if(Find(pos[p])==Find(pos[q]))  //一定要在他们不在同一个集合时再操作，否则直接跳过
                    continue;
                ll P=Find(pos[p]);
                sum[P]-=p;cnt[P]--;
                New(p);
                Union(pos[p],pos[q]);
            }
        }
    }
    return 0;
}
