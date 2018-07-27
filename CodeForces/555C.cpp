/*
两个线段树维护+离线+离散

离散化，然后线段树维护区间最值，区间修改与
区间查询。

在独立思考的情况下A掉此题，爽啊
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn=200000+10;
int index[maxn*4],tot;

struct Operator{
    int x,y,o;
}op[maxn];

int maxx[maxn*8],minx[maxn*8],setx[maxn*8],maxy[maxn*8],miny[maxn*8],sety[maxn*8];

void pushUpx(int k){
    maxx[k]=max(maxx[k*2],maxx[k*2+1]);
    minx[k]=min(minx[k*2],minx[k*2+1]);
}

void pushDownX(int k){
    if(setx[k]>=0){
        setx[k*2]=setx[k*2+1]=setx[k];
        maxx[k*2]=maxx[k*2+1]=maxx[k];
        minx[k*2]=minx[k*2+1]=minx[k];
        setx[k]=-1;
    }
}

void Setx(int a,int b,int v,int k,int l,int r){
    if(minx[k]>v) return ;
    if(a<=l && r<=b){
        if(maxx[k]<=v){
            maxx[k]=minx[k]=setx[k]=v;return ;
        }
        if(l==r) return ;
    }
    pushDownX(k);
    int m=(l+r)/2;
    if(a<=m)
        Setx(a,b,v,k*2,l,m);
    if(b>m)
        Setx(a,b,v,k*2+1,m+1,r);
    pushUpx(k);
}

int askx(int a,int k,int l,int r){
    if(l==r)
        return setx[k];
    pushDownX(k);
    int m=(l+r)/2,res;
    if(a<=m)
        res=askx(a,k*2,l,m);
    else res=askx(a,k*2+1,m+1,r);
    pushUpx(k);
    return res;
}

void pushUpy(int k){
    maxy[k]=max(maxy[k*2],maxy[k*2+1]);
    miny[k]=min(miny[k*2],miny[k*2+1]);
}

void pushDownY(int k){
    if(sety[k]>=0){
        sety[k*2]=sety[k*2+1]=sety[k];
        maxy[k*2]=maxy[k*2+1]=maxy[k];
        miny[k*2]=miny[k*2+1]=miny[k];
        sety[k]=-1;
    }
}

void Sety(int a,int b,int v,int k,int l,int r){
    if(miny[k]>v) return ;
    if(a<=l && r<=b){
        if(maxy[k]<=v){
            maxy[k]=miny[k]=sety[k]=v;return ;
        }
        if(l==r) return ;
    }
    pushDownY(k);
    int m=(l+r)/2;
    if(a<=m)
        Sety(a,b,v,k*2,l,m);
    if(b>m)
        Sety(a,b,v,k*2+1,m+1,r);
    pushUpy(k);
}

int asky(int a,int k,int l,int r){
    if(l==r)
        return sety[k];
    pushDownY(k);
    int m=(l+r)/2,res;
    if(a<=m)
        res=asky(a,k*2,l,m);
    else res=asky(a,k*2+1,m+1,r);
    pushUpy(k);
    return res;
}

void build(int k,int l,int r){
    setx[k]=sety[k]=-1;
    maxx[k]=minx[k]=maxy[k]=miny[k]=0;
    if(l==r) return ;
    int m=(l+r)/2;
    build(k*2,l,m);
    build(k*2+1,m+1,r);
}

int getIndex(int x){
    return (lower_bound(index,index+tot,x)-index)+1;
}


int main()
{
    int i,j,n,q,x,y;
    char c;
    while(scanf("%d%d",&n,&q)!=EOF){
        tot=0;
        int row=0,col=0;
        for(i=0;i<q;i++){
            scanf("%d%d",&op[i].x,&op[i].y);
            scanf(" %c",&c);
            if(c=='L') op[i].o=0;
            else op[i].o=1;
            index[tot++]=op[i].x;index[tot++]=op[i].y;
        }
        sort(index,index+tot);              //我一开始这里竟然没排序，我还傻乎乎地Debug半天。。。
        tot=unique(index,index+tot)-index;
        int m=tot;
        build(1,1,m);
        Setx(1,m,0,1,1,m);
        Sety(1,m,0,1,1,m);
        for(i=0;i<q;i++){
            x=getIndex(op[i].x);y=getIndex(op[i].y);
            if(op[i].o==1){
                int t=askx(x,1,1,m);
                printf("%d\n",op[i].y-t);
                Sety(getIndex(t),y,op[i].x,1,1,m);
                Setx(x,x,op[i].y,1,1,m);
            }else {
                int t=asky(y,1,1,m);
                printf("%d\n",op[i].x-t);
                Setx(getIndex(t),x,op[i].y,1,1,m);
                Sety(y,y,op[i].x,1,1,m);
            }
        }
    }
    return 0;
}

