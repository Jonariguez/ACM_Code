/****************
*PID:hdu5634
*Auth:Jonariguez
*****************
mark[k]:标记该区间的数是否全部一样，如果一样的话则
等于这个数，否则等于0。
那么对于操作1，遇到区间值全部相等，则直接修改区间和
和mark
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <cctype>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=300000+5;
const int maxa=10000000+2;
int phi[maxa];

void phi_table(){
    phi[1]=1;
    LL i,j;
    for(i=2;i<=10000000;i++){
        if(!phi[i]){
            for(j=i;j<=10000000;j+=i){
                if(!phi[j]) phi[j]=j;
                phi[j]=phi[j]/i*(i-1);
            }
        }
    }
}

struct Segment{
    LL sum[maxn*4],mark[maxn*4];
    void pushUp(int k){
        sum[k]=sum[k*2]+sum[k*2+1];
        if(mark[k*2] && mark[k*2]==mark[k*2+1])
            mark[k]=mark[k*2];
        else mark[k]=0;
    }
    void pushDown(int k,int l,int r){
        if(mark[k]){
            int lc=k*2,rc=k*2+1,m=(l+r)/2;
            mark[lc]=mark[rc]=mark[k];
            sum[lc]=mark[k]*(m-l+1);
            sum[rc]=mark[k]*(r-m);       //这里结束之后并不把mark[k]置0，因为mark的含义和lazy思想不太相同，
        }    //如果这个区间全部一样(mark[k]!=0)，那么它的子区间也一样(传递),那么该区间保持一样(即mark不置0)
    }
    void build(int k,int l,int r){
        if(l==r){
            scanf("%I64d",&sum[k]);mark[k]=sum[k];return ;
        }
        int m=(l+r)/2;
        build(k*2,l,m);
        build(k*2+1,m+1,r);
        pushUp(k);
    }
    void Set(int a,int b,LL v,int k,int l,int r){
        if(a<=l && r<=b){
            mark[k]=v;sum[k]=v*(r-l+1);return ;
        }
        pushDown(k,l,r);
        int m=(l+r)/2;
        if(a<=m)
            Set(a,b,v,k*2,l,m);
        if(b>m)
            Set(a,b,v,k*2+1,m+1,r);
        pushUp(k);
    }
    void update(int a,int b,int k,int l,int r){
        if(l==r){
            sum[k]=phi[sum[k]];
            mark[k]=sum[k];     //不要忘了更新mark[k]的值，WA。。。
            return ;
        }
        if(a<=l && r<=b && mark[k]){    //该区间全部一样则可以共同更新。
            mark[k]=(LL)phi[mark[k]];
            sum[k]=mark[k]*(r-l+1);
            return ;
        }
        pushDown(k,l,r);
        int m=(l+r)/2;
        if(a<=m)
            update(a,b,k*2,l,m);
        if(b>m)
            update(a,b,k*2+1,m+1,r);
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
}tree;

int main()
{
    int i,j,n,m,T;
    phi_table();
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        tree.build(1,1,n);
        int o,l,r,x;
        while(m--){
            scanf("%d",&o);
            if(o==1){
                scanf("%d%d",&l,&r);
                tree.update(l,r,1,1,n);
            }else if(o==2){
                scanf("%d%d%d",&l,&r,&x);
                tree.Set(l,r,(LL)x,1,1,n);
            }else {
                scanf("%d%d",&l,&r);
                printf("%I64d\n",tree.ask(l,r,1,1,n));
            }
        }
    }
    return 0;
}
