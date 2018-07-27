/*
POJ��100��
*/
#include <stdio.h>
#include <string.h>

const int maxn=50000+10;

typedef struct UFSet{
    int par[maxn],rel[maxn];
    void Init(int n){ for(int i=0;i<=n;i++) par[i]=i,rel[i]=0;}
    int Find(int x){
        if(par[x]==x) return x;
        int t=Find(par[x]);
        rel[x]=(rel[x]+rel[par[x]])%3;
        return par[x]=t;
    }
    void Union(int u,int v,int pu,int pv,int d){
        rel[pu]=(rel[v]-rel[u]+2+d)%3;      //ע�����������pu��pv����Ҫ����.   �ҷ��ֺϲ�ʱrel[pu]��rel[u],rel[v]��ͬ����
        par[pu]=pv;                         //������ôΪʲô�ܾ����أ�pv��v�й�ϵ��pu��u�й�ϵ����u��v���й�ϵ������u��v���ܾ���
                                            //pu��pv�Ĺ�ϵ����rel[pu]
    }
}UFSet;

int main()
{
    int i,j,k,n,a,b,pa,pb,d;
    scanf("%d%d",&n,&k);
    UFSet s;
    s.Init(n);
    int res=0;
    while(k--){
        scanf("%d%d%d",&d,&a,&b);
        if(a>n || b>n || a==b && d==2){ res++;continue;}
        pa=s.Find(a);pb=s.Find(b);
        if(pa!=pb)
            s.Union(a,b,pa,pb,d);
        else if((s.rel[b]+d+2)%3!=s.rel[a]) res++;
    }
    printf("%d\n",res);
    return 0;
}
