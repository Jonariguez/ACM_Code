/*
���鼯
��pos[]����Ϊÿ������ţ���ʼʱpos[i]=i;
����2������Ϊpos[p]���·���һ����λ��++tot��
����ֵ����Ȼ��p��������++tot,��ʼ��sum[pos[p]]
cnt[pos[p]]֮�󣬽�pos[p]��Ϊ�½ڵ����һ���
���鼯�������ɣ�����ÿ������������p��q��������
ֱ�Ӷ�p��q���������Ƕ����Ӧ�Ľڵ�pos[p],pos[q]
��������
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
                if(Find(pos[p])==Find(pos[q]))  //һ��Ҫ�����ǲ���ͬһ������ʱ�ٲ���������ֱ������
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
