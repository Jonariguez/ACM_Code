/****************
*PID:uva10635
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=250*250+10;
int a[maxn],b[maxn],p[maxn],q[maxn];

struct Segment{
    int sum[maxn*4];
    void pushUp(int k){
        sum[k]=max(sum[k*2],sum[k*2+1]);
    }
    void build(int k,int l,int r){
        sum[k]=0;
        if(l==r) return ;
        int m=(l+r)/2;
        build(k*2,l,m);
        build(k*2+1,m+1,r);
    }
    void update(int p,int v,int k,int l,int r){
        if(l==r){
            sum[k]=v;return ;
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
        int m=(l+r)/2,res=-1;
        if(a<=m)
            res=max(res,ask(a,b,k*2,l,m));
        if(b>m)
            res=max(res,ask(a,b,k*2+1,m+1,r));
        return res;
    }
}tree;

int main()
{
    int i,j,n,m,T,kcase=1;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&i,&n,&m);
        n++;m++;
        memset(p,0,sizeof(p));
        memset(q,0,sizeof(q));
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
            p[a[i]]=i;
        }
        for(i=1;i<=m;i++){
            scanf("%d",&b[i]);
            q[b[i]]=i;
        }
        tree.build(1,1,n);
        for(i=1;i<=m;i++){
            int x=p[b[i]];
            if(x==0) continue;
            if(x==1)
                tree.update(1,1,1,1,n);
            else {
                int t=tree.ask(1,x-1,1,1,n);
                tree.update(x,t+1,1,1,n);
            }
        }
        printf("Case %d: %d\n",kcase++,tree.ask(1,n,1,1,n));
    }
    return 0;
}
