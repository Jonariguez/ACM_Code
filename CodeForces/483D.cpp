/****************
*PID:483d div2
*Auth:Jonariguez
*****************
���Qi�Ķ����Ʊ�ʾ��ĳλ��Ϊ1��������[Li,Ri]�ڵ�������
�Ķ����Ʊ�ʾ�ĸ�λ�ñ���Ϊ1��
���Qi��ĳ��λ��Ϊ0���������Ӧ��������һ������λ����0��
�����������������˵�����������λ��Ϊ1ʱ���ͻ���޽⡣
�������ֳ�ͻ��ô�ж��أ� �Ǿ����Ȱ�m���������ȷ���1ȥ����
һ�����е�ÿ������Ȼ���m�����������Ƿ���ϣ������Ȼ������
�н⣬�����޽⡣
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=100000+5;

struct segmetn{
    int sum[maxn*4],set[maxn*4],mark[maxn*4];
    void pushUp(int k){
        sum[k]=(sum[k*2]&sum[k*2+1]);
    }
    void pushDown(int k,int l,int r){
        int lc=k*2,rc=k*2+1,m=(l+r)/2;
        if(mark[k]){
            set[lc]|=set[k];set[rc]|=set[k];
            mark[lc]=mark[rc]=1;
            sum[lc]|=set[k];
            sum[rc]|=set[k];
            set[k]=0;
            mark[k]=0;
        }
    }
    void build(int k,int l,int r){
        sum[k]=0;set[k]=0;mark[k]=0;
        if(l==r)
            return ;
        int m=(l+r)/2;
        build(k*2,l,m);
        build(k*2+1,m+1,r);
    }
    void Set(int a,int b,int v,int k,int l,int r){
        if(a<=l && r<=b){
            mark[k]=1;set[k]|=v;sum[k]|=v;return ;
        }
        pushDown(k,l,r);
        int m=(l+r)/2;
        if(a<=m)
            Set(a,b,v,k*2,l,m);
        if(b>m)
            Set(a,b,v,k*2+1,m+1,r);
        pushUp(k);
    }
    int query(int p,int k,int l,int r){
        if(l==r)
            return sum[k];
        pushDown(k,l,r);
        int m=(l+r)/2,res;
        if(p<=m)
           res=query(p,k*2,l,m);
        else
           res=query(p,k*2+1,m+1,r);
        pushUp(k);
        return res;
    }
    int ask(int a,int b,int k,int l,int r){
        if(a<=l && r<=b)
            return sum[k];
        pushDown(k,l,r);
        int m=(l+r)/2,res=(1<<30)-1;
        if(a<=m)
           res&=ask(a,b,k*2,l,m);
        if(b>m)
           res&=ask(a,b,k*2+1,m+1,r);
        pushUp(k);
        return res;
    }
}tree;

int L[maxn],R[maxn],Q[maxn],res[maxn];

int main()
{
    int i,j,n,m;
    scanf("%d%d",&n,&m);
    tree.build(1,1,n);
    for(i=1;i<=m;i++){
        scanf("%d%d%d",&L[i],&R[i],&Q[i]);
        tree.Set(L[i],R[i],Q[i],1,1,n);
    }
    int yes=1;
    for(i=1;i<=m;i++)
        if(tree.ask(L[i],R[i],1,1,n)!=Q[i]){
            yes=0;break;
        }
  /*
    for(i=0;i<30;i++){
        tree[i].build(1,1,n);
        tree[i].Set(1,n,0,1,1,n);
    }
    int yes=1;
    int l,r,q,temp,t;
    for(i=1;i<=m;i++){
        l=L[i];r=R[i];q=Q[i];
        for(j=0;j<30 && yes;j++){
            if((q>>j)&1)
                tree[j].Set(l,r,1,1,1,n);
            else{
                temp=tree[j].ask(l,r,1,1,n);
                if(temp==r-l+1 && temp!=0){
                    yes=0;break;
                }
            }
        }
    }*/
    if(yes==0){
        printf("NO\n");return 0;
    }
    puts("YES");
  /*  for(i=1;i<=n;i++){
        temp=0;
        for(j=0;j<30;j++){
            t=tree[j].query(i,1,1,n);
            if(t) temp|=(1<<j);
        }
        res[i]=temp;
    }*/
    for(i=1;i<=n;i++)
        res[i]=tree.query(i,1,1,n);
    for(i=1;i<=n;i++)
        printf("%d ",res[i]);
    return 0;
}
