#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn=100000+10;

int maxv[maxn*4],minv[maxn*4],set[maxn*4];

void pushUp(int k){
    maxv[k]=max(maxv[k*2],maxv[k*2+1]);
    minv[k]=min(minv[k*2],minv[k*2+1]);
}

void pushDown(int k){
    if(set[k]!=-1){
        int lc=k*2,rc=k*2+1;
        set[lc]=set[rc]=set[k];
        maxv[lc]=maxv[rc]=maxv[k];
        minv[lc]=minv[rc]=minv[k];
        set[k]=-1;
    }
}

void build(int k,int l,int r){
    set[k]=0;
    if(l==r){
        maxv[k]=minv[k]=0;return ;
    }
    int m=(l+r)/2;
    build(k*2,l,m);
    build(k*2+1,m+1,r);
    pushUp(k);
}

int res;

void update(int a,int b,int h,int k,int l,int r){
        if(minv[k]>h)
            return ;
    if(a<=l && r<=b){
        if(maxv[k]<=h){
            maxv[k]=minv[k]=h;set[k]=h;
            res+=r-l+1;return ;
        }
        if(l==r) return ;
    }
    pushDown(k);
    int m=(l+r)/2,res=0;
    if(a<=m)
        update(a,b,h,k*2,l,m);
    if(b>m)
        update(a,b,h,k*2+1,m+1,r);
    pushUp(k);
}

/*
int ask(int a,int b,int h,int k,int l,int r){
    if(a<=l && r<=b){
    //    printf("maxv[%d]=%d , minv[%d]=%d , h=%d\n",k,maxv[k],k,minv[k],h);
    //    printf("l=%d,r=%d\n",l,r);
        if(maxv[k]<=h) return r-l+1;
        if(minv[k]>=h) return 0;
        if(l==r) return 0;
    }
    pushDown(k);
    int m=(l+r)/2,res=0;
    if(a<=m)
        res+=ask(a,b,h,k*2,l,m);
    if(b>m)
        res+=ask(a,b,h,k*2+1,m+1,r);
    pushUp(k);
    return res;
}*/

int main()
{
    int i,j,k,n,l,r,h,T;
    scanf("%d",&T);
    while(scanf("%d",&n)!=EOF && n){
        build(1,1,100000);
        res=0;
        for(i=0;i<n;i++){
            scanf("%d%d%d",&l,&r,&h);
          //  res+=ask(l+1,r,h,1,1,100001);
            update(l+1,r,h,1,1,100001);
        }
        printf("%d\n",res);
    }
    return 0;
}
