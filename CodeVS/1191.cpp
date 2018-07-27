/****************
*PID:cdvs1191
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=200000+5;

struct segment{
    int sum[maxn*4],add[maxn*4],set[maxn*4];
    void pushUp(int k){
        sum[k]=sum[k*2]+sum[k*2+1];
    }
    void pushDown(int k,int l,int r){
        int lc=k*2,rc=k*2+1,m=(l+r)/2;
        if(set[k]>=0){
            set[lc]=set[rc]=set[k];
            sum[lc]=set[k]*(m-l+1);
            sum[rc]=set[k]*(r-m);
            set[k]=-1;
            add[lc]=add[rc]=0;
        }
        if(add[k]){
            add[lc]+=add[k];add[rc]+=add[k];
            sum[lc]+=add[k]*(m-l+1);
            sum[rc]+=add[k]*(r-m);
            add[k]=0;
        }
    }
    void build(int k,int l,int r){
        sum[k]=add[k]=0;set[k]=-1;
        if(l==r)
            return ;
        int m=(l+r)/2;
        build(k*2,l,m);
        build(k*2+1,m+1,r);
    }
    void insert(int a,int b,int v,int k,int l,int r){
        if(a<=l && r<=b){
            add[k]+=v;sum[k]+=v*(r-l+1);return ;
        }
        pushDown(k,l,r);
        int m=(l+r)/2;
        if(a<=m)
            insert(a,b,v,k*2,l,m);
        if(b>m)
            insert(a,b,v,k*2+1,m+1,r);
        pushUp(k);
    }
    void Set(int a,int b,int v,int k,int l,int r){
        if(a<=l && r<=b){
            set[k]=v;sum[k]=v*(r-l+1);return ;
        }
        pushDown(k,l,r);
        int m=(l+r)/2;
        if(a<=m)
            Set(a,b,v,k*2,l,m);
        if(b>m)
            Set(a,b,v,k*2+1,m+1,r);
        pushUp(k);
    }
    int ask(int a,int b,int k,int l,int r){
        if(a<=l && r<=b)
            return sum[k];
        pushDown(k,l,r);
        int m=(l+r)/2,res=0;
        if(a<=m) res+=ask(a,b,k*2,l,m);
        if(b>m) res+=ask(a,b,k*2+1,m+1,r);
        pushUp(k);
        return res;
    }
}tree;

int main()
{
    int i,j,n,m;
    scanf("%d%d",&n,&m);
    tree.build(1,1,n);
    tree.Set(1,n,1,1,1,n);
    while(m--){
        int a,b;
        scanf("%d%d",&a,&b);
        tree.Set(a,b,0,1,1,n);
        printf("%d\n",tree.ask(1,n,1,1,n));
    }
    return 0;
}
