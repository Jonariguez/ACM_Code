/****************
*PID:uva1151
*Auth:Jonariguez
*****************
���ž���P358
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

const int maxn=1000+10;
const ll INF=1e18;
int n,m,q,par[maxn],x[maxn],y[maxn];
struct pp{
    int a,b,v;
    bool operator < (const pp &r) const {
        return v<r.v;
    }
}s[maxn*maxn];

//�����ײ�
struct sub{
    int a[maxn],cost,k;
}Q[10];

void Init(){
    for(int i=0;i<=n;i++)
        par[i]=i;
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

ll Kruskal(int op){
    int i,j,cnt=0;
    ll res=0;
    Init();
    for(i=0;i<q;i++){       //ö���ײͣ�Ȼ����ײ���ĵ�Union�������������cost��
        if((op>>i)&1){
            for(j=1;j<Q[i].k;j++)
                if(Union(Q[i].a[0],Q[i].a[j]))
                    cnt++;          // cnt�Ʊ�
            res+=Q[i].cost;
        }
    }
    if(cnt==n-1) return res;
    for(i=0;i<m;i++){
        if(Union(s[i].a,s[i].b)){
            res+=s[i].v;
            if(++cnt==n-1) return res;
        }
    }
}

int main()
{
    int i,j,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&q);
        for(i=0;i<q;i++){
            scanf("%d%d",&Q[i].k,&Q[i].cost);
            for(j=0;j<Q[i].k;j++)
                scanf("%d",&Q[i].a[j]);
        }
        m=0;
        for(i=1;i<=n;i++){              //��Ϊ��Ŀ��point�����1~n����������ô�1��ʼ��һ��ʼ��0��ʼ��debug��һ��
            scanf("%d%d",&x[i],&y[i]);
            for(j=1;j<i;j++){
                s[m].a=j;s[m].b=i;s[m++].v=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
            }
        }
        sort(s,s+m);
        Init();
        int cnt=0,tot=m;
        m=0;
        ll res=0;
        for(i=0;i<tot;i++){         //����һ��MST��������n-1���ߣ���ôû���õ��ı���ʹ���ײ͵�����������ܻ��õ�
            if(Union(s[i].a,s[i].b)){
                s[m].a=s[i].a;s[m].b=s[i].b;s[m++].v=s[i].v;
                res+=s[i].v;
                if(++cnt==n-1) break;
            }
        }
        for(i=1;i<(1<<q);i++)       //ö��ʹ�õ��ײ͵����
            res=min(res,Kruskal(i));
        printf("%lld\n",res);
        if(T)
            printf("\n");
    }
    return 0;
}


