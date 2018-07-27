/*
��Ȩ���鼯
*/
#include <stdio.h>
#include <string.h>
#include <math.h>

const int maxn=2000+10;

typedef struct UFSet{
    int par[maxn],rel[maxn];
    void Init(int n){ for(int i=0;i<=n;i++) par[i]=i,rel[i]=0;}
    int Find(int x){
        if(par[x]==x) return x;
        int t=Find(par[x]);
        rel[x]=rel[x]^rel[par[x]];
        return par[x]=t;
    }
    bool Union(int u,int v){        //�÷���ֵ��ȷ���Ƿ�ͬ�ԣ�trueΪͬ�ԣ�falseΪ����
        int pu=Find(u),pv=Find(v);
        if(pu==pv) return rel[u]==rel[v];
        rel[pv]=!(rel[u]^rel[v]);          //�������һ���������ô����һ���������ͬ�����������ܹ����pu��pv�Ĺ�ϵ
        par[pv]=pu;                     //��Ϊpu��u�й�ϵ(rel[u]),pv��v�й�ϵ(rel[v]),��u��vҲһ���������ԵĹ�ϵ
        return false;                    //����pu��pv�Ĺ�ϵ���ܹ��������
    }                                   //v->pv(rel[v]) u->pu(rel[u])   pv->pu(rel[pv])
}UFSet;                                 //       0          0               1
                                        //       0          1               0
                                        //       1          0               0
                                        //       1          1               1
int main()
{
    int i,T,kcase=1,n,q,flag;
    scanf("%d",&T);
    UFSet s;
    while(T--){
        scanf("%d%d",&n,&q);
        s.Init(n);
        flag=1;
        while(q--){
            int a,b;
            scanf("%d%d",&a,&b);
            if(s.Union(a,b))
                flag=0;
        }
        printf("Scenario #%d:\n",kcase++);
        if(flag)
            printf("No suspicious bugs found!\n\n");
        else
            printf("Suspicious bugs found!\n\n");
    }
    return 0;
}
