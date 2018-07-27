/*
线段树
如果将这个billboard逆时针旋转90度，那么h变成线段树的总区间长度，而w就是每个区间的初始值。
题目要求“最上最左”，“最上”其实在线段树中就是最左，“最左”就是挨着贴就行。
其实这个就是用线段树维护区间最大值，然后如果最大值>wi，则递归，一直递归到叶子节点就是答案，
并修改节点值，然后pushUp维护。  递归时因为要求最左，所以左子树优先递归。
*/
#include <stdio.h>
#include <string.h>

const int maxn=200000+10;

int sum[maxn*4],h,n,w;

int Max(int x,int y){
    if(x<y) return y;
    return x;
}

void pushUp(int k){
    sum[k]=Max(sum[k*2],sum[k*2+1]);
}

void build(int k,int l,int r){
    if(l==r){
        sum[k]=w;return ;
    }
    int m=(l+r)/2;
    build(k*2,l,m);
    build(k*2+1,m+1,r);
    pushUp(k);
}

void update(int a,int k,int l,int r,int W){
    if(l==r){
        sum[k]-=W;return ;
    }

}

int query(int k,int l,int r,int W){
    if(l==r){
        sum[k]-=W;return l;
    }
    int m=(l+r)/2,res;
    if(sum[k*2]>=W)
        res=query(k*2,l,m,W);
    else if(sum[k*2+1]>=W)
        res=query(k*2+1,m+1,r,W);
    else res=-1;
    pushUp(k);
    return res;
}

int main()
{
    int i,j,a,res,wi;
    while(scanf("%d%d%d",&h,&w,&n)!=EOF){
        if(h>n) h=n;            //这里h>n时就没用意义了，因为如果给了一个wi比w还要打，那么再多的h也不能放下
        build(1,1,h);           //如果wi<=w，那么n个海报最多也就用n个单位的billboard。
        while(n--){
            scanf("%d",&wi);
            if(wi>w){
                printf("-1\n");
                continue;
            }
            printf("%d\n",query(1,1,h,wi));
        }
    }
    return 0;
}
