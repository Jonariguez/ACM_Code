/*
线段树
就因为k*2,后面少写了一个+1,WA到死
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn=1000000+10;
int n;

int sum[22][maxn*4],maxv[22][maxn*4],minv[22][maxn*4],set[22][maxn*4],add[22][maxn*4];

void pushUp(int i,int k,int l,int r){
    if(l>=r) return ;
    sum[i][k]=sum[i][k*2]+sum[i][k*2+1];
    maxv[i][k]=max(maxv[i][k*2],maxv[i][k*2+1]);
    minv[i][k]=min(minv[i][k*2],minv[i][k*2+1]);
}

void pushDown(int i,int k,int l,int r){
    if(l>=r) return ;
    int m=(l+r)/2;
    if(set[i][k]!=-1){
        set[i][k*2]=set[i][k*2+1]=set[i][k];
        sum[i][k*2]=set[i][k]*(m-l+1);sum[i][k*2+1]=set[i][k]*(r-m);
        maxv[i][k*2]=maxv[i][k*2+1]=minv[i][k*2]=minv[i][k*2+1]=set[i][k];
        add[i][k*2]=add[i][k*2+1]=0;
        set[i][k]=-1;
    }
    if(add[i][k]){
        sum[i][k*2]+=add[i][k]*(m-l+1);sum[i][k*2+1]+=add[i][k]*(r-m);
        maxv[i][k*2]+=add[i][k];maxv[i][k*2+1]+=add[i][k];
        minv[i][k*2]+=add[i][k];minv[i][k*2+1]+=add[i][k];
        add[i][k*2]+=add[i][k];add[i][k*2+1]+=add[i][k];
        add[i][k]=0;
    }
}

void build(int i,int k,int l,int r){
    set[i][k]=-1;add[i][k]=0;sum[i][k]=maxv[i][k]=minv[i][k]=0;
    if(l==r){
        return ;
    }
    int m=(l+r)/2;
    build(i,k*2,l,m);
    build(i,k*2+1,m+1,r);       //这里少写个+1
    pushUp(i,k,l,r);
}

void Set(int i,int a,int b,int k,int l,int r,int v){
    if(a<=l && r<=b){
        set[i][k]=v;add[i][k]=0;
        sum[i][k]=v*(r-l+1);
        maxv[i][k]=minv[i][k]=v;
        return ;
    }
    pushDown(i,k,l,r);
    int m=(l+r)/2;
    if(a<=m)
        Set(i,a,b,k*2,l,m,v);
    if(b>m)
        Set(i,a,b,k*2+1,m+1,r,v);       //shit，这里也少写了个+1
    pushUp(i,k,l,r);
}

void Add(int i,int a,int b,int k,int l,int r,int v){
    if(a<=l && r<=b){
        add[i][k]+=v;
        sum[i][k]+=v*(r-l+1);
        maxv[i][k]+=v;minv[i][k]+=v;
        return ;
    }
    int m=(l+r)/2;
    pushDown(i,k,l,r);
    if(a<=m)
        Add(i,a,b,k*2,l,m,v);
    if(b>m)
        Add(i,a,b,k*2+1,m+1,r,v);
    pushUp(i,k,l,r);
}

int sumres,maxres,minres;

void query(int i,int a,int b,int k,int l,int r){
    if(a<=l && r<=b){
        sumres+=sum[i][k];
        maxres=max(maxres,maxv[i][k]);minres=min(minres,minv[i][k]);return ;
    }
    pushDown(i,k,l,r);
    int m=(l+r)/2;
    if(a<=m)
        query(i,a,b,k*2,l,m);
    if(b>m)
        query(i,a,b,k*2+1,m+1,r);
   // pushUp(i,k,l,r);
}

int main()
{
    #ifdef Online_Judge
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // Online_Judge
    int i,j,c,r,m,op,x1,x2,y1,y2,v;
    int T;
    while(scanf("%d%d%d",&r,&c,&m)!=EOF){
        n=c*r;
        for(i=1;i<=r;i++)
            build(i,1,1,n);
        while(m--){
            scanf("%d",&op);
            if(op==1){
                scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&v);
                for(i=x1;i<=x2;i++)
                    Add(i,y1,y2,1,1,n,v);
            }else if(op==2){
                scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&v);
                for(i=x1;i<=x2;i++)
                    Set(i,y1,y2,1,1,n,v);
            }else{
                scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
                sumres=0;maxres=-1000000009;minres=1000000009;
                for(i=x1;i<=x2;i++)
                    query(i,y1,y2,1,1,n);
                printf("%d %d %d\n",sumres,minres,maxres);
            }
        }
    }
    return 0;
}

