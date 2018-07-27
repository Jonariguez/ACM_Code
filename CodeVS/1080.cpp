/****************
*PID:cdvs1080
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=100000+5;

typedef struct segment{
    int sum[maxn*4];
    void pushUp(int k){
        sum[k]=sum[k*2]+sum[k*2+1];
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
    void update(int p,int v,int k,int l,int r){
        if(l==r){
            sum[k]+=v;
            return ;
        }
        int m=(l+r)/2;
        if(p<=m)
            update(p,v,k*2,l,m);
        else update(p,v,k*2+1,m+1,r);
        pushUp(k);
    }
    int ask(int a,int b,int k,int l,int r){
        if(a<=l && r<=b)
            return sum[k];
        int m=(l+r)/2;
        int res=0;
        if(a<=m) res+=ask(a,b,k*2,l,m);
        if(b>m) res+=ask(a,b,k*2+1,m+1,r);
        return res;
    }
}Tree;

Tree tree;

int main()
{
    int i,j,n,m;
    scanf("%d",&n);
    tree.build(1,1,n);
    scanf("%d",&m);
    while(m--){
        int a,b,k;
        scanf("%d%d%d",&k,&a,&b);
        if(k==1)
            tree.update(a,b,1,1,n);
        else printf("%d\n",tree.ask(a,b,1,1,n));
    }
    return 0;
}
