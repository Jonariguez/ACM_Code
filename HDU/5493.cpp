/****************
*PID:hdu5493
*Auth:Jonariguez
*****************
一道水线段树题，网络赛的时候竟然没敢写。。。。。
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=100000+10;
bool vis[maxn];
int res[maxn];

struct pp{
    int k,h;
}s[maxn];

int cmp(const pp &a,const pp &b){
    return a.h<b.h;
}

typedef struct Segment{
    int sum[maxn*4];
    void pushUp(int k){
        sum[k]=sum[k*2]+sum[k*2+1];
    }
    void build(int k,int l,int r){
        if(l==r){
            sum[k]=1;return ;
        }
        int m=(l+r)/2;
        build(k*2,l,m);
        build(k*2+1,m+1,r);
        pushUp(k);
    }
    int askL(int v,int k,int l,int r){
        if(l==r) return l;
        int m=(l+r)/2;
        if(v<=sum[k*2])
            return askL(v,k*2,l,m);
        return askL(v-sum[k*2],k*2+1,m+1,r);
    }
    int askR(int v,int k,int l,int r){
        if(l==r) return l;
        int m=(l+r)/2;
        if(v<=sum[k*2+1])
            return askR(v,k*2+1,m+1,r);
        return askR(v-sum[k*2+1],k*2,l,m);
    }
    void update(int p,int k,int l,int r){
        if(l==r){
            sum[k]=0;return ;
        }
        int m=(l+r)/2;
        if(p<=m)
            update(p,k*2,l,m);
        else update(p,k*2+1,m+1,r);
        pushUp(k);
    }
}Tree;

Tree tree;

int main()
{
    int i,j,n,kcase=1,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        fill(vis,vis+n+1,0);
        for(i=0;i<n;i++)
            scanf("%d%d",&s[i].h,&s[i].k);
        sort(s,s+n,cmp);
        tree.build(1,1,n);
        int flag=1;
        for(i=0;i<n;i++){
            int v=s[i].k+1;
            if(tree.sum[1]<v){
                flag=0;break;
            }
            int l=tree.askL(v,1,1,n),r=tree.askR(v,1,1,n);
            l=min(l,r);
            res[l]=s[i].h;
            tree.update(l,1,1,n);
        }
        printf("Case #%d: ",kcase++);
        if(flag==0)
            printf("impossible\n");
        else
            for(i=1;i<=n;i++)
                printf("%d%c",res[i],i==n?'\n':' ');
    }
    return 0;
}
