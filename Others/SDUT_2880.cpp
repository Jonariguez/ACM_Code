/****************
*PID:sdut_2880
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

const int maxn=100000+5;
ll sum[maxn*4],add[maxn*4],set[maxn*4];

void pushUp(int k){
    sum[k]=sum[k*2]+sum[k*2+1];
}

void pushDown(int k,int l,int r){
    int m=(l+r)/2,lc=k*2,rc=k*2+1;
    if(set[k]!=-1){
        set[lc]=set[rc]=set[k];
        add[lc]=add[rc]=0;
        sum[lc]=set[k]*(m-l+1);sum[rc]=set[k]*(r-m);
        set[k]=-1;
    }
    if(add[k]){
        sum[lc]+=add[k]*(m-l+1);
        sum[rc]+=add[k]*(r-m);
        add[lc]+=add[k];add[rc]+=add[k];
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

void Set(int a,int b,ll v,int k,int l,int r){
    if(a<=l && r<=b){
        set[k]=v;sum[k]=v*(r-l+1);add[k]=0;
        return ;
    }
    pushDown(k,l,r);
    int m=(l+r)/2;
    if(a<=m)
        Set(a,b,v,k*2,l,m);
    if(b>m)
        Set(a,b,v,k*2+1,m+1,r);
    pushUp(k);
}

void Add(int a,int b,ll v,int k,int l,int r){
    if(a<=l && r<=b){
        add[k]+=v;sum[k]+=v*(r-l+1);
        return ;
    }
    pushDown(k,l,r);
    int m=(l+r)/2;
    if(a<=m)
        Add(a,b,v,k*2,l,m);
    if(b>m)
        Add(a,b,v,k*2+1,m+1,r);
    pushUp(k);
}

ll ask(int a,int b,int k,int l,int r){
    if(a<=l && r<=b)
        return sum[k];
    pushDown(k,l,r);
    int m=(l+r)/2;
    ll res=0;
    if(a<=m)
        res+=ask(a,b,k*2,l,m);
    if(b>m)
        res+=ask(a,b,k*2+1,m+1,r);
    pushUp(k);
    return res;
}




int main()
{
    int i,T,j,n,m;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        build(1,1,n);
        int a,b,t=0,t1;
        ll res=0;
        for(i=0;i<m;i++){
            scanf("%d%d%d",&t1,&a,&b);
            Add(1,n,t1-t,1,1,n);
            res+=ask(a,b,1,1,n);
            Set(a,b,0,1,1,n);
            t=t1;
        }
        printf("%lld\n",res);
    }
    return 0;
}
