/****************
*PID:cdvs1690
*Auth:Jonariguez
*****************
�ڵ�k�ĳ���Ϊr-l+1�Ļ������俪�ŵĵ���sum[k]����
�����һ�°�ť�����������ŵĵƵĸ����ͱ��sum[k]=r-l+1-sum[k]
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=100000+5;

typedef struct segment{
    int sum[maxn*4],add[maxn*4];
    void pushUp(int k){
        sum[k]=sum[k*2]+sum[k*2+1];
    }
    void pushDown(int k,int l,int r){
        int lc=k*2,rc=k*2+1,m=(l+r)/2;
        if(add[k]&1){
            add[lc]+=add[k];
            add[rc]+=add[k];
            if(add[k]&1){           //����������λ���ı�Ƶ�״̬
                sum[lc]=(m-l+1)-sum[lc];
                sum[rc]=(r-m)-sum[rc];
            }
            add[k]=0;
        }else add[k]=0;
    }
    void build(int k,int l,int r){
        add[k]=sum[k]=0;
        if(l==r)
            return ;
        int m=(l+r)/2;
        build(k*2,l,m);
        build(k*2+1,m+1,r);
    }
    void Set(int a,int b,int k,int l,int r){
        if(a<=l && r<=b){
            add[k]++;sum[k]=(r-l+1)-sum[k];return ;
        }
        pushDown(k,l,r);
        int m=(l+r)/2;
        if(a<=m)
            Set(a,b,k*2,l,m);
        if(b>m)
            Set(a,b,k*2+1,m+1,r);
        pushUp(k);
    }
    int ask(int a,int b,int k,int l,int r){
        if(a<=l && r<=b)
            return sum[k];
        pushDown(k,l,r);
        int m=(l+r)/2,res=0;
        if(a<=m)
            res+=ask(a,b,k*2,l,m);
        if(b>m)
            res+=ask(a,b,k*2+1,m+1,r);
        pushUp(k);
        return res;
    }
}Tree;

Tree tree;

int main()
{
    int i,j,n,m,res;
    scanf("%d%d",&n,&m);
    tree.build(1,1,n);
    while(m--){
        int k,a,b;
        scanf("%d%d%d",&k,&a,&b);
        if(k==0)
            tree.Set(a,b,1,1,n);
        else printf("%d\n",tree.ask(a,b,1,1,n));
    }
    return 0;
}
