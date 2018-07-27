/*
线段树
希望1A
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn=100000+10;

int minv[maxn*4],n,a[maxn];

void pushUp(int k){
    minv[k]=min(minv[k*2],minv[k*2+1]);
}

//因为会直接更新到叶子节点，所以用不着lazy思想
void update(int p,int v,int k,int l,int r){
    if(l==r){
        minv[k]=v;return ;
    }
    int m=(l+r)/2;
    if(p<=m)
        update(p,v,k*2,l,m);
    else
        update(p,v,k*2+1,m+1,r);
    pushUp(k);
}

int ask(int a,int b,int k,int l,int r){
    if(a<=l && r<=b)
        return minv[k];
    int m=(l+r)/2,res=100005;
    if(a<=m)
        res=min(res,ask(a,b,k*2,l,m));
    if(b>m)
        res=min(res,ask(a,b,k*2+1,m+1,r));
    return res;
}

int s[30];

int main()
{
    int i,j,k,x,y,q;
    char str[40];
    scanf("%d%d",&n,&q);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        update(i,a[i],1,1,n);
    }
    while(q--){
        for(i=0;i<6;i++)
            scanf(" %c",&str[i]);
        if(str[0]=='q'){
            scanf("%d,%d)",&x,&y);
            printf("%d\n",ask(x,y,1,1,n));
        }else {
            int tot=0;char c;
            for(;;){
                scanf("%d%c",&s[tot++],&c);
                if(c==')') break;
            }
            //在a[]的内部直接实现循环移动
            int t=a[s[0]],d;
            for(i=tot-1;i>=0;i--){
                d=a[s[i]];a[s[i]]=t;
                t=d;
            }
            //然后移动的位置(即s数组里的数)对应的数已经变了，只需要重新update一下就好
            for(i=0;i<tot;i++)
                update(s[i],a[s[i]],1,1,n);
        }
    }
    return 0;
}
