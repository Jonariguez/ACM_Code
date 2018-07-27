/*
轮廓周长：线段树+扫描线
还用到了区间合并，left,right的作用
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;

const int maxn=10000+10;
int sum[maxn*8],cover[maxn*8],cnt[maxn*8],index[maxn*2];
short left[maxn*8],right[maxn*8];

struct Line{
    int x,y1,y2;
    bool left;
}lines[maxn*2];

int cmp(const Line &a,const Line &b){
    if(a.x==b.x)
        return a.left>b.left;  //left也有影响
    return a.x<b.x;
}

void build(int k,int l,int r){
    sum[k]=cover[k]=cnt[k]=0;
    if(l==r)
        return ;
    int m=(l+r)/2;
    build(k*2,l,m);
    build(k*2+1,m+1,r);
}

void pushUp(int k,int l,int r){
    if(cover[k]){
        sum[k]=r-l+1;
        left[k]=right[k]=1;
        cnt[k]=2;
    }
    else if(l==r){
        sum[k]=cnt[k]=0;left[k]=right[k]=0;
    }
    else {
        sum[k]=sum[k*2]+sum[k*2+1];
        cnt[k]=cnt[k*2]+cnt[k*2+1];
        left[k]=left[k*2];right[k]=right[k*2+1];
        if(left[k*2+1] && right[k*2])
            cnt[k]-=2;
    }
}

void Insert(int a,int b,int k,int l,int r){
    if(a<=l && r<=b){
        cover[k]++;
        pushUp(k,l,r);
        return ;
    }
    int m=(l+r)/2;
    if(a<=m)
        Insert(a,b,k*2,l,m);
    if(b>m)
        Insert(a,b,k*2+1,m+1,r);
    pushUp(k,l,r);
}

void Delete(int a,int b,int k,int l,int r){
    if(a<=l && r<=b){
        cover[k]--;
        pushUp(k,l,r);
            return ;
    }
    int m=(l+r)/2;
    if(a<=m)
        Delete(a,b,k*2,l,m);
    if(b>m)
        Delete(a,b,k*2+1,m+1,r);
    pushUp(k,l,r);
}

int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF){
        if(n==0){
            printf("0\n");continue;
        }
        int tot=0;
        int x1,x2,y1,y2,r=-10000-10;
        for(i=0;i<n;i++){
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            lines[tot].x=x1;
            lines[tot].y1=y1+10001;     //一定是10001,10000则错
            lines[tot].y2=y2+10001;
            lines[tot++].left=true;
            lines[tot].x=x2;
            lines[tot].y1=y1+10001;
            lines[tot].y2=y2+10001;
            r=max(r,y2+10001);
            lines[tot++].left=false;
        }
        sort(lines,lines+tot,cmp);
        build(1,1,r);
        int res=0,temp=0;
        for(i=0;i<tot;i++){
            if(lines[i].left)
                Insert(lines[i].y1,lines[i].y2-1,1,1,r);
            else
                Delete(lines[i].y1,lines[i].y2-1,1,1,r);
            if(i!=tot-1)
                res+=cnt[1]*(lines[i+1].x-lines[i].x);
            res+=fabs(sum[1]-temp);
            temp=sum[1];
        }
        printf("%d\n",res);
    }
    return 0;
}

