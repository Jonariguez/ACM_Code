/*
�߶���
�Ѿ���BIT�ķ���AC�ˣ�����Ϊ�������߶�����˼�룬�������߶�����һ�°ɡ�
�ܼ򵥣�Ҳ�������򣬰ѡ����ܰ�������߶ε��߶Ρ����룬ά��һ��minֵ��
��ΪҪ����ǹ����ı��Լ��Ĵ�ġ��ڲ���ʱ��ѯ���Լ�����м���(��min)�����ˡ�
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn=100000;
int sum[(maxn+10)*4],vis[maxn+10];

struct pp{
    int s,e,id;
}seg[maxn+10];

int cmp(const pp &x,const pp &y){   //ע������ķ�ʽ�����Ȱ������Ҷ˽���������������
    if(x.e==y.e)
        return x.s<y.s;
    return x.e>y.e;
}

void pushUp(int k){
    sum[k]=sum[k*2]+sum[k*2+1];
}

void update(int a,int b,int k,int l,int r){
    if(a<=l && r<=b){
        sum[k]++;return ;
    }
    int m=(l+r)/2;
    if(a<=m)
        update(a,b,k*2,l,m);
    if(b>m)
        update(a,b,k*2+1,m+1,r);
    pushUp(k);
}

int ask(int a,int b,int k,int l,int r){
    if(a<=l && r<=b)
        return sum[k];
    int m=(l+r)/2,res=1000000;
    if(a<=m)
        res=min(res,ask(a,b,k*2,l,m));
    if(b>m)
        res=min(res,ask(a,b,k*2+1,m+1,r));
    return res;
}

int main()
{
    int i,j,n,res;
    while(scanf("%d",&n),n){
        for(i=0;i<n;i++){
            scanf("%d%d",&seg[i].s,&seg[i].e);
            seg[i].id=i;
        }
        sort(seg,seg+n,cmp);
        memset(sum,0,sizeof(sum));
        memset(vis,0,sizeof(vis));
        for(i=0;i<n;i++){
            if(i && seg[i].s==seg[i-1].s && seg[i].e==seg[i-1].e){   //Ҫ������ȵ����
                vis[seg[i].id]=vis[seg[i-1].id];     //���������vis[seg[i].id]=vis[seg[i-1].id],������cnt���û��ǰ�
            }else vis[seg[i].id]=ask(seg[i].s,seg[i].e,1,0,maxn);
            update(seg[i].s,seg[i].e,1,0,maxn);
        }

        for(i=0;i<n;i++)
            printf("%d%c",vis[i],i==n-1?'\n':' ');
    }
    return 0;
}
