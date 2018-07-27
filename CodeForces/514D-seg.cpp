/****************
*PID:514d div2
*Auth:Jonariguez
*****************
Ïß¶ÎÊ÷+¶þ·Ö
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=100000+5;
const int INF=1e9;
const int maxm=7;

typedef struct segment{
    int sum[maxn*4];
    void pushUp(int k){
        sum[k]=max(sum[k*2],sum[k*2+1]);
    }
    void build(int k,int l,int r){
        if(l==r) return ;
        sum[k]=0;
        int m=(l+r)/2;
        build(k*2,l,m);
        build(k*2+1,m+1,r);
    }
    void Insert(int p,int v,int k,int l,int r){
        if(l==r){
            sum[k]=v;return ;
        }
        int m=(l+r)/2;
        if(p<=m) Insert(p,v,k*2,l,m);
        else Insert(p,v,k*2+1,m+1,r);
        pushUp(k);
    }
    int ask(int a,int b,int k,int l,int r){
        if(a<=l && r<=b)
            return sum[k];
        int m=(l+r)/2,res=0;
        if(a<=m)
            res=max(res,ask(a,b,k*2,l,m));
        if(b>m)
            res=max(res,ask(a,b,k*2+1,m+1,r));
        return res;
    }
}Tree;

Tree tree[maxm];
int ans[maxm],temp[maxm],n,m,k;

bool C(int p1,int p2){
    int i,j,sum=0;
    for(i=1;i<=m;i++)
        sum+=(temp[i]=tree[i].ask(p1,p2,1,1,n));
    return sum<=k;
}

int main()
{
    int i,j,v,x;
    while(scanf("%d%d%d",&n,&m,&k)!=EOF){
        for(i=1;i<=m;i++) tree[i].build(1,1,n);
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                scanf("%d",&v);
                tree[j].Insert(i,v,1,1,n);
            }
        }
        if(n==1){
            int sum=0;
            for(i=1;i<=m;i++)
                sum+=(temp[i]=tree[i].ask(1,1,1,1,n));
            if(sum>k)
                for(i=1;i<=m;i++) printf("0 ");
            else for(i=1;i<=m;i++) printf("%d ",temp[i]);
            puts("");
            continue;
        }
     /*   while(1){
            int a,b;
            scanf("%d%d",&a,&b);
            printf("%d\n",tree[1].ask(a,b,1,1,n));
        }*/
        int l,r,res=0;
        for(i=1;i<=n;i++){
            l=i;r=n+1;
            while(l<r-1){
                int M=(l+r)/2;
                if(C(i,M))
                    l=M;
                else r=M-1;
            }
           // printf("i=%d l=%d\n",i,l);
            if(l-i+1>res){
                res=l-i+1;
                for(j=1;j<=m;j++) ans[j]=tree[j].ask(i,l,1,1,n);
            }
        }
        for(i=1;i<=m;i++)
            printf("%d ",ans[i]);
        puts("");
    }
    return 0;
}
