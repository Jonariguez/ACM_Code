#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;

const int maxn=50000+10;
int minn[maxn*4],maxx[maxn*4];

void pushUp(int k){
    minn[k]=min(minn[k*2],minn[k*2+1]);
    maxx[k]=max(maxx[k*2],maxx[k*2+1]);
}

void build(int k,int l,int r){
    if(l==r){
        int t;
        scanf("%d",&t);
        minn[k]=maxx[k]=t;
    }
    else {
        int m=(l+r)/2;
        build(k*2,l,m);
        build(k*2+1,m+1,r);pushUp(k);
    }

}

int maxv,minv;

void query(int a,int b,int k,int l,int r){  //因为同时求最大值和最小值，所以不能采用返回值的方式了，而是用全局变量
    if(a<=l && b>=r){
        minv=min(minv,minn[k]);
        maxv=max(maxv,maxx[k]);
        return ;
    }
    int m=(l+r)/2;
    if(a<=m)    query(a,b,k*2,l,m);
    if(b>m)     query(a,b,k*2+1,m+1,r);
}

int main()
{
    int n,q,a,b;
    scanf("%d%d",&n,&q);
    build(1,1,n);
    while(q--){
        scanf("%d%d",&a,&b);
        maxv=-1;minv=1000000+2;  //注意minv初始值的大小
        query(a,b,1,1,n);
        printf("%d\n",maxv-minv);
    }
    return 0;
}
