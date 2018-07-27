/****************
*PID:zoj1610
*Auth:Jonariguez
*****************
线段树+懒惰标记记录颜色，然后全部更新到底
最后暴力统计每一种颜色的线段个数。
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn=8000+10;

int sum[maxn*4],set[maxn*4],col[maxn*4],n;

void build(int k,int l,int r){
    set[k]=-1;sum[k]=-1;
    if(l==r) return ;
    int m=(l+r)/2;
    build(k*2,l,m);
    build(k*2+1,m+1,r);
}

void pushDown(int k){
    if(set[k]>=0){
        set[k*2]=set[k*2+1]=set[k];
       // sum[k]=set[k];
        sum[k*2]=sum[k*2+1]=set[k];
        set[k]=-1;
    }
}

void update(int a,int b,int v,int k,int l,int r){
    if(a<=l && r<=b){
        set[k]=v;sum[k]=v;return ;
    }
    pushDown(k);
    int m=(l+r)/2;
    if(a<=m)
        update(a,b,v,k*2,l,m);
    if(b>m)
        update(a,b,v,k*2+1,m+1,r);
}

void ask(int a,int b,int k,int l,int r){
    if(l==r){
        col[l]=sum[k];return ;
    }
    int m=(l+r)/2;
    pushDown(k);
    if(a<=m)
        ask(a,b,k*2,l,m);
    if(b>m)
        ask(a,b,k*2+1,m+1,r);
}

int main()
{
    int i;
    while(scanf("%d",&n)!=EOF){
        int m=8000;
        build(1,1,m);
        int a,b,x,r=0;
        for(i=1;i<=n;i++){
            scanf("%d%d%d",&a,&b,&x);
            a++;
            update(a,b,x,1,1,m);
        }
        memset(col,-1,sizeof(col));
        ask(1,m,1,1,m);
        for(i=0;i<=8000;i++){
            int c=0;
            for(int j=1;j<=m;){
                while(j<=m && col[j]!=i) j++;
                if(j>m) break;
                while(j<=m && col[j]==i) j++;
                c++;
            }
            if(c)
                printf("%d %d\n",i,c);
        }
        printf("\n");
    }
    return 0;
}
