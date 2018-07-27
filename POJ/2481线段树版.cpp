/*
线段树
已经用BIT的方法AC了，不过为了掌握线段树的思想，还是用线段树敲一下吧。
很简单，也是先排序，把“最能包含别的线段的线段”插入，维护一个min值，
因为要求的是公共的比自己的大的。在插入时查询比自己大的有几个(即min)就行了。
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn=100000;
int sum[(maxn+10)*4],vis[maxn+10];

struct pp{
    int s,e,id;
}seg[maxn+10];

int cmp(const pp &x,const pp &y){   //注意排序的方式，是先按区间右端降序，相等则按左端升序
    if(x.e==y.e)
        return x.s<y.s;
    return x.e>y.e;
}

void pushUp(int k){
    sum[k]=sum[k*2]+sum[k*2+1];
}

void update(int a,int b,int k,int l,int r){
    if(a<=l && r<=b){
        sum[k]++;return ;
    }
    int m=(l+r)/2;
    if(a<=m)
        update(a,b,k*2,l,m);
    if(b>m)
        update(a,b,k*2+1,m+1,r);
    pushUp(k);
}

int ask(int a,int b,int k,int l,int r){
    if(a<=l && r<=b)
        return sum[k];
    int m=(l+r)/2,res=1000000;
    if(a<=m)
        res=min(res,ask(a,b,k*2,l,m));
    if(b>m)
        res=min(res,ask(a,b,k*2+1,m+1,r));
    return res;
}

int main()
{
    int i,j,n,res;
    while(scanf("%d",&n),n){
        for(i=0;i<n;i++){
            scanf("%d%d",&seg[i].s,&seg[i].e);
            seg[i].id=i;
        }
        sort(seg,seg+n,cmp);
        memset(sum,0,sizeof(sum));
        memset(vis,0,sizeof(vis));
        for(i=0;i<n;i++){
            if(i && seg[i].s==seg[i-1].s && seg[i].e==seg[i-1].e){   //要处理相等的情况
                vis[seg[i].id]=vis[seg[i-1].id];     //这里可以用vis[seg[i].id]=vis[seg[i-1].id],而不用cnt，好机智啊
            }else vis[seg[i].id]=ask(seg[i].s,seg[i].e,1,0,maxn);
            update(seg[i].s,seg[i].e,1,0,maxn);
        }

        for(i=0;i<n;i++)
            printf("%d%c",vis[i],i==n-1?'\n':' ');
    }
    return 0;
}
