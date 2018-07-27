/****************
*PID:cdvs1082
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn=200000+5;

typedef struct segment{
    LL sum[maxn*4],add[maxn*4];
    void pushUp(int k){
        sum[k]=sum[k*2]+sum[k*2+1];
    }
    void pushDown(int k,int l,int r){
        int lc=k*2,rc=k*2+1,m=(l+r)/2;
        if(add[k]){
            add[lc]+=add[k];add[rc]+=add[k];
            sum[lc]+=add[k]*(m-l+1);
            sum[rc]+=add[k]*(r-m);
            add[k]=0;
        }
    }
    void build(int k,int l,int r){
        if(l==r){
            scanf("%d",&sum[k]);return ;
        }
        int m=(l+r)/2;
        build(k*2,l,m);
        build(k*2+1,m+1,r);
        pushUp(k);
    }
    void Add(int a,int b,int v,int k,int l,int r){
        if(a<=l && r<=b){
            add[k]+=(LL)v;sum[k]+=(LL)v*(r-l+1);return ;
        }
        pushDown(k,l,r);
        int m=(l+r)/2;
        if(a<=m)
            Add(a,b,v,k*2,l,m);
        if(b>m)
            Add(a,b,v,k*2+1,m+1,r);
        pushUp(k);
    }
    LL ask(int a,int b,int k,int l,int r){
        if(a<=l && r<=b)
            return sum[k];
        pushDown(k,l,r);
        int m=(l+r)/2;
        LL res=0;
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
    int i,j,n,q;
    scanf("%d",&n);
    tree.build(1,1,n);
    scanf("%d",&q);
    while(q--){
        int k,a,b,c;
        scanf("%d",&k);
        if(k==1){
            scanf("%d%d%d",&a,&b,&c);
            tree.Add(a,b,c,1,1,n);
        }else{
            scanf("%d%d",&a,&b);
            printf("%lld\n",tree.ask(a,b,1,1,n));
        }
    }
    return 0;
}
